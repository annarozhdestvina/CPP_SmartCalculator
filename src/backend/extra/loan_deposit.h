#ifndef LOAN_DEPOSIT_H_
#define LOAN_DEPOSIT_H_

#include <math.h>
#include <stdbool.h>

typedef struct {
  long double loan_sum;
  int num_of_periods;
  bool month_year;
  long double percent;
  bool type_of_payment;
  long double payment_min;
  long double payment_max;
  long double overpayment;
  long double total_loan_repayment;
} loan_t;

typedef struct {
  long double deposit_sum;
  long double percent;
  int period_type;
  int period_value;
  int payment_frequency;
  bool interest_capitalization;
  int replenishment_type;
  long double replenishment_value;
  int withdrawal_type;
  long double withdrawal_value;
  long double accrued_interest;
  long double effective_percent;
  long double taxes;
  long double total_sum;
} deposit_t;

typedef struct {
  int day;
  int month;
  int year;
  int count_days;
} date_t;

typedef struct {
  long double cb_key_rate;
  long double tax_rate;
  long double tax_free_income;
} tax_t;

// loan
void init_loan(loan_t *loan_db, long double sum, int num_of_periods,
               bool type_of_period, long double percent, bool type_of_payment);
void calculate_loan(loan_t *loan_db);

// deposit
void init_deposit(deposit_t *deposit_db, long double sum, long double percent,
                  int period_type, int period_value, int payment_frequency,
                  bool interest_capitalization, int replenishment_type,
                  long double replenishment_value, int withdrawal_type,
                  long double withdrawal_value);
void init_deposit_date(date_t *date, int day, int month, int year,
                       deposit_t *deposit_db);
void init_tax_options(tax_t *tax, long double cb_key_rate, long double tax_rate,
                      long double tax_free_income);
void deposit_period_in_days(deposit_t *deposit_db, date_t *date);
int count_period_in_days(date_t *date, int year, int month, int day);
void calculate_deposit(deposit_t *deposit_db, date_t *date, tax_t *tax);

void daily_interest_accrual(deposit_t *deposit_db, date_t *date, tax_t *tax,
                            int period);
void monthly_interest_accrual(deposit_t *deposit_db, date_t *date, tax_t *tax,
                              int period);
void end_interest_accrual(deposit_t *deposit_db, date_t *date, tax_t *tax);

long double count_interest_by_year(deposit_t *deposit_db,
                                   long double deposit_interest,
                                   long double interest_by_year);
void count_taxes(deposit_t *deposit_db, long double interest_by_year,
                 tax_t *tax);
void count_deposit_total_sum(deposit_t *deposit_db);

bool check_leap_year(int year);
int count_days_in_month(int month, int year);
void next_date(date_t *date);
void next_checkpoint_date(date_t *next_date, int type, int day_in_period);
void change_deposit_sum(deposit_t *deposit_db, date_t *date,
                        date_t *change_date, int type, long double value,
                        long double *deposit_sum, int day_in_period);

#endif  // LOAN_DEPOSIT_H_
