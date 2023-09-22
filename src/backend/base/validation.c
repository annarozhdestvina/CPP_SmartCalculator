#include "calculator.h"

/*
    validate_input

    - ЧТО ДЕЛАЕТ: проверяет корректность введенных данных

    - ПАРАМЕТРЫ:
        1. введенный в консоль массив
        2. структура lexemes
        3. структура result

    - ПОРЯДОК РАБОТЫ:
        1. В (int) переменную length записывается результат функции
   validate_lexemes (длина введённого массива)
        2. В структуру result --> элемент result_code записываются ошибки:
            - NULL_LENGTH, если длина массива = 0
            - OVER_LENGTH, если длина массива более 255 символов
        3. Если после п.2 нет ошибок, то выполняем функцию validate_brackets
        4. Если после п.3 нет ошибок, то в переменную lexeme_count записывается
   результат функции convert_input_str (количество лексем в массиве)
        5. Если после п.3 нет ошибок, то выполняем функцию validate_operations
        6. Если после п.5 нет ошибок, то выполняем функцию
   validate_numbers_and_functions

    - РЕЗУЛЬТАТ: количество лексем в массиве (из п.4)
*/
int validate_input(const char *input_str, lexeme_t *lexemes, result_t *result) {
  int lexeme_count = 0;

  int length = validate_lexemes(input_str, result);

  if (length == 0) {
    result->result_code = NULL_LENGTH;
  } else if (length > 255) {
    result->result_code = OVER_LENGTH;
  }

  if (result->result_code == OK) validate_brackets(input_str, result);

  if (result->result_code == OK) {
    lexeme_count = convert_input_str(input_str, lexemes);
    validate_operations(lexemes, lexeme_count, result);

    if (result->result_code == OK)
      validate_numbers_and_functions(lexemes, lexeme_count, result);
  }

  return lexeme_count;
}

/*
    validate_lexemes

    - ЧТО ДЕЛАЕТ: проверяет корректность каждого токена в массиве input_str

    - ПАРАМЕТРЫ:
        1. введенный в консоль массив
        2. структура result

    - ПОРЯДОК РАБОТЫ:
        1. В (char) переменную start_char записывается input_str
   (введенный в консоль массив)
        2. Инициализируется двумерный (char) массив valid_input_tokens с
   перечеслением корректных токенов:
          - точка
          - пробел
          - числа 0-9
          - X/x (обозначение переменной в выражении)
          - арифметические операторы
          - круглые скобки
          - математические функции
        3. Проверяется наличие каждого токена массива input_str в двумерном
   массиве valid_input_tokens. Если есть совпадение то устанавливается flag = 1
        4. Если после п.3 flag = 0:
          - в структуру result --> элемент result_code записывается ошибка
   INVALID_SYMBOL
          - в структуру result --> элемент position записывается порядковый
   номер в массиве ошибочного токена
          - досрочный выход из цикла
        5. Индекс массива input_str увеличивается на длину валидного токена
   (например, '+' на 1, 'sin' на 3)

    - РЕЗУЛЬТАТ: длина введённого массива (разница между адресом окончания и
   адресом начала введенного массива input_str)
*/
int validate_lexemes(const char *input_str, result_t *result) {
  const char *start_char = input_str;

  char valid_input_tokens[31][5] = {
      ".",  "0",   "1",    "2",   "3",    "4",   "5",    "6",
      "7",  "8",   "9",    " ",   "+",    "-",   "*",    "/",
      "^",  "(",   ")",    "x",   "X",    "mod", "sqrt", "log",
      "ln", "sin", "asin", "cos", "acos", "tan", "atan"};

  while (*input_str) {
    int i = 0;
    int flag = 0;

    for (; i < 31; i++) {
      if (strstr(input_str, valid_input_tokens[i]) == input_str) {
        flag = 1;
        break;
      }
    }

    if (flag == 0) {
      result->result_code = INVALID_SYMBOL;
      result->position = input_str - start_char + 1;
      break;
    }

    input_str += strlen(valid_input_tokens[i]);
  }

  return (int)(input_str - start_char);
}

/*
    validate_brackets

    - ЧТО ДЕЛАЕТ: проверяет совпадение числа открывающихся и закрывающихся
   скобок в массиве input_str

    - ПАРАМЕТРЫ:
        1. введенный в консоль массив
        2. структура result

    - ПОРЯДОК РАБОТЫ:
        1. В (char) переменную start_char записывается input_str
   (введенный в консоль массив)
        2. Проверяется совпадение числа открывающихся и закрывающихся скобок в
   массиве input_str:
          - flag увеличивается на 1 при открывающейся скобке
          - flag уменьшается на 1 при закрывающейся скобке
        3. Если после п.2 flag < 0:
          - в структуру result --> элемент result_code записывается ошибка
   INVALID_CLOSE_BRACKET
          - в структуру result --> элемент position записывается порядковый
   номер в массиве ошибочного токена
          - досрочный выход из цикла
        4. Если после п.2 flag > 0:
          - в структуру result --> элемент result_code записывается ошибка
   INVALID_OPEN_BRACKET
          - в структуру result --> элемент position записывается порядковый
   номер в массиве ошибочного токена

    - РЕЗУЛЬТАТ: -
*/
void validate_brackets(const char *input_str, result_t *result) {
  const char *start_char = input_str;
  int flag = 0;

  while (*input_str) {
    if (*input_str == '(') flag++;
    if (*input_str == ')') flag--;
    if (flag < 0) {
      result->result_code = INVALID_CLOSE_BRACKET;
      result->position = input_str - start_char + 1;
      break;
    }
    input_str++;
  }

  if (flag > 0) result->result_code = INVALID_OPEN_BRACKET;
}

/*
    validate_operations

    - ЧТО ДЕЛАЕТ: проверяет корректность лексем слева и справа от лексем,
   являющихся операторами

    - ПАРАМЕТРЫ:
        1. структура lexemes
        2. количество лексем в массиве
        3. структура result

    - ПОРЯДОК РАБОТЫ:
        1. В структуру result --> элемент result_code записывается ошибка
   INVALID_LEXEME, если первая или последняя лексема в массиве является
   оператором
        2. В цикле рассматриваются лексемы, являющиеся операторами.
   Инициализируются (int) переменные token_left (лексема i-1 порядка - слева от
   оператора) и token_right (лексема i+1 порядка - справа от оператора)
   ).
        3. Если token_right является унарным оператором, то индекс token_right
   становится i+2
        4. В структуру result --> элемент result_code записывается ошибка
   INVALID_LEXEME, если token_left не является числом и/или token_left является
   закрывающейся скобкой
        5. В структуру result --> элемент result_code записывается ошибка
   INVALID_LEXEME, если token_right не является числом и/или token_right
   является открывающейся скобкой и/или token_right не является математической
   функцией

    - РЕЗУЛЬТАТ: -
*/
void validate_operations(lexeme_t *lexemes, int lexeme_count,
                         result_t *result) {
  if (is_operator(lexemes[0].token)) {
    result->result_code = INVALID_LEXEME;
  } else if (is_operator(lexemes[lexeme_count - 1].token)) {
    result->result_code = INVALID_LEXEME;
  } else {
    for (int i = 1; i < lexeme_count - 1; i++) {
      if (is_operator(lexemes[i].token)) {
        int token_left = lexemes[i - 1].token;
        int token_right = lexemes[i + 1].token;
        if (is_unary_operator(token_right)) token_right = lexemes[i + 2].token;

        if (!(is_number(token_left) || token_left == BRACKET_CLOSE)) {
          result->result_code = INVALID_LEXEME;
        } else if (!(is_number(token_right) || token_right == BRACKET_OPEN ||
                     is_function(token_right))) {
          result->result_code = INVALID_LEXEME;
        }
      }
    }
  }
}

/*
    validate_numbers_and_functions

    - ЧТО ДЕЛАЕТ: проверяет корректность лексем слева и справа от лексем,
   являющихся числами, математическими функциями, скобками

    - ПАРАМЕТРЫ:
        1. структура lexemes
        2. количество лексем в массиве
        3. структура result

    - ПОРЯДОК РАБОТЫ:
        1. В структуру result --> элемент result_code записывается ошибка
   INVALID_LEXEME, если последняя лексема в массиве является математической
   функцией
        2. В структуру result --> элемент result_code записывается ошибка
   INVALID_LEXEME, если текущая лексема является числом, а следующая лексема
   (i+1 порядка) является либо числом, либо унарным оператором, либо
   математической функцией
        3. В структуру result --> элемент result_code записывается ошибка
   INVALID_LEXEME, если текущая лексема является математической функцией, а
   следующая лексема (i+1 порядка) не является открывающейся скобкой, либо
   предыдущая лексема (i-1 порядка) является закрывающейся скобкой
        4. В структуру result --> элемент result_code записывается ошибка
   INVALID_LEXEME, если текущая лексема является открывающейся скобкой, а
   следующая лексема (i+1 порядка) является закрывающейся скобкой

    - РЕЗУЛЬТАТ: -
*/
void validate_numbers_and_functions(lexeme_t *lexemes, int lexeme_count,
                                    result_t *result) {
  if (is_function(lexemes[lexeme_count - 1].token)) {
    result->result_code = INVALID_LEXEME;
  } else {
    for (int i = 0; i < lexeme_count - 1; i++) {
      if (is_number(lexemes[i].token) &&
          (is_number(lexemes[i + 1].token) ||
           is_unary_operator(lexemes[i + 1].token) ||
           is_function(lexemes[i + 1].token))) {
        result->result_code = INVALID_LEXEME;
        break;
      } else if (is_function(lexemes[i].token) &&
                 (lexemes[i + 1].token != BRACKET_OPEN ||
                  (i > 0 && lexemes[i - 1].token == BRACKET_CLOSE))) {
        result->result_code = INVALID_LEXEME;
        break;
      } else if (lexemes[i].token == BRACKET_OPEN &&
                 lexemes[i + 1].token == BRACKET_CLOSE) {
        result->result_code = INVALID_LEXEME;
        break;
      }
    }
  }
}
