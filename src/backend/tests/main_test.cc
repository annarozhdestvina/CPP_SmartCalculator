#include <gtest/gtest.h>

int main(int argument_counter, char **arguments) {
  ::testing::InitGoogleTest(&argument_counter, arguments);
  return RUN_ALL_TESTS();
}


// #include "main_test.h"

// int main() {
//   run_tests();
//   return 0;
// }

// void run_tests() {
//   Suite *list_cases[] = {suite_calculator(), suite_loan(), suite_deposit(),
//                          NULL};

//   for (Suite **current_testcase = list_cases; *current_testcase;
//        current_testcase++)
//     run_testcase(*current_testcase);
// }

// void run_testcase(Suite *testcase) {
//   static int counter_testcase = 1;

//   if (counter_testcase > 1) putchar('\n');
//   printf("CURRENT TEST: %d\n", counter_testcase);
//   counter_testcase++;

//   SRunner *sr = srunner_create(testcase);

//   srunner_set_fork_status(sr, CK_NOFORK);
//   srunner_run_all(sr, CK_NORMAL);

//   srunner_free(sr);
// }
