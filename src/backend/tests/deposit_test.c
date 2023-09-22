// #include "main_test.h"

// START_TEST(deposit_test_in_days_01) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 987654321;
//   long double percent = 9;
//   int period_type = 0;
//   int period_value = 321;
//   int payment_frequency = 0;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 20;
//   int month = 4;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 78129600.12;
//   long double taxes = 10137348.02;
//   long double effective_percent = 9.0;
//   long double total_sum = 987654321.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_days_02) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 987654321;
//   long double percent = 9;
//   int period_type = 0;
//   int period_value = 321;
//   int payment_frequency = 0;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 20;
//   int month = 4;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 81292575.38;
//   long double taxes = 10548534.80;
//   long double effective_percent = 9.36;
//   long double total_sum = 1068946896.38;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_days_03) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 987654321;
//   long double percent = 9;
//   int period_type = 0;
//   int period_value = 321;
//   int payment_frequency = 1;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 20;
//   int month = 4;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 78129600.65;
//   long double taxes = 10137348.08;
//   long double effective_percent = 9.0;
//   long double total_sum = 987654321.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_days_04) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 987654321;
//   long double percent = 9;
//   int period_type = 0;
//   int period_value = 321;
//   int payment_frequency = 1;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 20;
//   int month = 4;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 81230336.25;
//   long double taxes = 10540443.71;
//   long double effective_percent = 9.35;
//   long double total_sum = 1068884657.25;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_days_05) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 987654321;
//   long double percent = 9;
//   int period_type = 0;
//   int period_value = 321;
//   int payment_frequency = 2;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 20;
//   int month = 4;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 78129600.53;
//   long double taxes = 10137348.07;
//   long double effective_percent = 9.0;
//   long double total_sum = 987654321.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_days_06) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 987654321;
//   long double percent = 9;
//   int period_type = 0;
//   int period_value = 321;
//   int payment_frequency = 2;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 20;
//   int month = 4;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 80993228.15;
//   long double taxes = 10509619.66;
//   long double effective_percent = 9.32;
//   long double total_sum = 1068647549.15;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_days_07) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 987654321;
//   long double percent = 9;
//   int period_type = 0;
//   int period_value = 321;
//   int payment_frequency = 3;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 20;
//   int month = 4;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 78129600.52;
//   long double taxes = 10137348.07;
//   long double effective_percent = 9.0;
//   long double total_sum = 987654321.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_days_08) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 987654321;
//   long double percent = 9;
//   int period_type = 0;
//   int period_value = 321;
//   int payment_frequency = 3;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 20;
//   int month = 4;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 80428743.13;
//   long double taxes = 10436236.61;
//   long double effective_percent = 9.26;
//   long double total_sum = 1068083064.13;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_days_09) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 987654321;
//   long double percent = 9;
//   int period_type = 0;
//   int period_value = 321;
//   int payment_frequency = 4;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 20;
//   int month = 4;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 78129600.52;
//   long double taxes = 10137348.07;
//   long double effective_percent = 9.0;
//   long double total_sum = 987654321.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_days_10) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 987654321;
//   long double percent = 9;
//   int period_type = 0;
//   int period_value = 321;
//   int payment_frequency = 4;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 20;
//   int month = 4;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 79644091.05;
//   long double taxes = 10334231.84;
//   long double effective_percent = 9.17;
//   long double total_sum = 1067298412.05;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_days_11) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 987654321;
//   long double percent = 9;
//   int period_type = 0;
//   int period_value = 321;
//   int payment_frequency = 5;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 20;
//   int month = 4;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 78129600.52;
//   long double taxes = 10147098.07;
//   long double effective_percent = 9.0;
//   long double total_sum = 987654321.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_days_12) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 987654321;
//   long double percent = 9;
//   int period_type = 0;
//   int period_value = 321;
//   int payment_frequency = 5;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 20;
//   int month = 4;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 78129600.52;
//   long double taxes = 10147098.07;
//   long double effective_percent = 8.99;
//   long double total_sum = 1065783921.52;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_days_13) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 987654321;
//   long double percent = 9;
//   int period_type = 0;
//   int period_value = 321;
//   int payment_frequency = 6;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 20;
//   int month = 4;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 78129600.52;
//   long double taxes = 10147098.07;
//   long double effective_percent = 9.0;
//   long double total_sum = 987654321.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_days_14) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 987654321;
//   long double percent = 9;
//   int period_type = 0;
//   int period_value = 321;
//   int payment_frequency = 6;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 20;
//   int month = 4;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 78129600.52;
//   long double taxes = 10147098.07;
//   long double effective_percent = 8.99;
//   long double total_sum = 1065783921.52;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_months_01) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1000000;
//   long double percent = 12;
//   int period_type = 1;
//   int period_value = 60;
//   int payment_frequency = 0;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 30;
//   int month = 11;
//   int year = 2022;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 600004.62;
//   long double taxes = 27925.66;
//   long double effective_percent = 12.0;
//   long double total_sum = 1000000;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_months_02) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1000000;
//   long double percent = 12;
//   int period_type = 1;
//   int period_value = 60;
//   int payment_frequency = 0;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 30;
//   int month = 11;
//   int year = 2022;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 821939.11;
//   long double taxes = 56770.60;
//   long double effective_percent = 16.43;
//   long double total_sum = 1821939.11;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_months_03) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1000000;
//   long double percent = 12;
//   int period_type = 1;
//   int period_value = 60;
//   int payment_frequency = 1;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 30;
//   int month = 11;
//   int year = 2022;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 599999.93;
//   long double taxes = 28053.28;
//   long double effective_percent = 12.0;
//   long double total_sum = 1000000;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_months_04) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1000000;
//   long double percent = 12;
//   int period_type = 1;
//   int period_value = 60;
//   int payment_frequency = 1;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 30;
//   int month = 11;
//   int year = 2022;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 820864.52;
//   long double taxes = 56761.54;
//   long double effective_percent = 16.41;
//   long double total_sum = 1820864.52;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_months_05) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1000000;
//   long double percent = 12;
//   int period_type = 1;
//   int period_value = 60;
//   int payment_frequency = 2;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 30;
//   int month = 11;
//   int year = 2022;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 599999.92;
//   long double taxes = 27967.80;
//   long double effective_percent = 12.0;
//   long double total_sum = 1000000;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_months_06) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1000000;
//   long double percent = 12;
//   int period_type = 1;
//   int period_value = 60;
//   int payment_frequency = 2;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 30;
//   int month = 11;
//   int year = 2022;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 816694.52;
//   long double taxes = 56138.10;
//   long double effective_percent = 16.32;
//   long double total_sum = 1816694.52;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_months_07) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1000000;
//   long double percent = 12;
//   int period_type = 1;
//   int period_value = 60;
//   int payment_frequency = 3;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 30;
//   int month = 11;
//   int year = 2022;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 600000.03;
//   long double taxes = 29250.00;
//   long double effective_percent = 12.0;
//   long double total_sum = 1000000;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_months_08) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1000000;
//   long double percent = 12;
//   int period_type = 1;
//   int period_value = 60;
//   int payment_frequency = 3;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 30;
//   int month = 11;
//   int year = 2022;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 806110.11;
//   long double taxes = 56044.31;
//   long double effective_percent = 16.11;
//   long double total_sum = 1806110.11;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_months_09) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1000000;
//   long double percent = 12;
//   int period_type = 1;
//   int period_value = 60;
//   int payment_frequency = 4;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 30;
//   int month = 11;
//   int year = 2022;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 600000;
//   long double taxes = 29250.00;
//   long double effective_percent = 12.0;
//   long double total_sum = 1000000;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_months_10) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1000000;
//   long double percent = 12;
//   int period_type = 1;
//   int period_value = 60;
//   int payment_frequency = 4;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 30;
//   int month = 11;
//   int year = 2022;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 790845.97;
//   long double taxes = 54059.98;
//   long double effective_percent = 15.81;
//   long double total_sum = 1790845.97;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_months_11) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1000000;
//   long double percent = 12;
//   int period_type = 1;
//   int period_value = 60;
//   int payment_frequency = 5;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 30;
//   int month = 11;
//   int year = 2022;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 600000;
//   long double taxes = 29250.00;
//   long double effective_percent = 12.0;
//   long double total_sum = 1000000;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_months_12) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1000000;
//   long double percent = 12;
//   int period_type = 1;
//   int period_value = 60;
//   int payment_frequency = 5;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 30;
//   int month = 11;
//   int year = 2022;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 762341.68;
//   long double taxes = 50354.42;
//   long double effective_percent = 15.24;
//   long double total_sum = 1762341.68;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_months_13) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1000000;
//   long double percent = 12;
//   int period_type = 1;
//   int period_value = 60;
//   int payment_frequency = 6;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 30;
//   int month = 11;
//   int year = 2022;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 600000;
//   long double taxes = 68250.00;
//   long double effective_percent = 12.0;
//   long double total_sum = 1000000;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_months_14) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1000000;
//   long double percent = 12;
//   int period_type = 1;
//   int period_value = 60;
//   int payment_frequency = 6;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 30;
//   int month = 11;
//   int year = 2022;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 600000;
//   long double taxes = 68250.00;
//   long double effective_percent = 11.99;
//   long double total_sum = 1600000;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_months_15) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1000000;
//   long double percent = 12;
//   int period_type = 1;
//   int period_value = 12;
//   int payment_frequency = 6;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 30;
//   int month = 12;
//   int year = 2022;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 120000.00;
//   long double taxes = 5850.00;
//   long double effective_percent = 12.0;
//   long double total_sum = 1120000.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_months_16) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1000000;
//   long double percent = 12;
//   int period_type = 1;
//   int period_value = 26;
//   int payment_frequency = 3;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 30;
//   int month = 12;
//   int year = 2022;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 291758.16;
//   long double taxes = 15180.22;
//   long double effective_percent = 13.46;
//   long double total_sum = 1291758.16;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_years_01) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 123454321;
//   long double percent = 7;
//   int period_type = 2;
//   int period_value = 3;
//   int payment_frequency = 0;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 1;
//   int month = 7;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 25925405.78;
//   long double taxes = 3331302.75;
//   long double effective_percent = 7.00;
//   long double total_sum = 123454321.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_years_02) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 123454321;
//   long double percent = 7;
//   int period_type = 2;
//   int period_value = 3;
//   int payment_frequency = 0;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 1;
//   int month = 7;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 28845502.59;
//   long double taxes = 3710915.34;
//   long double effective_percent = 7.78;
//   long double total_sum = 152299823.59;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_years_03) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 123454321;
//   long double percent = 7;
//   int period_type = 2;
//   int period_value = 3;
//   int payment_frequency = 1;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 1;
//   int month = 7;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 25925407.85;
//   long double taxes = 3331303.02;
//   long double effective_percent = 7.00;
//   long double total_sum = 123454321.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_years_04) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 123454321;
//   long double percent = 7;
//   int period_type = 2;
//   int period_value = 3;
//   int payment_frequency = 1;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 1;
//   int month = 7;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 28827171.52;
//   long double taxes = 3708532.30;
//   long double effective_percent = 7.78;
//   long double total_sum = 152281492.52;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_years_05) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 123454321;
//   long double percent = 7;
//   int period_type = 2;
//   int period_value = 3;
//   int payment_frequency = 2;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 1;
//   int month = 7;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 25925407.43;
//   long double taxes = 3331302.97;
//   long double effective_percent = 7.00;
//   long double total_sum = 123454321.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_years_06) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 123454321;
//   long double percent = 7;
//   int period_type = 2;
//   int period_value = 3;
//   int payment_frequency = 2;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 1;
//   int month = 7;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 28755607.14;
//   long double taxes = 3699228.93;
//   long double effective_percent = 7.76;
//   long double total_sum = 152209928.14;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_years_07) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 123454321;
//   long double percent = 7;
//   int period_type = 2;
//   int period_value = 3;
//   int payment_frequency = 3;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 1;
//   int month = 7;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 25925407.42;
//   long double taxes = 3331302.96;
//   long double effective_percent = 7.00;
//   long double total_sum = 123454321.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_years_08) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 123454321;
//   long double percent = 7;
//   int period_type = 2;
//   int period_value = 3;
//   int payment_frequency = 3;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 1;
//   int month = 7;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 28572165.95;
//   long double taxes = 3675381.57;
//   long double effective_percent = 7.71;
//   long double total_sum = 152026486.95;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_years_09) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 123454321;
//   long double percent = 7;
//   int period_type = 2;
//   int period_value = 3;
//   int payment_frequency = 4;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 1;
//   int month = 7;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 25925407.41;
//   long double taxes = 3341052.96;
//   long double effective_percent = 7.00;
//   long double total_sum = 123454321.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_years_10) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 123454321;
//   long double percent = 7;
//   int period_type = 2;
//   int period_value = 3;
//   int payment_frequency = 4;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 1;
//   int month = 7;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 28302532.03;
//   long double taxes = 3650079.16;
//   long double effective_percent = 7.63;
//   long double total_sum = 151756853.03;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_years_11) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 123454321;
//   long double percent = 7;
//   int period_type = 2;
//   int period_value = 3;
//   int payment_frequency = 5;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 1;
//   int month = 7;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 25925407.41;
//   long double taxes = 3341052.96;
//   long double effective_percent = 7.00;
//   long double total_sum = 123454321.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_years_12) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 123454321;
//   long double percent = 7;
//   int period_type = 2;
//   int period_value = 3;
//   int payment_frequency = 5;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 1;
//   int month = 7;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 27782529.55;
//   long double taxes = 3582478.84;
//   long double effective_percent = 7.49;
//   long double total_sum = 151236850.55;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_years_13) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 123454321;
//   long double percent = 7;
//   int period_type = 2;
//   int period_value = 3;
//   int payment_frequency = 6;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 1;
//   int month = 7;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 25925407.41;
//   long double taxes = 3360552.96;
//   long double effective_percent = 7.00;
//   long double total_sum = 123454321.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_test_in_years_14) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 123454321;
//   long double percent = 7;
//   int period_type = 2;
//   int period_value = 3;
//   int payment_frequency = 6;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 1;
//   int month = 7;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 25925407.41;
//   long double taxes = 3360552.96;
//   long double effective_percent = 6.99;
//   long double total_sum = 149379728.41;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.effective_percent, effective_percent,
//                            0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_replineshment_01) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1234321;
//   long double percent = 11;
//   int period_type = 0;
//   int period_value = 1234;
//   int payment_frequency = 0;
//   bool interest_capitalization = 0;
//   int replenishment_type = 1;
//   long double replenishment_value = 12345.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 31;
//   int month = 1;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 549555.33;
//   long double taxes = 32442.19;
//   long double total_sum = 1728121.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_replineshment_02) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1234321;
//   long double percent = 11;
//   int period_type = 0;
//   int period_value = 1234;
//   int payment_frequency = 0;
//   bool interest_capitalization = 1;
//   int replenishment_type = 1;
//   long double replenishment_value = 12345.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 31;
//   int month = 1;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 658500.52;
//   long double taxes = 46605.07;
//   long double total_sum = 2386621.52;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_replineshment_03) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1234321;
//   long double percent = 11;
//   int period_type = 0;
//   int period_value = 1234;
//   int payment_frequency = 2;
//   bool interest_capitalization = 0;
//   int replenishment_type = 2;
//   long double replenishment_value = 12345.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 31;
//   int month = 1;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 487455.50;
//   long double taxes = 24957.10;
//   long double total_sum = 1394806.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_replineshment_04) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1234321;
//   long double percent = 11;
//   int period_type = 0;
//   int period_value = 1234;
//   int payment_frequency = 2;
//   bool interest_capitalization = 1;
//   int replenishment_type = 2;
//   long double replenishment_value = 12345.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 31;
//   int month = 1;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 584876.48;
//   long double taxes = 37033.94;
//   long double total_sum = 1979682.48;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_replineshment_05) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1234321;
//   long double percent = 11;
//   int period_type = 0;
//   int period_value = 1234;
//   int payment_frequency = 3;
//   bool interest_capitalization = 0;
//   int replenishment_type = 3;
//   long double replenishment_value = 12345.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 31;
//   int month = 1;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 471940.80;
//   long double taxes = 22352.30;
//   long double total_sum = 1308391.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_replineshment_06) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1234321;
//   long double percent = 11;
//   int period_type = 0;
//   int period_value = 1234;
//   int payment_frequency = 3;
//   bool interest_capitalization = 1;
//   int replenishment_type = 3;
//   long double replenishment_value = 12345.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 31;
//   int month = 1;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 561429.79;
//   long double taxes = 33985.87;
//   long double total_sum = 1869820.79;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_replineshment_07) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1234321;
//   long double percent = 11;
//   int period_type = 0;
//   int period_value = 1234;
//   int payment_frequency = 6;
//   bool interest_capitalization = 0;
//   int replenishment_type = 4;
//   long double replenishment_value = 12345.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 31;
//   int month = 1;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 464274.57;
//   long double taxes = 50605.69;
//   long double total_sum = 1271356.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_replineshment_08) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1234321;
//   long double percent = 11;
//   int period_type = 0;
//   int period_value = 1234;
//   int payment_frequency = 6;
//   bool interest_capitalization = 1;
//   int replenishment_type = 4;
//   long double replenishment_value = 12345.00;
//   int withdrawal_type = 0;
//   long double withdrawal_value = 0.00;

//   int day = 31;
//   int month = 1;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 464274.57;
//   long double taxes = 50605.69;
//   long double total_sum = 1735630.57;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_withdrawal_01) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1234321;
//   long double percent = 11;
//   int period_type = 0;
//   int period_value = 1234;
//   int payment_frequency = 0;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 1;
//   long double withdrawal_value = 1234.00;

//   int day = 30;
//   int month = 1;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 449580.73;
//   long double taxes = 21374.51;
//   long double total_sum = 1184961.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_withdrawal_02) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1234321;
//   long double percent = 11;
//   int period_type = 0;
//   int period_value = 1234;
//   int payment_frequency = 0;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 1;
//   long double withdrawal_value = 1234.00;

//   int day = 30;
//   int month = 1;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 545090.65;
//   long double taxes = 31861.78;
//   long double total_sum = 1730051.65;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_withdrawal_03) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1234321;
//   long double percent = 11;
//   int period_type = 0;
//   int period_value = 1234;
//   int payment_frequency = 2;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 2;
//   long double withdrawal_value = 1234.00;

//   int day = 30;
//   int month = 1;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 455783.27;
//   long double taxes = 21928.13;
//   long double total_sum = 1218279.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_withdrawal_04) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1234321;
//   long double percent = 11;
//   int period_type = 0;
//   int period_value = 1234;
//   int payment_frequency = 2;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 2;
//   long double withdrawal_value = 1234.00;

//   int day = 30;
//   int month = 1;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 549247.35;
//   long double taxes = 32402.16;
//   long double total_sum = 1767526.35;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_withdrawal_05) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1234321;
//   long double percent = 11;
//   int period_type = 0;
//   int period_value = 1234;
//   int payment_frequency = 3;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 3;
//   long double withdrawal_value = 1234.00;

//   int day = 30;
//   int month = 1;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 457332.61;
//   long double taxes = 20453.24;
//   long double total_sum = 1226917.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_withdrawal_06) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1234321;
//   long double percent = 11;
//   int period_type = 0;
//   int period_value = 1234;
//   int payment_frequency = 3;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 3;
//   long double withdrawal_value = 1234.00;

//   int day = 30;
//   int month = 1;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 545232.25;
//   long double taxes = 31880.19;
//   long double total_sum = 1772149.25;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_withdrawal_07) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1234321;
//   long double percent = 11;
//   int period_type = 0;
//   int period_value = 1234;
//   int payment_frequency = 6;
//   bool interest_capitalization = 0;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 4;
//   long double withdrawal_value = 1234.00;

//   int day = 30;
//   int month = 1;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 458098.94;
//   long double taxes = 49802.86;
//   long double total_sum = 1230619.00;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// START_TEST(deposit_withdrawal_08) {
//   deposit_t deposit_db;
//   date_t date;
//   tax_t tax;

//   long double deposit_sum = 1234321;
//   long double percent = 11;
//   int period_type = 0;
//   int period_value = 1234;
//   int payment_frequency = 6;
//   bool interest_capitalization = 1;
//   int replenishment_type = 0;
//   long double replenishment_value = 0.00;
//   int withdrawal_type = 4;
//   long double withdrawal_value = 1234.00;

//   int day = 30;
//   int month = 1;
//   int year = 2023;

//   long double cb_key_rate = 7.5;
//   long double tax_rate = 13.0;
//   long double tax_free_income = 1000000.00;

//   init_deposit(&deposit_db, deposit_sum, percent, period_type, period_value,
//                payment_frequency, interest_capitalization, replenishment_type,
//                replenishment_value, withdrawal_type, withdrawal_value);
//   init_deposit_date(&date, day, month, year, &deposit_db);
//   init_tax_options(&tax, cb_key_rate, tax_rate, tax_free_income);
//   calculate_deposit(&deposit_db, &date, &tax);

//   long double accrued_interest = 458098.94;
//   long double taxes = 49802.86;
//   long double total_sum = 1688717.94;

//   ck_assert_ldouble_eq_tol(deposit_db.accrued_interest, accrued_interest, 0.1);
//   ck_assert_ldouble_eq_tol(deposit_db.taxes, taxes, 0.2);
//   ck_assert_ldouble_eq_tol(deposit_db.total_sum, total_sum, 0.1);
// }
// END_TEST

// Suite *suite_deposit() {
//   Suite *s = suite_create("suite_deposit");
//   TCase *tc = tcase_create("deposit");

//   tcase_add_test(tc, deposit_test_in_days_01);
//   tcase_add_test(tc, deposit_test_in_days_02);
//   tcase_add_test(tc, deposit_test_in_days_03);
//   tcase_add_test(tc, deposit_test_in_days_04);
//   tcase_add_test(tc, deposit_test_in_days_05);
//   tcase_add_test(tc, deposit_test_in_days_06);
//   tcase_add_test(tc, deposit_test_in_days_07);
//   tcase_add_test(tc, deposit_test_in_days_08);
//   tcase_add_test(tc, deposit_test_in_days_09);
//   tcase_add_test(tc, deposit_test_in_days_10);
//   tcase_add_test(tc, deposit_test_in_days_11);
//   tcase_add_test(tc, deposit_test_in_days_12);
//   tcase_add_test(tc, deposit_test_in_days_13);
//   tcase_add_test(tc, deposit_test_in_days_14);

//   tcase_add_test(tc, deposit_test_in_months_01);
//   tcase_add_test(tc, deposit_test_in_months_02);
//   tcase_add_test(tc, deposit_test_in_months_03);
//   tcase_add_test(tc, deposit_test_in_months_04);
//   tcase_add_test(tc, deposit_test_in_months_05);
//   tcase_add_test(tc, deposit_test_in_months_06);
//   tcase_add_test(tc, deposit_test_in_months_07);
//   tcase_add_test(tc, deposit_test_in_months_08);
//   tcase_add_test(tc, deposit_test_in_months_09);
//   tcase_add_test(tc, deposit_test_in_months_10);
//   tcase_add_test(tc, deposit_test_in_months_11);
//   tcase_add_test(tc, deposit_test_in_months_12);
//   tcase_add_test(tc, deposit_test_in_months_13);
//   tcase_add_test(tc, deposit_test_in_months_14);
//   tcase_add_test(tc, deposit_test_in_months_15);
//   tcase_add_test(tc, deposit_test_in_months_16);

//   tcase_add_test(tc, deposit_test_in_years_01);
//   tcase_add_test(tc, deposit_test_in_years_02);
//   tcase_add_test(tc, deposit_test_in_years_03);
//   tcase_add_test(tc, deposit_test_in_years_04);
//   tcase_add_test(tc, deposit_test_in_years_05);
//   tcase_add_test(tc, deposit_test_in_years_06);
//   tcase_add_test(tc, deposit_test_in_years_07);
//   tcase_add_test(tc, deposit_test_in_years_08);
//   tcase_add_test(tc, deposit_test_in_years_09);
//   tcase_add_test(tc, deposit_test_in_years_10);
//   tcase_add_test(tc, deposit_test_in_years_11);
//   tcase_add_test(tc, deposit_test_in_years_12);
//   tcase_add_test(tc, deposit_test_in_years_13);
//   tcase_add_test(tc, deposit_test_in_years_14);

//   tcase_add_test(tc, deposit_replineshment_01);
//   tcase_add_test(tc, deposit_replineshment_02);
//   tcase_add_test(tc, deposit_replineshment_03);
//   tcase_add_test(tc, deposit_replineshment_04);
//   tcase_add_test(tc, deposit_replineshment_05);
//   tcase_add_test(tc, deposit_replineshment_06);
//   tcase_add_test(tc, deposit_replineshment_07);
//   tcase_add_test(tc, deposit_replineshment_08);

//   tcase_add_test(tc, deposit_withdrawal_01);
//   tcase_add_test(tc, deposit_withdrawal_02);
//   tcase_add_test(tc, deposit_withdrawal_03);
//   tcase_add_test(tc, deposit_withdrawal_04);
//   tcase_add_test(tc, deposit_withdrawal_05);
//   tcase_add_test(tc, deposit_withdrawal_06);
//   tcase_add_test(tc, deposit_withdrawal_07);
//   tcase_add_test(tc, deposit_withdrawal_08);

//   suite_add_tcase(s, tc);
//   return s;
// }
