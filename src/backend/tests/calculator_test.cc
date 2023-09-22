#include <gtest/gtest.h>

#include "../base/calculator.h"
#include "../extra/loan_deposit.h"

namespace {

TEST(array, T0Operator) {
  
  EXPECT_EQ(true, true);
}


TEST(Calculator, test_01) {
  result_t result;
  result.position = 0;
  result.result_code = OK;

  lexeme_t lexemes[BUFF_SIZE];
  lexeme_t polish[BUFF_SIZE];

  char input_str[] = "1 + 2";
  long double check = 3.0l;

  int lexeme_count = validate_input(input_str, lexemes, &result);

  // ck_assert_int_eq(lexeme_count, 3);
  EXPECT_EQ(lexeme_count, 3);
  EXPECT_EQ(result.result_code, OK);

  int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

  EXPECT_EQ(polish_count, 3);

  int code;
  calculate(polish, polish_count, &code);

  long double ans = calculate(polish, polish_count, &code);

  EXPECT_EQ(code, OK);
  EXPECT_NEAR(ans, check, 1E-8);
}


} // namespace



// #include "main_test.h"

// START_TEST(calculator_test_01) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] = "1 + 2";
//   long double check = 3.0;

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 3);
//   ck_assert_int_eq(result.result_code, OK);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   ck_assert_int_eq(polish_count, 3);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, OK);
//   ck_assert_ldouble_eq_tol(ans, check, 1E-8);
// }
// END_TEST

// START_TEST(calculator_test_02) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] = "(1 + 2 )";
//   long double check = 3.0;

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 5);
//   ck_assert_int_eq(result.result_code, OK);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   ck_assert_int_eq(polish_count, 3);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, OK);
//   ck_assert_ldouble_eq_tol(ans, check, 1E-8);
// }
// // END_TEST

// START_TEST(calculator_test_03) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] = "5.25 / ( 4.2 + - 2.1 )";
//   long double check = 2.5;

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 8);
//   ck_assert_int_eq(result.result_code, OK);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   ck_assert_int_eq(polish_count, 6);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, OK);
//   ck_assert_ldouble_eq_tol(ans, check, 1E-8);
// }
// END_TEST

// START_TEST(calculator_test_04) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] = "1 + ( sin(45) + cos(45) )";
//   long double check = 2.376225513351;

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 13);
//   ck_assert_int_eq(result.result_code, OK);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   ck_assert_int_eq(polish_count, 7);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, OK);
//   ck_assert_ldouble_eq_tol(ans, check, 1E-8);
// }
// END_TEST

// START_TEST(calculator_test_05) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] = "cos(.978) * sin(tan(45.05099) / 2.37)";
//   long double check = 0.388320908496;

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 14);
//   ck_assert_int_eq(result.result_code, OK);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   ck_assert_int_eq(polish_count, 8);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, OK);
//   ck_assert_ldouble_eq_tol(ans, check, 1E-8);
// }
// END_TEST

// START_TEST(calculator_test_06) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] = "acos(.5) - asin(atan(0.3) ^ 3.4)";
//   long double check = 1.032076959890;

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 14);
//   ck_assert_int_eq(result.result_code, OK);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   ck_assert_int_eq(polish_count, 8);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, OK);
//   ck_assert_ldouble_eq_tol(ans, check, 1E-8);
// }
// END_TEST

// START_TEST(calculator_test_07) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] = "-cos(-1) + -sin(1)";
//   long double check = -1.381773290676;

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 12);
//   ck_assert_int_eq(result.result_code, OK);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   ck_assert_int_eq(polish_count, 8);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, OK);
//   ck_assert_ldouble_eq_tol(ans, check, 1E-8);
// }
// END_TEST

// START_TEST(calculator_test_08) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] = "ln(6) + log(12.56) + -sqrt(56)";
//   long double check = -4.592565664918;

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 15);
//   ck_assert_int_eq(result.result_code, OK);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   ck_assert_int_eq(polish_count, 9);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, OK);
//   ck_assert_ldouble_eq_tol(ans, check, 1E-8);
// }
// END_TEST

// START_TEST(calculator_test_09) {
//   result_t result = {0};
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] = "ln(6) + (log(12.56) + -sqrt(56))";
//   long double check = -4.592565664918;

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 17);
//   ck_assert_int_eq(result.result_code, OK);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   ck_assert_int_eq(polish_count, 9);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, OK);
//   ck_assert_ldouble_eq_tol(ans, check, 1E-8);
// }
// END_TEST

// START_TEST(calculator_test_10) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] =
//       "sin(2) * cos(5) + tan(67^2) / sin(128) - atan(sqrt(9)) - (4 mod 2) * "
//       "log(5)";
//   long double check = -1.475321162573;

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 40);
//   ck_assert_int_eq(result.result_code, OK);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   ck_assert_int_eq(polish_count, 24);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, OK);
//   ck_assert_ldouble_eq_tol(ans, check, 1E-8);
// }
// END_TEST

// START_TEST(calculator_valid_test_01) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};

//   char input_str[] =
//       "ln(6) + log(12.56) + -sqrt(56) + ln(6) + log(12.56) + -sqrt(56) +"
//       "ln(6) + log(12.56) + -sqrt(56) + ln(6) + log(12.56) + -sqrt(56) +"
//       "ln(6) + log(12.56) + -sqrt(56) + ln(6) + log(12.56) + -sqrt(56) +"
//       "ln(6) + log(12.56) + -sqrt(56) + ln(6) + log(12.56) + -sqrt(56) +";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 0);
//   ck_assert_int_eq(result.result_code, OVER_LENGTH);
// }
// END_TEST

// START_TEST(calculator_valid_test_02) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};

//   char input_str[] = "ln(6) + log(12.56) m + -sqrt(56)";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 0);
//   ck_assert_int_eq(result.result_code, INVALID_SYMBOL);
//   ck_assert_int_eq(result.position, 20);
// }
// END_TEST

// START_TEST(calculator_valid_test_03) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};

//   char input_str[] = "ln(6) + si + log(12.56) - m + -sqrt(56)";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 0);
//   ck_assert_int_eq(result.result_code, INVALID_SYMBOL);
//   ck_assert_int_eq(result.position, 9);
// }
// END_TEST

// START_TEST(calculator_valid_test_04) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};

//   char input_str[] = "(ln(6)) + (log(12.56) + -sqrt(56)))";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 0);
//   ck_assert_int_eq(result.result_code, INVALID_CLOSE_BRACKET);
//   ck_assert_int_eq(result.position, 35);
// }
// END_TEST

// START_TEST(calculator_valid_test_05) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};

//   char input_str[] = "((ln(6) + (log(12.56) + -sqrt(56)))";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 0);
//   ck_assert_int_eq(result.result_code, INVALID_OPEN_BRACKET);
//   ck_assert_int_eq(result.position, 0);
// }
// END_TEST

// START_TEST(calculator_valid_test_06) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};

//   char input_str[] = "* ln(6) + log(12.56) + -sqrt(56)";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 16);
//   ck_assert_int_eq(result.result_code, INVALID_LEXEME);
//   ck_assert_int_eq(result.position, 0);
// }
// END_TEST

// START_TEST(calculator_valid_test_07) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};

//   char input_str[] = "ln(6) + log(12.56) + -sqrt(56) +";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 16);
//   ck_assert_int_eq(result.result_code, INVALID_LEXEME);
//   ck_assert_int_eq(result.position, 0);
// }
// END_TEST

// START_TEST(calculator_valid_test_08) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};

//   char input_str[] = "ln() + log(12.56) + -sqrt(56)";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 14);
//   ck_assert_int_eq(result.result_code, INVALID_LEXEME);
//   ck_assert_int_eq(result.position, 0);
// }
// END_TEST

// START_TEST(calculator_valid_test_09) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};

//   char input_str[] = "ln(6) + ^ log(12.56) + -sqrt(56)";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 16);
//   ck_assert_int_eq(result.result_code, INVALID_LEXEME);
//   ck_assert_int_eq(result.position, 0);
// }
// END_TEST

// START_TEST(calculator_valid_test_10) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};

//   char input_str[] = "ln(6) + log(12.56) + -sqrt";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 12);
//   ck_assert_int_eq(result.result_code, INVALID_LEXEME);
//   ck_assert_int_eq(result.position, 0);
// }
// END_TEST

// START_TEST(calculator_valid_test_11) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};

//   char input_str[] = "ln(6) + log(12.56 15) + -sqrt(56)";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 16);
//   ck_assert_int_eq(result.result_code, INVALID_LEXEME);
//   ck_assert_int_eq(result.position, 0);
// }
// END_TEST

// START_TEST(calculator_valid_test_12) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};

//   char input_str[] = "ln(6) + 15 log(12.56) + -sqrt(56)";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 16);
//   ck_assert_int_eq(result.result_code, INVALID_LEXEME);
//   ck_assert_int_eq(result.position, 0);
// }
// END_TEST

// START_TEST(calculator_valid_test_13) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] = "ln(6) + log(12.56 / 0) + -sqrt(56)";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 17);
//   ck_assert_int_eq(result.result_code, OK);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   ck_assert_int_eq(polish_count, 11);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, DIV_ZERO);
//   ck_assert_ldouble_eq_tol(ans, 0, 1E-8);
// }
// END_TEST

// START_TEST(calculator_valid_test_14) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] = "ln(6) + log(12.56) + -sqrt(-56)";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 16);
//   ck_assert_int_eq(result.result_code, OK);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   ck_assert_int_eq(polish_count, 10);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, NEGATIVE_ROOT);
//   ck_assert_ldouble_eq_tol(ans, 0, 1E-8);
// }
// END_TEST

// START_TEST(calculator_valid_test_15) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] = "ln(6) + log(-12.56) + -sqrt(56)";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 16);
//   ck_assert_int_eq(result.result_code, OK);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   ck_assert_int_eq(polish_count, 10);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, NEGATIVE_LOG_LN);
//   ck_assert_ldouble_eq_tol(ans, 0, 1E-8);
// }
// END_TEST

// START_TEST(calculator_valid_test_16) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] = "ln(-6) + log(12.56) + -sqrt(56)";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 16);
//   ck_assert_int_eq(result.result_code, OK);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   ck_assert_int_eq(polish_count, 10);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, NEGATIVE_LOG_LN);
//   ck_assert_ldouble_eq_tol(ans, 0, 1E-8);
// }
// END_TEST

// START_TEST(calculator_valid_test_17) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] = "ln(6) + log(12.56) + -tan(1.5707963268)";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 15);
//   ck_assert_int_eq(result.result_code, OK);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   ck_assert_int_eq(polish_count, 9);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, DIV_ZERO);
//   ck_assert_ldouble_eq_tol(ans, 0, 1E-8);
// }
// END_TEST

// START_TEST(calculator_valid_test_18) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};

//   char input_str[] = "ln(6) + log(12.56) + -tan1.5707963268";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 13);
//   ck_assert_int_eq(result.result_code, INVALID_LEXEME);
//   ck_assert_int_eq(result.position, 0);
// }
// END_TEST

// START_TEST(calculator_valid_test_19) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};

//   char input_str[] = "";

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 0);
//   ck_assert_int_eq(result.result_code, NULL_LENGTH);
//   ck_assert_int_eq(result.position, 0);
// }
// END_TEST

// START_TEST(calculator_large_test_01) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] =
//       "cos(tan(2.0221 + tan(sin(cos(5.0945)) - tan(cos(3.6593))) ^ 1.4616) -"
//       "sin(4.1949 - sin(cos(tan(tan(cos(3.8475)))) ^ 8.8451) ^ 1.4109) -"
//       "tan(2.6884 / tan(5.2519 / 6.5461)))";
//   long double check = -0.899891009753;

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, OK);
//   ck_assert_ldouble_eq_tol(ans, check, 1E-8);
// }
// END_TEST

// START_TEST(calculator_large_test_02) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] =
//       "tan(3.764) ^ sin(9.445 - sin(7.2889 / 8.0438 -"
//       "cos(sin(cos(tan(8.4448))) - 4.482)) /"
//       "tan(cos(cos(sin(cos(cos(2.003)))) / 0.1315))) - 8.8453 / "
//       "0.3612";
//   long double check = -23.766674545863;

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, OK);
//   ck_assert_ldouble_eq_tol(ans, check, 1E-8);
// }
// END_TEST

// START_TEST(calculator_large_test_03) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] =
//       "tan(sin(cos(8.8905) - 9.586)) / tan(9.6334) - sin(4.091 - 6.8317 ^"
//       "1.3065) + sin(tan(2.4431 + 7.5867) ^ sin(sin( 6.6115 ^ 3.7525) /"
//       "tan(sin(tan(tan(7.1462))) / sin(2.7571))))";
//   long double check = 7.167106761528;

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, OK);
//   ck_assert_ldouble_eq_tol(ans, check, 1E-8);
// }
// END_TEST

// START_TEST(calculator_large_test_04) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] =
//       "2.4474 / 8.0162 / 3.2142 + tan(0.6211 + sin(tan(7.5952 + 5.3702)) -"
//       "4.7121 ^ sin(1.9427 - 2.8496)) / cos(0.2688 ^ 0.5391 +"
//       "cos(tan(cos(cos(5.6221))) / sin(2.3295) - tan(cos(tan(cos(9.2239))))))";
//   long double check = 1.660108415838;

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, OK);
//   ck_assert_ldouble_eq_tol(ans, check, 1E-8);
// }
// END_TEST

// START_TEST(calculator_large_test_05) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] =
//       "asin(.4474) / acos(0.0162) / 3.2142 + tan(0.6211 + asin(.3702) -"
//       " 2 mod 3 + 4.7121 ^ sin(1.9427 * 2.8496)) / cos(0.2688 ^ 0.5391 +"
//       "cos(tan(cos(cos(5.6221))) / sin(2.3295) - tan(cos(atan(cos(9.2239))))))";
//   long double check = -6.060250573134;

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, OK);
//   ck_assert_ldouble_eq_tol(ans, check, 1E-8);
// }
// END_TEST

// START_TEST(calculator_variable_test_01) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] = "ln(6) + log(x) + -sqrt(56)";
//   long double check = -4.592565664918;

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 15);
//   ck_assert_int_eq(result.result_code, OK);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   ck_assert_int_eq(polish_count, 9);

//   long double x_var = 12.56;
//   if (check_value(polish, polish_count)) set_value(polish, polish_count, x_var);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, OK);
//   ck_assert_ldouble_eq_tol(ans, check, 1E-8);
// }
// END_TEST

// START_TEST(calculator_variable_test_02) {
//   result_t result;
//   result.position = 0;
//   result.result_code = OK;

//   lexeme_t lexemes[BUFF_SIZE] = {0};
//   lexeme_t polish[BUFF_SIZE] = {0};

//   char input_str[] = "x + x ^ 2";
//   long double check = 12;

//   int lexeme_count = validate_input(input_str, lexemes, &result);

//   ck_assert_int_eq(lexeme_count, 5);
//   ck_assert_int_eq(result.result_code, OK);

//   int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);

//   ck_assert_int_eq(polish_count, 5);

//   long double x_var = 3;
//   if (check_value(polish, polish_count)) set_value(polish, polish_count, x_var);

//   int code;

//   long double ans = calculate(polish, polish_count, &code);

//   ck_assert_int_eq(code, OK);
//   ck_assert_ldouble_eq_tol(ans, check, 1E-8);
// }
// END_TEST

// Suite *suite_calculator() {
//   Suite *s = suite_create("suite_calculator");
//   TCase *tc = tcase_create("calculator");

//   tcase_add_test(tc, calculator_test_01);
//   tcase_add_test(tc, calculator_test_02);
//   tcase_add_test(tc, calculator_test_03);
//   tcase_add_test(tc, calculator_test_04);
//   tcase_add_test(tc, calculator_test_05);
//   tcase_add_test(tc, calculator_test_06);
//   tcase_add_test(tc, calculator_test_07);
//   tcase_add_test(tc, calculator_test_08);
//   tcase_add_test(tc, calculator_test_09);
//   tcase_add_test(tc, calculator_test_10);

//   tcase_add_test(tc, calculator_valid_test_01);
//   tcase_add_test(tc, calculator_valid_test_02);
//   tcase_add_test(tc, calculator_valid_test_03);
//   tcase_add_test(tc, calculator_valid_test_04);
//   tcase_add_test(tc, calculator_valid_test_05);
//   tcase_add_test(tc, calculator_valid_test_06);
//   tcase_add_test(tc, calculator_valid_test_07);
//   tcase_add_test(tc, calculator_valid_test_08);
//   tcase_add_test(tc, calculator_valid_test_09);
//   tcase_add_test(tc, calculator_valid_test_10);
//   tcase_add_test(tc, calculator_valid_test_11);
//   tcase_add_test(tc, calculator_valid_test_12);
//   tcase_add_test(tc, calculator_valid_test_13);
//   tcase_add_test(tc, calculator_valid_test_14);
//   tcase_add_test(tc, calculator_valid_test_15);
//   tcase_add_test(tc, calculator_valid_test_16);
//   tcase_add_test(tc, calculator_valid_test_17);
//   tcase_add_test(tc, calculator_valid_test_18);
//   tcase_add_test(tc, calculator_valid_test_19);

//   tcase_add_test(tc, calculator_large_test_01);
//   tcase_add_test(tc, calculator_large_test_02);
//   tcase_add_test(tc, calculator_large_test_03);
//   tcase_add_test(tc, calculator_large_test_04);
//   tcase_add_test(tc, calculator_large_test_05);

//   tcase_add_test(tc, calculator_variable_test_01);
//   tcase_add_test(tc, calculator_variable_test_02);

//   suite_add_tcase(s, tc);
//   return s;
// }
