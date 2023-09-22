#include "loan_deposit.h"

void init_deposit(deposit_t *deposit_db, long double sum, long double percent,
                  int period_type, int period_value, int payment_frequency,
                  bool interest_capitalization, int replenishment_type,
                  long double replenishment_value, int withdrawal_type,
                  long double withdrawal_value) {
  deposit_db->deposit_sum = sum;
  deposit_db->percent = percent;
  deposit_db->period_type = period_type;
  deposit_db->period_value = period_value;
  deposit_db->payment_frequency = payment_frequency;
  deposit_db->interest_capitalization = interest_capitalization;
  deposit_db->replenishment_type = replenishment_type;
  deposit_db->replenishment_value = replenishment_value;
  deposit_db->withdrawal_type = withdrawal_type;
  deposit_db->withdrawal_value = -withdrawal_value;
  deposit_db->taxes = 0.0;
  deposit_db->accrued_interest = 0.0;
}

void init_deposit_date(date_t *date, int day, int month, int year,
                       deposit_t *deposit_db) {
  date->day = day;
  date->month = month;
  date->year = year;
  deposit_period_in_days(deposit_db, date);
}

void init_tax_options(tax_t *tax, long double cb_key_rate, long double tax_rate,
                      long double tax_free_income) {
  tax->cb_key_rate = cb_key_rate;
  tax->tax_rate = tax_rate;
  tax->tax_free_income = tax_free_income;
}

void deposit_period_in_days(deposit_t *deposit_db, date_t *date) {
  if (deposit_db->period_type == 0) {  // period value in days
    date->count_days = deposit_db->period_value;
  } else if (deposit_db->period_type == 1) {  // period value in months
    int last_year =
        date->year + (date->month + deposit_db->period_value - 1) / 12;

    int last_month = (date->month + deposit_db->period_value) % 12;
    if (!last_month) last_month = date->month;

    int last_day = date->day;
    if (count_days_in_month(date->month, date->year) == date->day ||
        (date->day > count_days_in_month(last_month, last_year) &&
         last_month == 2)) {
      last_day = count_days_in_month(last_month, last_year);
    }

    date->count_days =
        count_period_in_days(date, last_year, last_month, last_day);
  } else if (deposit_db->period_type == 2) {  // period value in years
    int last_year = date->year + deposit_db->period_value;
    int last_month = date->month;
    int last_day = date->day;
    date->count_days =
        count_period_in_days(date, last_year, last_month, last_day);
  }
}

int count_period_in_days(date_t *date, int year, int month, int day) {
  int counter = 0;
  int y_cnt = date->year;
  for (; y_cnt <= year; y_cnt++) {
    bool y_first = y_cnt == date->year;
    int m_cnt = y_first ? date->month : 1;
    for (; m_cnt <= 12; m_cnt++) {
      if (y_cnt == year && m_cnt > month) break;
      bool m_first = m_cnt == date->month;
      int d_cnt = m_first && y_first ? date->day + 1 : 1;
      for (; d_cnt <= count_days_in_month(m_cnt, y_cnt); d_cnt++) {
        if (y_cnt == year && m_cnt == month && d_cnt > day) break;
        counter++;
      }
    }
  }
  return counter;
}

void calculate_deposit(deposit_t *deposit_db, date_t *date, tax_t *tax) {
  switch (deposit_db->payment_frequency) {
    case 0:  // daily
      daily_interest_accrual(deposit_db, date, tax, 1);
      break;
    case 1:  // weekly
      daily_interest_accrual(deposit_db, date, tax, 7);
      break;
    case 2:  // monthly
      monthly_interest_accrual(deposit_db, date, tax, 1);
      break;
    case 3:  // quarterly
      monthly_interest_accrual(deposit_db, date, tax, 3);
      break;
    case 4:  // semi-annual
      monthly_interest_accrual(deposit_db, date, tax, 6);
      break;
    case 5:  // annual
      monthly_interest_accrual(deposit_db, date, tax, 12);
      break;
    case 6:  // at the end
      end_interest_accrual(deposit_db, date, tax);
      break;
  }
}

void daily_interest_accrual(deposit_t *deposit_db, date_t *date, tax_t *tax,
                            int period) {
  long double sub_interest = 0.0;  // for the effective interest's calculation
  long double deposit_sum = deposit_db->deposit_sum;  // for the capitalization
  long double percent = 0.0;                          // percentage per day
  long double deposit_interest = 0.0;  // accrual of interest per day
  long double interest_by_year = 0.0;  // interest per calendar year

  int day_in_period = date->day;
  long double *p_deposit_sum = &deposit_sum;

  // set next date for deposit replenishment
  date_t next_replenishment_date = *date;
  if (deposit_db->replenishment_type) {
    next_checkpoint_date(&next_replenishment_date,
                         deposit_db->replenishment_type, day_in_period);
  }
  // set next date for deposit withdrawal
  date_t next_withdrawal_date = *date;
  if (deposit_db->withdrawal_type) {
    next_checkpoint_date(&next_withdrawal_date, deposit_db->withdrawal_type,
                         day_in_period);
  }

  for (int num_of_day = 1; num_of_day <= date->count_days; num_of_day++) {
    int previous_date_year = date->year;
    next_date(date);
    int next_date_year = date->year;

    // tax calculation in the end of the calendar year
    if (previous_date_year != next_date_year) {
      count_taxes(deposit_db, interest_by_year, tax);
      interest_by_year = 0.0;
    }

    percent = deposit_db->percent / (365 + check_leap_year(date->year));
    deposit_interest += deposit_sum * percent;
    sub_interest += roundl(deposit_db->deposit_sum * percent) / 100;

    // interest calculation in the reporting period
    if (num_of_day % period == 0) {
      interest_by_year = count_interest_by_year(deposit_db, deposit_interest,
                                                interest_by_year);
      if (deposit_db->interest_capitalization)
        deposit_sum += deposit_interest / 100;
      deposit_interest = 0.0;
    }
    // increase deposit sum by replenishment in checkpoint date
    change_deposit_sum(deposit_db, date, &next_replenishment_date,
                       deposit_db->replenishment_type,
                       deposit_db->replenishment_value, p_deposit_sum,
                       day_in_period);

    // decrease deposit sum by withdrawal in checkpoint date
    change_deposit_sum(
        deposit_db, date, &next_withdrawal_date, deposit_db->withdrawal_type,
        deposit_db->withdrawal_value, p_deposit_sum, day_in_period);
  }
  // interest calculation in the end
  interest_by_year =
      count_interest_by_year(deposit_db, deposit_interest, interest_by_year);

  // tax calculation at the end of the deposit term (last year)
  count_taxes(deposit_db, interest_by_year, tax);

  count_deposit_total_sum(deposit_db);

  deposit_db->effective_percent =
      deposit_db->percent * deposit_db->accrued_interest / sub_interest;
}

void monthly_interest_accrual(deposit_t *deposit_db, date_t *date, tax_t *tax,
                              int period) {
  long double sub_interest = 0.0;  // for the effective interest's calculation
  long double deposit_sum = deposit_db->deposit_sum;  // for the capitalization
  long double percent = 0.0;                          // percentage per day
  long double deposit_interest = 0.0;  // accrual of interest per day
  long double interest_by_year = 0.0;  // interest per calendar year

  int check_day = date->day;
  int check_month = date->month;
  int check = 1;

  int day_in_period = date->day;
  long double *p_deposit_sum = &deposit_sum;

  // set next date for deposit replenishment
  date_t next_replenishment_date = *date;
  if (deposit_db->replenishment_type) {
    next_checkpoint_date(&next_replenishment_date,
                         deposit_db->replenishment_type, day_in_period);
  }
  // set next date for deposit withdrawal
  date_t next_withdrawal_date = *date;
  if (deposit_db->withdrawal_type) {
    next_checkpoint_date(&next_withdrawal_date, deposit_db->withdrawal_type,
                         day_in_period);
  }

  for (int num_of_day = 1; num_of_day <= date->count_days; num_of_day++) {
    int previous_date_year = date->year;
    next_date(date);
    int next_date_year = date->year;

    // tax calculation in the end of the calendar year
    if (previous_date_year != next_date_year) {
      count_taxes(deposit_db, interest_by_year, tax);
      interest_by_year = 0.0;
    }

    percent = deposit_db->percent / (365 + check_leap_year(date->year));
    deposit_interest += deposit_sum * percent;
    sub_interest += roundl(deposit_db->deposit_sum * percent) / 100;

    // checking the end of the current month
    if (check_month != date->month &&
        check_day > count_days_in_month(date->month, date->year)) {
      if (date->day == count_days_in_month(date->month, date->year)) {
        check++;
        check_month = date->month;
      }
    } else if (check_month != date->month && check_day == date->day) {
      check++;
      check_month = date->month;
    }
    // interest calculation in the reporting period
    if (check % (period + 1) == 0) {
      interest_by_year = count_interest_by_year(deposit_db, deposit_interest,
                                                interest_by_year);
      if (deposit_db->interest_capitalization) {
        deposit_sum += deposit_interest / 100;
      }
      deposit_interest = 0.0;
      check = 1;
    }
    // increase deposit sum by replenishment in checkpoint date
    change_deposit_sum(deposit_db, date, &next_replenishment_date,
                       deposit_db->replenishment_type,
                       deposit_db->replenishment_value, p_deposit_sum,
                       day_in_period);

    // decrease deposit sum by withdrawal in checkpoint date
    change_deposit_sum(
        deposit_db, date, &next_withdrawal_date, deposit_db->withdrawal_type,
        deposit_db->withdrawal_value, p_deposit_sum, day_in_period);
  }
  // interest calculation in the end
  interest_by_year =
      count_interest_by_year(deposit_db, deposit_interest, interest_by_year);

  // tax calculation at the end of the deposit term (last year)
  count_taxes(deposit_db, interest_by_year, tax);

  count_deposit_total_sum(deposit_db);

  deposit_db->effective_percent =
      deposit_db->percent * deposit_db->accrued_interest / sub_interest;
}

void end_interest_accrual(deposit_t *deposit_db, date_t *date, tax_t *tax) {
  long double deposit_sum = deposit_db->deposit_sum;  // for the capitalization
  long double percent = 0.0;                          // percentage per day
  long double deposit_interest = 0.0;  // accrual of interest per day

  int day_in_period = date->day;
  long double *p_deposit_sum = &deposit_sum;

  // set next date for deposit replenishment
  date_t next_replenishment_date = *date;
  if (deposit_db->replenishment_type) {
    next_checkpoint_date(&next_replenishment_date,
                         deposit_db->replenishment_type, date->day);
  }
  //  set next date for deposit withdrawal
  date_t next_withdrawal_date = *date;
  if (deposit_db->withdrawal_type) {
    next_checkpoint_date(&next_withdrawal_date, deposit_db->withdrawal_type,
                         day_in_period);
  }

  for (int num_of_day = 1; num_of_day <= date->count_days; num_of_day++) {
    next_date(date);
    percent = deposit_db->percent / (365 + check_leap_year(date->year));
    deposit_interest += deposit_sum * percent;

    // increase deposit sum by replenishment in checkpoint date
    change_deposit_sum(deposit_db, date, &next_replenishment_date,
                       deposit_db->replenishment_type,
                       deposit_db->replenishment_value, p_deposit_sum,
                       day_in_period);

    // decrease deposit sum by withdrawal in checkpoint date
    change_deposit_sum(
        deposit_db, date, &next_withdrawal_date, deposit_db->withdrawal_type,
        deposit_db->withdrawal_value, p_deposit_sum, day_in_period);
  }
  // interest calculation in the end
  deposit_db->accrued_interest += roundl(deposit_interest) / 100;

  // tax calculation at the end of the deposit term (last year)
  count_taxes(deposit_db, deposit_db->accrued_interest, tax);

  count_deposit_total_sum(deposit_db);

  deposit_db->effective_percent = deposit_db->percent;
}

long double count_interest_by_year(deposit_t *deposit_db,
                                   long double deposit_interest,
                                   long double interest_by_year) {
  long double temp = deposit_db->accrued_interest;
  deposit_db->accrued_interest += roundl(deposit_interest) / 100;
  interest_by_year += deposit_db->accrued_interest - temp;
  return interest_by_year;
}

void count_taxes(deposit_t *deposit_db, long double interest_by_year,
                 tax_t *tax) {
  long double tax_base = 0;
  long double tax_free_interest = tax->cb_key_rate * tax->tax_free_income / 100;
  if (interest_by_year - tax_free_interest > 0) {
    tax_base = interest_by_year - tax_free_interest;
  }
  deposit_db->taxes += roundl(tax_base) * tax->tax_rate / 100;
}

void count_deposit_total_sum(deposit_t *deposit_db) {
  deposit_db->total_sum = deposit_db->deposit_sum;
  if (deposit_db->interest_capitalization) {
    deposit_db->total_sum += deposit_db->accrued_interest;
  }
}

void next_date(date_t *date) {
  int count_days = count_days_in_month(date->month, date->year);
  if (date->day > count_days - 1) {
    if (date->month == 12) {
      date->day = 1;
      date->month = 1;
      date->year += 1;
    } else {
      date->day = 1;
      date->month += 1;
    }
  } else {
    date->day += 1;
  }
}

void next_checkpoint_date(date_t *next_date, int type, int day_in_period) {
  int add_month = 0;
  switch (type) {
    case 1:  // monthly
      add_month = 1;
      break;
    case 2:  // quarterly
      add_month = 3;
      break;
    case 3:  // semi-annual
      add_month = 6;
      break;
    case 4:  // annual
      add_month = 12;
      break;
  }

  int next_year = next_date->year + (next_date->month + add_month - 1) / 12;

  int next_month = (next_date->month + add_month) % 12;
  if (!next_month) next_month = next_date->month + 1;

  int next_day = day_in_period;
  if (day_in_period > count_days_in_month(next_month, next_year)) {
    next_day = count_days_in_month(next_month, next_year);
  }

  next_date->year = next_year;
  next_date->month = next_month;
  next_date->day = next_day;
}

void change_deposit_sum(deposit_t *deposit_db, date_t *date,
                        date_t *change_date, int type, long double value,
                        long double *deposit_sum, int day_in_period) {
  if (type) {
    bool day_eq = date->day == change_date->day;
    bool month_eq = date->month == change_date->month;
    bool year_eq = date->year == change_date->year;

    if (day_eq && month_eq && year_eq) {
      deposit_db->deposit_sum += value;
      if (deposit_db->deposit_sum < 0) deposit_db->deposit_sum = 0;

      *deposit_sum += value;
      if (*deposit_sum < 0) *deposit_sum = 0;

      next_checkpoint_date(change_date, type, day_in_period);
    }
  }
}

int count_days_in_month(int month, int year) {
  int result = 28 + ((0x3bbeecc >> (month * 2)) & 3);
  if (check_leap_year(year) && month == 2) result++;
  return result;
}

bool check_leap_year(int year) {
  return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
