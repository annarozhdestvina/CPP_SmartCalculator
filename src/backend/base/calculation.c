#include "calculator.h"

/*
    calculate

    - ЧТО ДЕЛАЕТ: вычисляет итоговое значение

    - ПАРАМЕТРЫ:
        1. структура polish
        2. количество элементов в массиве польской нотации
        3. структура result --> элемент result_code

    - ПОРЯДОК РАБОТЫ:
        1. Инициализация (long double) массива buff: вспомогательный массив для
   подсчета итогового результата (накопительным итогом). Нулевой элемент массива
   соотвествует значению структура polish --> элемент number Далее в цикле
   рассматривается массив элементов в формате обратной польской нотации начиная
   с 1 элемента
        2. Если текущий элемент является числом или Х-переменной, то в массив
   buff записывается значение структуры polish --> элемент number
        3. Если текущий элемент является унарным минусом, то предыдущее значение
   (индекс i-1) в массиве buff умножается на -1
        4. Если текущий элемент является функцией, то предыдущее значение
   (индекс i-1) в массиве buff передается в функцию run_function (производятся
   вычисления математической функции посредством стандартной библиотеки). В
   значение с данным индексом в массиве buff записывается результат. Если
   вычисление вернулось с ошибкой, то происходит выход из цикла.
        5. Если текущий элемент является оператором, то предшествующее
   предыдущему и предыдущее значения (индексы i-2 и i-1 соответственно) в
   массиве buff передаются в функцию run_operation (производятся вычисления с
   операторами, в т.ч. посредством стандартной библиотеки). Если вычисление
   вернулось с ошибкой, то происходит выход из цикла. В случае отсутствия ошибки
   текущий индекс массива buff уменьшается на 1

        В результате работы цикла значение элемента со старшим индексом будет
   являться итоговым результатом калькуляции

    - РЕЗУЛЬТАТ: итоговое значение
*/
long double calculate(lexeme_t *polish, int polish_count, int *code) {
  *code = OK;
  long double buff[BUFF_SIZE / 2] = {0};

  buff[0] = polish[0].number;
  int idx = 1;
  for (int i = 1; i < polish_count; i++) {
    if (polish[i].token == NUMBER || polish[i].token == X_VAR) {
      buff[idx] = polish[i].number;
      idx++;
    } else if (polish[i].token == UNARY_MINUS) {
      buff[idx - 1] *= -1;
    } else if (is_function(polish[i].token)) {
      buff[idx - 1] = run_function(polish[i].token, buff[idx - 1], code);
      if (*code == DIV_ZERO || *code == NEGATIVE_ROOT ||
          *code == NEGATIVE_LOG_LN)
        break;
    } else if (is_operator(polish[i].token)) {
      buff[idx - 2] =
          run_operation(polish[i].token, buff[idx - 2], buff[idx - 1], code);
      if (*code == DIV_ZERO) break;
      idx--;
    }
  }
  return buff[idx - 1];
}

/*
    run_function

    - ЧТО ДЕЛАЕТ: производятся вычисления математической функции посредством
   стандартной библиотеки

    - ПАРАМЕТРЫ:
        1. структура polish --> элемент token
        2. структура polish --> элемент number
        3. структура result --> элемент result_code

    - ПОРЯДОК РАБОТЫ:
        1. В функцию подается значение параметра математической функции. Через
   switch case с параметром структура polish --> элемент token испозьзуется
   математическая функция из стандартной библиотеки <math.h>. Результат
   записывается в (long double) переменную result
        2. Обработка ошибок в математических функциях:
          - тангенс: если результат вычисления косинуса с параметром var ~= 0,
   то в структуру result --> элемент result_code записывается ошибка DIV_ZERO
          - логарифм: если параметр var < 0,
   то в структуру result --> элемент result_code записывается ошибка
   NEGATIVE_LOG_LN
          - квадратный корень: если параметр var < 0,
   то в структуру result --> элемент result_code записывается ошибка
   NEGATIVE_ROOT

    - РЕЗУЛЬТАТ: результат вычисления математической функции
*/
long double run_function(int token, long double var, int *code) {
  long double result = 0.0;
  switch (token) {
    case SIN:
      result = sinl(var);
      break;
    case ASIN:
      result = asinl(var);
      break;
    case COS:
      result = cosl(var);
      break;
    case ACOS:
      result = acosl(var);
      break;
    case TAN: {
      if (fabsl(cosl(var)) < 1E-8) {
        *code = DIV_ZERO;
      } else {
        result = tanl(var);
      }
      break;
    }
    case ATAN:
      result = atanl(var);
      break;
    case LOG: {
      if (var < 0) {
        *code = NEGATIVE_LOG_LN;
      } else {
        result = log10l(var);
      }
      break;
    }
    case LN: {
      if (var < 0) {
        *code = NEGATIVE_LOG_LN;
      } else {
        result = logl(var);
      }
      break;
    }
    case SQRT: {
      if (var < 0) {
        *code = NEGATIVE_ROOT;
      } else {
        result = sqrtl(var);
      }
      break;
    }
  }
  return result;
}

/*
    run_operation

    - ЧТО ДЕЛАЕТ: производятся вычисления с операторами, в т.ч. посредством
   стандартной библиотеки

    - ПАРАМЕТРЫ:
        1. структура polish --> элемент token
        2. структура polish --> элемент number с индексом i-2
        3. структура result --> элемент number с индексом i-1
        4. структура result --> элемент result_code

    - ПОРЯДОК РАБОТЫ:
        1. В функции возведения в степень и взятия остатка подается значение
   параметров математической функции. Через switch case с параметром структура
   polish --> элемент token испозьзуется либо оператор, либо математическая
   функция из стандартной библиотеки <math.h>. Результат записывается в (long
   double) переменную result
        2. Обработка ошибок в математических функциях:
          - деление: если параметр var_b = 0,
   то в структуру result --> элемент result_code записывается ошибка
   DIV_ZERO

    - РЕЗУЛЬТАТ: результат вычисления, в т.ч. с использованием математической
   функции
*/
long double run_operation(int token, long double var_a, long double var_b,
                          int *code) {
  *code = OK;
  long double result = 0.0;

  switch (token) {
    case PLUS:
      result = var_a + var_b;
      break;
    case MINUS:
      result = var_a - var_b;
      break;
    case MUL:
      result = var_a * var_b;
      break;
    case DIV: {
      if (fabsl(var_b) < 1E-8) {
        *code = DIV_ZERO;
      } else {
        result = var_a / var_b;
      }
      break;
    }
    case POW:
      result = powl(var_a, var_b);
      break;
    case MOD:
      result = fmodl(var_a, var_b);
      break;
  }

  return result;
}
