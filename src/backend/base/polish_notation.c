#include "calculator.h"

/*
    revers_polish_notation

    - ЧТО ДЕЛАЕТ: реализация алгоритма Дейкстры - перевод массива лексем
   (lexemes) в массив элементов в формате обратной польской нотации (polish)

    - ПАРАМЕТРЫ:
        1. структура lexemes
        2. количество лексем в массиве
        3. структура polish

    - ПОРЯДОК РАБОТЫ:
        1. Инициализация переменных:
          - buff: вспомогательный массив структур (стек)
          - buff_count: счетчик элементов вспомогательного массива структур
   (buff)
          - polish_count: счетчик элементов массива элементов в формате обратной
   польской нотации (polish)
        Далее происходит реализация алгоритма Дейкстры.
        2. Если лексема является числом, то записываем в структуру polish её
   значение
        3. Если лексема является функцией или открывающейся скобкой, записываем
   в структуру buff её значение
        4. Если лексема является оператором или унарным оператором, то
   инициируется цикл со следующими параметрами:
          - в стеке имеются элементы (переменная buff_count > 0)
          - элемент в стеке с индексом i-1 является оператором либо унарным
   оператором
          - приоритет элемента в стеке с индексом i-1 не выше приоритета
   текущего элемента (индекс i) в массиве лексем
   , в котором записываем в структуру polish значение структуры buff с индексом
   i-1. В завершении записываем в структуру buff (индекс i) текущее значение
   структуры лексем.
        5. Если лексема является закрывающейся скобкой, то
   инициируется цикл со следующими параметрами:
          - элемент в стеке с индексом i-1 не является открывающейся скобкой
    , в котором записываем в структуру polish значение структуры buff с индексом
   i-1. Далее уменьшаем счетчик buff_count на 1. Если элемент структуры buff с
   индексом i-1 является функцией, то записываем в структуру polish значение
   структуры buff с индексом i-1
        6. Оставшиеся элементы (операторы) в стеке записываем в структуру polish
   (со старшего индекса до нулевого).

    - РЕЗУЛЬТАТ: количество элементов в массиве элементов в формате обратной
   польской нотации
*/
int revers_polish_notation(lexeme_t *lexemes, int lexeme_count,
                           lexeme_t *polish) {
  lexeme_t buff[BUFF_SIZE] = {0};
  int buff_count = 0;
  int polish_count = 0;

  for (int i = 0; i < lexeme_count; i++) {
    int token = lexemes[i].token;

    if (is_number(token)) {
      polish[polish_count++] = lexemes[i];

    } else if (is_function(token) || token == BRACKET_OPEN) {
      buff[buff_count++] = lexemes[i];

    } else if (is_operator(token) || is_unary_operator(token)) {
      while (buff_count > 0 &&
             (is_operator(buff[buff_count - 1].token) ||
              is_unary_operator(buff[buff_count - 1].token)) &&
             buff[buff_count - 1].priority <= lexemes[i].priority) {
        polish[polish_count++] = buff[--buff_count];
      }
      buff[buff_count++] = lexemes[i];

    } else if (token == BRACKET_CLOSE) {
      while (buff[buff_count - 1].token != BRACKET_OPEN) {
        polish[polish_count++] = buff[--buff_count];
      }
      buff_count--;
      if (buff_count && is_function(buff[buff_count - 1].token)) {
        polish[polish_count++] = buff[--buff_count];
      }
    }
  }
  while (buff_count > 0) {
    polish[polish_count++] = buff[--buff_count];
  }

  return polish_count;
}
