// #include "main_test.h"

// START_TEST(loan_test_01) {
//   loan_t loan_db;

//   long double loan_sum = 1000000;
//   int num_of_periods = 60;
//   bool type_of_period = 0;
//   long double percent = 12;
//   bool type_of_payment = 0;

//   init_loan(&loan_db, loan_sum, num_of_periods, type_of_period, percent,
//             type_of_payment);
//   calculate_loan(&loan_db);

//   long double payment_min = 22244.45;
//   long double overpayment = 334667;
//   long double total_loan_repayment = 1334667;

//   ck_assert_ldouble_eq_tol(loan_db.payment_min, payment_min, 0.1);
//   ck_assert_ldouble_eq_tol(loan_db.overpayment, overpayment, 0.1);
//   ck_assert_ldouble_eq_tol(loan_db.total_loan_repayment, total_loan_repayment,
//                            0.1);
// }
// END_TEST

// START_TEST(loan_test_02) {
//   loan_t loan_db;

//   long double loan_sum = 1000000;
//   int num_of_periods = 5;
//   bool type_of_period = 1;
//   long double percent = 12;
//   bool type_of_payment = 0;

//   init_loan(&loan_db, loan_sum, num_of_periods, type_of_period, percent,
//             type_of_payment);
//   calculate_loan(&loan_db);

//   long double payment_min = 22244.45;
//   long double overpayment = 334667;
//   long double total_loan_repayment = 1334667;

//   ck_assert_ldouble_eq_tol(loan_db.payment_min, payment_min, 0.1);
//   ck_assert_ldouble_eq_tol(loan_db.overpayment, overpayment, 0.1);
//   ck_assert_ldouble_eq_tol(loan_db.total_loan_repayment, total_loan_repayment,
//                            0.1);
// }
// END_TEST

// START_TEST(loan_test_03) {
//   loan_t loan_db;

//   long double loan_sum = 1000000;
//   int num_of_periods = 60;
//   bool type_of_period = 0;
//   long double percent = 12;
//   bool type_of_payment = 1;

//   init_loan(&loan_db, loan_sum, num_of_periods, type_of_period, percent,
//             type_of_payment);
//   calculate_loan(&loan_db);

//   long double payment_min = 16833.33;
//   long double payment_max = 26666.67;
//   long double overpayment = 305000;
//   long double total_loan_repayment = 1305000;

//   ck_assert_ldouble_eq_tol(loan_db.payment_min, payment_min, 0.1);
//   ck_assert_ldouble_eq_tol(loan_db.payment_max, payment_max, 0.1);
//   ck_assert_ldouble_eq_tol(loan_db.overpayment, overpayment, 0.1);
//   ck_assert_ldouble_eq_tol(loan_db.total_loan_repayment, total_loan_repayment,
//                            0.1);
// }
// END_TEST

// START_TEST(loan_test_04) {
//   loan_t loan_db;

//   long double loan_sum = 1000000;
//   int num_of_periods = 5;
//   bool type_of_period = 1;
//   long double percent = 12;
//   bool type_of_payment = 1;

//   init_loan(&loan_db, loan_sum, num_of_periods, type_of_period, percent,
//             type_of_payment);
//   calculate_loan(&loan_db);

//   long double payment_min = 16833.33;
//   long double payment_max = 26666.67;
//   long double overpayment = 305000;
//   long double total_loan_repayment = 1305000;

//   ck_assert_ldouble_eq_tol(loan_db.payment_min, payment_min, 0.1);
//   ck_assert_ldouble_eq_tol(loan_db.payment_max, payment_max, 0.1);
//   ck_assert_ldouble_eq_tol(loan_db.overpayment, overpayment, 0.1);
//   ck_assert_ldouble_eq_tol(loan_db.total_loan_repayment, total_loan_repayment,
//                            0.1);
// }
// END_TEST

// Suite *suite_loan() {
//   Suite *s = suite_create("suite_loan");
//   TCase *tc = tcase_create("loan");

//   tcase_add_test(tc, loan_test_01);
//   tcase_add_test(tc, loan_test_02);
//   tcase_add_test(tc, loan_test_03);
//   tcase_add_test(tc, loan_test_04);

//   suite_add_tcase(s, tc);
//   return s;
// }
