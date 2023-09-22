#include "calculator.h"

/*
    check_function

    - ЧТО ДЕЛАЕТ: распознает в массиве input_str лексемы, являющиеся
   математическими функциями

    - ПАРАМЕТРЫ:
        1. указатель на индекс массива, введенного в консоль

    - ПОРЯДОК РАБОТЫ:
        1. С помощью библиотечной функции strstr производится поиск совпадения
   названия математической функции в массиве input_str. В случае совпадения:
          - в структуру lexeme --> элемент token записывается тип,
   соответствующий математической функции
          - индекс массива input_str увеличивается на число символов в названии
   данной функции

    - РЕЗУЛЬТАТ: тип токена в списке token_type
*/
int check_function(const char **input_str) {
  int token = -1;

  if (strstr(*input_str, "sin") == *input_str) {
    token = SIN;
    *input_str += 3;
  } else if (strstr(*input_str, "asin") == *input_str) {
    token = ASIN;
    *input_str += 4;
  } else if (strstr(*input_str, "cos") == *input_str) {
    token = COS;
    *input_str += 3;
  } else if (strstr(*input_str, "acos") == *input_str) {
    token = ACOS;
    *input_str += 4;
  } else if (strstr(*input_str, "tan") == *input_str) {
    token = TAN;
    *input_str += 3;
  } else if (strstr(*input_str, "atan") == *input_str) {
    token = ATAN;
    *input_str += 4;
  } else if (strstr(*input_str, "log") == *input_str) {
    token = LOG;
    *input_str += 3;
  } else if (strstr(*input_str, "ln") == *input_str) {
    token = LN;
    *input_str += 2;
  } else if (strstr(*input_str, "sqrt") == *input_str) {
    token = SQRT;
    *input_str += 4;
  }

  return token;
}

/*
    check_operation

    - ЧТО ДЕЛАЕТ: распознает в массиве input_str лексемы, являющиеся
   операторами

    - ПАРАМЕТРЫ:
        1. указатель на индекс массива, введенного в консоль

    - ПОРЯДОК РАБОТЫ:
        1. Производится поиск совпадения символа оператора (операция взятия
   остатка mod - помощью библиотечной функции strstr) в массиве input_str. В
   случае совпадения:
          - в структуру lexeme --> элемент token записывается тип,
   соответствующий оператору
          - индекс массива input_str увеличивается на число символов оператора

    - РЕЗУЛЬТАТ: тип токена в списке token_type
*/
int check_operation(const char **input_str) {
  int token = -1;

  if (**input_str == '+') {
    token = PLUS;
    *input_str += 1;
  } else if (**input_str == '-') {
    token = MINUS;
    *input_str += 1;
  } else if (**input_str == '*') {
    token = MUL;
    *input_str += 1;
  } else if (**input_str == '/') {
    token = DIV;
    *input_str += 1;
  } else if (**input_str == '^') {
    token = POW;
    *input_str += 1;
  } else if (**input_str == '(') {
    token = BRACKET_OPEN;
    *input_str += 1;
  } else if (**input_str == ')') {
    token = BRACKET_CLOSE;
    *input_str += 1;
  } else if (strstr(*input_str, "mod") == *input_str) {
    token = MOD;
    *input_str += 3;
  }

  return token;
}

/*
    check_unary_operations

    - ЧТО ДЕЛАЕТ: распознает в массиве input_str лексемы, являющиеся
   унарными операторами

    - ПАРАМЕТРЫ:
        1. структура lexemes
        2. количество лексем в массиве

    - ПОРЯДОК РАБОТЫ:
        1. Производится поиск в массиве лексем, где текущий элемент в массиве
   является либо числом, либо математической функцией, а предыдущий элемент -
   плюсом или минусом.
        2. Если условия п.1 удовлетворяются для 0 и 1 элемента массива лексем,
   то в структуру lexeme --> элемент token предыдущего элемента записывается тип
   UNARY_PLUS / UNARY_MINUS
        3. Если элемент, предшествующий предыдущему элементу массива лексем
   (индекс i-2), является либо оператором, либо открывающейся скобкой, то в
   структуру lexeme --> элемент token предыдущего элемента записывается тип
   UNARY_PLUS / UNARY_MINUS

    - РЕЗУЛЬТАТ: -
*/
void check_unary_operations(lexeme_t *lexemes, int lexeme_count) {
  for (int i = 1; i < lexeme_count; i++) {
    if ((is_number(lexemes[i].token) || is_function(lexemes[i].token)) &&
        is_add_sub(lexemes[i - 1].token)) {
      if (i == 1) {
        lexemes[i - 1].token =
            (lexemes[i - 1].token == PLUS) ? UNARY_PLUS : UNARY_MINUS;
      } else if (is_operator(lexemes[i - 2].token) ||
                 lexemes[i - 2].token == BRACKET_OPEN) {
        lexemes[i - 1].token =
            (lexemes[i - 1].token == PLUS) ? UNARY_PLUS : UNARY_MINUS;
      }
    }
  }
}

/*
    is_number

    - ЧТО ДЕЛАЕТ: определяет, является лексема числом или Х-переменной

    - ПАРАМЕТРЫ:
        1. тип ликсемы из списка token_type, записанный в cтруктуру lexeme -->
   элемент token

    - ПОРЯДОК РАБОТЫ:
        1. Если лексема является числом или Х-переменной, то возвращается
   значение 1 (true), в ином случае 0 (false)

    - РЕЗУЛЬТАТ: булево значение (true/false)
*/
bool is_number(int token) { return token == NUMBER || token == X_VAR; }

/*
    is_number

    - ЧТО ДЕЛАЕТ: определяет, является лексема плюсом или минусом

    - ПАРАМЕТРЫ:
        1. тип ликсемы из списка token_type, записанный в cтруктуру lexeme -->
   элемент token

    - ПОРЯДОК РАБОТЫ:
        1. Если лексема является плюсом или минусом, то возвращается
   значение 1 (true), в ином случае 0 (false)

    - РЕЗУЛЬТАТ: булево значение (true/false)
*/
bool is_add_sub(int token) { return token == PLUS || token == MINUS; }

/*
    is_unary_operator

    - ЧТО ДЕЛАЕТ: определяет, является лексема унарным оператором

    - ПАРАМЕТРЫ:
        1. тип ликсемы из списка token_type, записанный в cтруктуру lexeme -->
   элемент token

    - ПОРЯДОК РАБОТЫ:
        1. Если лексема является унарным оператором, то возвращается
   значение 1 (true), в ином случае 0 (false)

    - РЕЗУЛЬТАТ: булево значение (true/false)
*/
bool is_unary_operator(int token) {
  return token == UNARY_PLUS || token == UNARY_MINUS;
}

/*
    is_operator

    - ЧТО ДЕЛАЕТ: определяет, является лексема оператором

    - ПАРАМЕТРЫ:
        1. тип ликсемы из списка token_type, записанный в cтруктуру lexeme -->
   элемент token

    - ПОРЯДОК РАБОТЫ:
        1. Если лексема является оператором, то возвращается
   значение 1 (true), в ином случае 0 (false)

    - РЕЗУЛЬТАТ: булево значение (true/false)
*/
bool is_operator(int token) {
  return token == PLUS || token == MINUS || token == MUL || token == DIV ||
         token == POW || token == MOD;
}

/*
    is_function

    - ЧТО ДЕЛАЕТ: определяет, является лексема математической функцией

    - ПАРАМЕТРЫ:
        1. тип ликсемы из списка token_type, записанный в cтруктуру lexeme -->
   элемент token

    - ПОРЯДОК РАБОТЫ:
        1. Если лексема является математической функцией, то возвращается
   значение 1 (true), в ином случае 0 (false)

    - РЕЗУЛЬТАТ: булево значение (true/false)
*/
bool is_function(int token) {
  return token == SIN || token == ASIN || token == COS || token == ACOS ||
         token == TAN || token == ATAN || token == LOG || token == LN ||
         token == SQRT;
}
