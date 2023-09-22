#include "loan_deposit.h"

/*
    init_loan

    - ЧТО ДЕЛАЕТ: заполнение инициализированной структуры loan_db входными
   параметрами, введенными в консоль

    - ПАРАМЕТРЫ:
        1. структура loan_db
        2. сумма кредита
        3. количество периодов кредита
        4. тип периода (0 - месяц / 1 - год)
        5. процентная ставка по кредиту
        6. порядок погашения (0 - аннуитетный / 1- дифференцированный)

    - ПОРЯДОК РАБОТЫ:
        1. В структуру loan_db записываются значения входных параметров.

    - РЕЗУЛЬТАТ: -
*/
void init_loan(loan_t *loan_db, long double sum, int num_of_periods,
               bool type_of_period, long double percent, bool type_of_payment) {
  loan_db->loan_sum = sum;
  loan_db->num_of_periods = num_of_periods;
  loan_db->month_year = type_of_period;
  loan_db->percent = percent;
  loan_db->type_of_payment = type_of_payment;
}

/*
    calculate_loan

    - ЧТО ДЕЛАЕТ: расчет суммарных погашений по кредиту, эффективной процентной
   ставки, переплаты по кредиту

    - ПАРАМЕТРЫ:
        1. структура loan_db

    - ПОРЯДОК РАБОТЫ:
        1. Инициализируется (long double) переменная percent, в которую
   записывается значение структуры loan_db --> элемент percent, переведенное в
   десятичную дробь (/100) в месячном выражении (/12)
        2. Инициализируется (int) переменная month, в которую записывается
   значение структуры loan_db --> элемент num_of_periods. Данная переменная
   переводится в месяцы (*12), если значение структуры loan_db --> элемент
   num_of_periods равняется 1
        3. Если значение структуры loan_db --> элемент type_of_payment = 1:
            3.1 Инициализируется (long double) переменная overpayment, в которую
   будет записана сумма планируемых к уплате процентов по кредиту (переплата по
   кредиту)
            3.2 Инициализируется (long double) переменная loan_sum, в
   которую значение структуры loan_db --> элемент type_of_payment
            3.3 Инициализируется (long double) переменная month_payment, в
   которую сумма платежа по телу кредита за период (сумма кредита / кол-во
   месяцев погашения)
            3.4 В цикле рассчитывается значение overpayment - при каждой
   итерации процентная ставка по кредиту умножается на остаток суммы долга по
   телу кредита, который в свою очередь сокращается на значение month_payment
   (сумма платежа по телу кредита за период)
            3.5 Присваивание значений элементам структуры loan_db:
                - overpayment - значение переменной overpayment
                - total_loan_repayment - сумма значений переменной overpayment и
   структуре loan_db --> элемент loan_sum
                - payment_min -

    - РЕЗУЛЬТАТ: -
*/
void calculate_loan(loan_t *loan_db) {
  long double loan_sum = loan_db->loan_sum;
  long double percent = loan_db->percent / 1200;
  int month = loan_db->num_of_periods;
  if (loan_db->month_year) month *= 12;
  if (loan_db->type_of_payment) {
    long double overpayment = 0.0;
    long double month_payment = loan_sum / month;
    for (int i = 0; i < month; i++) {
      overpayment += loan_sum * percent;
      loan_sum -= month_payment;
      if (i == 0) loan_db->payment_max = month_payment + overpayment;
      if (i == month - 1) loan_db->payment_min = month_payment * (1 + percent);
    }
    loan_db->overpayment = overpayment;
    loan_db->total_loan_repayment = overpayment + loan_db->loan_sum;
  } else {
    long double count_percent = powl(1 + percent, month);
    loan_db->payment_min =
        loan_sum * percent * count_percent / (count_percent - 1);
    loan_db->total_loan_repayment =
        roundl(loan_db->payment_min * 100) / 100 * month;
    loan_db->overpayment = loan_db->total_loan_repayment - loan_sum;
  }
}
