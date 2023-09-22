#include "calculator.h"

/*
    convert_input_str

    - ЧТО ДЕЛАЕТ: распознаем все лексемы в массиве input_str и заполняем
   структуры lexemes

    - ПАРАМЕТРЫ:
        1. введенный в консоль массив
        2. структура lexemes

    - ПОРЯДОК РАБОТЫ:
        1. В цикле пропускаем игнорируем символы, являющиеся пробелами, и
   выполняем функцию convert_string_to_lexeme (записываем значение символа в
   структуру lexemes) с увеличением счетчика lexeme_count (количествао лексем в
   массиве)
        2. Выполняем функцию check_unary_operations (проверяем, является ли
   лексема унарным оператором)
        3. Выполняем функцию set_priority (указываем приоритетность операции)

    - РЕЗУЛЬТАТ: количество лексем в массиве
*/
int convert_input_str(const char *input_str, lexeme_t *lexemes) {
  int lexeme_count = 0;

  while (*input_str) {
    if (*input_str == ' ') {
      input_str++;
      continue;
    }

    convert_string_to_lexeme(&input_str, lexemes + lexeme_count);
    lexeme_count++;
  }

  check_unary_operations(lexemes, lexeme_count);
  set_priority(lexemes, lexeme_count);

  return lexeme_count;
}

/*
    convert_string_to_lexeme

    - ЧТО ДЕЛАЕТ:

    - ПАРАМЕТРЫ:
        1. указатель на индекс массива, введенного в консоль
        2. структура lexemes, которая относится к определенной лексеме

    - ПОРЯДОК РАБОТЫ:
        1. Если текущий элемент в массиве является либо точкой, либо числом, то:
          - в структуру lexeme --> элемент token записывается тип NUMBER
          - в структуру lexeme --> number position записывается значение (long
   double ) числа с помощью библиотечной функции strtold
        2. Если в п.1 структура lexeme --> элемент token не изменялся, то
   выполняется функция check_function (проверяем, является ли лексема
   математической функцией)
        3. Если в п.1 и п.2 структура lexeme --> элемент token не изменялся, то
   выполняется функция check_operation (проверяем, является ли лексема
   оператором)
        4. Если в п.1, п.2, п.3 структура lexeme --> элемент token не изменялся,
   то в данный элемент записывается тип X_VAR и индекс массива input_str
   увеличивается на 1

    - РЕЗУЛЬТАТ: -
*/
void convert_string_to_lexeme(const char **input_str, lexeme_t *lexeme) {
  lexeme->token = -1;

  if (**input_str == '.' || (**input_str >= '0' && **input_str <= '9')) {
    lexeme->token = NUMBER;
    lexeme->number = strtold(*input_str, (char **)input_str);
  }

  if (lexeme->token == -1) lexeme->token = check_function(input_str);

  if (lexeme->token == -1) lexeme->token = check_operation(input_str);

  if (lexeme->token == -1) {
    lexeme->token = X_VAR;
    *input_str += 1;
  }
}

/*
    set_priority

    - ЧТО ДЕЛАЕТ: расстановка приоритетов операций в массиве лексем

    - ПАРАМЕТРЫ:
        1. структура lexemes
        2. количество лексем в массиве

    - ПОРЯДОК РАБОТЫ:
        1. В структуру lexeme --> элемент priority записывается номер
   приоритета:
          - (1) для унарных операторов
          - (2) для оператора возведения в степень
          - (3) для операторов умножения/деления/взятия остатка
          - (4) для остальных лексем

    - РЕЗУЛЬТАТ: -
*/
void set_priority(lexeme_t *lexemes, int lexeme_count) {
  for (int i = 0; i < lexeme_count; i++) {
    if (is_unary_operator(lexemes[i].token)) {
      lexemes[i].priority = 1;
    } else if (lexemes[i].token == POW) {
      lexemes[i].priority = 2;
    } else if (lexemes[i].token == MUL || lexemes[i].token == DIV ||
               lexemes[i].token == MOD) {
      lexemes[i].priority = 3;
    } else if (is_add_sub(lexemes[i].token)) {
      lexemes[i].priority = 4;
    }
  }
}
