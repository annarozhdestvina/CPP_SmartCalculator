#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define S21_PI_2 1.57079632679489661923
#define BUFF_SIZE 256

typedef enum {
  OK,
  NULL_LENGTH,
  OVER_LENGTH,
  INVALID_SYMBOL,
  INVALID_CLOSE_BRACKET,
  INVALID_OPEN_BRACKET,
  INVALID_LEXEME,
  DIV_ZERO,
  NEGATIVE_ROOT,
  NEGATIVE_LOG_LN
} result;

typedef enum {
  NUMBER,
  X_VAR,
  PLUS,
  MINUS,
  MUL,
  DIV,
  POW,
  MOD,
  SQRT,
  UNARY_PLUS,
  UNARY_MINUS,
  BRACKET_OPEN,
  BRACKET_CLOSE,
  SIN,
  ASIN,
  COS,
  ACOS,
  TAN,
  ATAN,
  LOG,
  LN
} token_type;

typedef struct {
  int result_code;
  int position;
} result_t;

typedef struct {
  int token;
  int priority;
  long double number;
} lexeme_t;

int validate_input(const char *input_str, lexeme_t *lexemes, result_t *result);

void validate_length(const char *input_str, result_t *result);
int validate_lexemes(const char *input_str, result_t *result);
void validate_brackets(const char *input_str, result_t *result);
void validate_operations(lexeme_t *lexemes, int lexeme_count, result_t *result);
void validate_numbers_and_functions(lexeme_t *lexemes, int lexeme_count,
                                    result_t *result);

int convert_input_str(const char *input_str, lexeme_t *lexemes);

void convert_string_to_lexeme(const char **input_str, lexeme_t *lexeme);
int check_function(const char **input_str);
int check_operation(const char **input_str);
void check_unary_operations(lexeme_t *lexemes, int lexeme_count);
void set_priority(lexeme_t *lexemes, int lexeme_count);

int revers_polish_notation(lexeme_t *lexemes, int lexeme_count,
                           lexeme_t *polish);

bool check_value(lexeme_t *polish, int polish_count);
void set_value(lexeme_t *polish, int polish_count, long double x_var);

long double calculate(lexeme_t *polish, int polish_count, int *code);
long double run_function(int token, long double var, int *code);
long double run_operation(int token, long double var_a, long double var_b,
                          int *code);

bool is_number(int token);
bool is_add_sub(int token);
bool is_unary_operator(int token);
bool is_operator(int token);
bool is_function(int token);

#endif  // CALCULATOR_H_
