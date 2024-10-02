/**
 * @file libsets.c
 * @author BusterDaemon (bugsbunnygdi@pm.me)
 * @brief Реализация библиотеки для работы со множествами
 * @details Содержит реализацию работы библиотеки для операций над
 * множествами
 * @version 0.1
 * @date 2024-09-25
 *
 * @copyright GNU Public License
 *
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "libsets.h"

/**
 * @brief Создаёт новое множество с единственным элементом
 * @author BusterDaemon
 * @details Функция выделяет память под новый элемент множества,
 * записывает в него значение элемента и возвращает адрес на этот элемент.
 * Если память выделить не удалось тогда функция возвращает нулевой
 * указатель и сообщает об этом.
 * @param num Значение элемента множества
 * @return SetElem* Указатель на множество/элемент множества
 */
SetElem *New(int64_t num) {
  SetElem *set;
  if ((set = (SetElem *)malloc(sizeof(SetElem))) == NULL) {
    puts(_ALLOCATE_SET_ERR);
    return NULL;
  }
  set->num = num;
  set->next = NULL;

  return set;
}

/**
 * @brief Создание пустого множества
 * @author BusterDaemon
 * @details Функция аналогична функции New(), однако
 * какой либо изначальный элемент здесь отсутствует, по
 * сути возвращая пустое множество.
 * @return SetElem* Указатель на множество
 */
SetElem *NewEmpty(void) {
  SetElem *set;
  if ((set = (SetElem *)malloc(sizeof(SetElem))) == NULL) {
    puts(_ALLOCATE_SET_ERR);
    return NULL;
  }

  Pop(&set);

  return set;
}

/**
 * @brief Добавление нового элемента
 * @author BusterDaemon
 * @details Добавляет новый элемент к существующему множеству.
 * Если множество оказывается пустым (не содержит элементов), тогда
 * новый элемент является указателем на это самое множество.
 * @param tail Указатель на множество
 * @param num Значение нового элемента
 */
void Push(SetElem **tail, int64_t num) {
  if (*tail == NULL) {
    *tail = New(num);
    return;
  }

  SetElem *new = New(num);

  new->next = *tail;
  *tail = new;
}

/**
 * @brief Удаляет первый элемент (голову) множества.
 * @author BusterDaemon
 * @details Удаляет голову множества, однако если множество
 * пустое тогда появляется соответствующее сообщение. В обратном
 * случае функция доходит до головы и удаляет её, делая головой
 * предыдущий элемент от удаляемого.
 * @param tail Указатель на множество
 */
void Pop(SetElem **tail) {
  if (*tail == NULL) {
    puts(_EMPTY_SET_MESSAGE);
    return;
  }

  SetElem *current = *tail;
  SetElem *prev = NULL;
  while (current->next != NULL) {
    prev = current;
    current = current->next;
  }

  free(current);
  if (prev != NULL) {
    prev->next = NULL;
    return;
  }

  *tail = NULL;
}

/**
 * @brief Вывод всего множества
 * @author BusterDaemon
 * @param tail Указатель на множество
 */
void PrintAll(SetElem **tail) {
  if (*tail == NULL) {
    puts(_EMPTY_SET_MESSAGE);
    return;
  }

  SetElem *current = *tail;
  putc('{', stdout);
  do {
    printf(" %ld", current->num);
    current = current->next;
    if (current != NULL)
      printf(", ");
  } while (current != NULL);
  printf(" }\n");
}

/**
 * @brief Определение количества элементов (размера) множества
 * @author BusterDaemon
 * @param tail Указатель на множество
 * @return int Количество элементов (размер) множества
 */
int Size(SetElem **tail) {
  int size = 0;

  SetElem *current = *tail;
  while (current != NULL) {
    size++;
    current = current->next;
  }

  return size;
}

/**
 * @brief Получение значения определенного элемента
 * @author BusterDaemon
 * @details Функция проходит по всему списку и возвращает
 * значение элемента на указанной позиции. Если множество
 * пустое то выводится соответствующее сообщение и возвращается нуль.
 * В случае если указана позиция больше размера множества возвращается
 * значение головы множества (первого добавленного элемента).
 * @param tail Указатель на множество
 * @param position Позиция элемента
 * @return int Значение элемента множества
 */
int GetElem(SetElem **tail, int position) {
  if (*tail == NULL) {
    puts(_EMPTY_SET_MESSAGE);
    return 0;
  }

  SetElem *current = *tail;
  int curpos = 0;

  while (current->next != NULL) {
    if (curpos == position || current->next == NULL)
      break;
    current = current->next;
    curpos++;
  }

  return current->num;
}

/**
 * @brief Проверяет существование элемента с указанным значением
 * @author BusterDaemon
 * @details Проходит по всему множеству и проверяет существование
 * элемента с указанным значением. Если элемент существует возвращает 1,
 * в противном случае 0. Если множество пустое возвращает 0 и соответствующее
 * сообщение.
 * @param tail Указатель на множество
 * @param num Значение существование которого проверяется
 * @return int Статус существования элемента с нужным значением
 */
int IsExist(SetElem **tail, int64_t num) {
  if (*tail == NULL) {
    puts(_EMPTY_SET_MESSAGE);
    return 0;
  }

  SetElem *current = *tail;
  while (current != NULL) {
    if (current->num == num)
      return 1;
    current = current->next;
  }

  return 0;
}

/**
 * @brief Производит операцию разности
 * @author rembov
 * @details возвращается новое множество,
 * содержащее элементы, которые присутствуют в множестве A,
 * но отсутствуют в множестве B.
 * @param setA: указатель на множество A, из которого будут удаляться элементы,
 * присутствующие в множестве B.
 * @param setB: указатель на множество B, элементы которого будут удалены из
 * множества A.
 * @return int Статус существования элемента с нужным значением
 */

SetElem *Difference(SetElem **setA, SetElem **setB) {
  if (*setA == NULL) {
    puts(_EMPTY_SET_MESSAGE);
    return NULL;
  }

  SetElem *diffSet = NULL;

  SetElem *currentA = *setA;

  // Проходим по всем элементам множества A
  while (currentA != NULL) {
    // Если элемент множества A отсутствует в множестве B, добавляем его в
    // diffSet
    if (!IsExist(setB, currentA->num)) {
      Push(&diffSet, currentA->num);
    }
    currentA = currentA->next;
  }

  return diffSet;
}

/**
 * @brief Производит операцию объединения
 * @author rembov
 * @details возвращается  новое множество,
 * содержащее все уникальные элементы из множеств A и B
 * @param setA: указатель на множество A.
 * @param setB: указатель на множество B.*@ return int Статус существования
 * элемента с нужным значением
 */
SetElem *Union(SetElem **setA, SetElem **setB) {
  SetElem *unionSet = NULL;

  SetElem *currentA = *setA;
  SetElem *currentB = *setB;

  // Добавляем все элементы множества A в unionSet
  while (currentA != NULL) {
    Push(&unionSet, currentA->num);
    currentA = currentA->next;
  }

  // Добавляем все элементы множества B в unionSet, если они не присутствуют в
  // unionSet
  while (currentB != NULL) {
    if (!IsExist(&unionSet, currentB->num)) {
      Push(&unionSet, currentB->num);
    }
    currentB = currentB->next;
  }

  return unionSet;
}

/**
 * @brief Производит операцию дополнения в промежутке множества A
 * @authors rembov
 * @authors BusterDaemon
 * @details Возвращает новое множество, содержащее элементы,
 * которые присутствуют в промежутке от минимального до максимального значения
 * множества A, но отсутствуют в самом множестве A.
 * @param setA Указатель на множество A
 * @param min Значение минимума
 * @param max Значение максимума
 * @return SetElem* Указатель на множество, содержащее дополнение множества A в его
 * промежутке
 */
SetElem *Complement(SetElem **setA, int64_t min, int64_t max) {
  if (*setA == NULL) {
    puts(_EMPTY_SET_MESSAGE);
    return NULL;
  }

  SetElem *complementSet = NewEmpty();

  // Проходим по всем значениям удовлетворяющих неравенству
  // min < x < max
  for (int64_t i = min + 1; i < max; i++) {
    // Если элемент отсутствует в множестве A, добавляем его в complementSet
    if (!IsExist(setA, i))
      Push(&complementSet, i);
  }

  return complementSet;
}

/**
 * @brief Производит операцию пересечения
 * @author rembov
 * @details Возвращает новое множество, содержащее элементы,
 * которые присутствуют одновременно в множестве A и множестве B.
 * @param setA Указатель на множество A
 * @param setB Указатель на множество B
 * @return SetElem* Указатель на множество, содержащее пересечение множеств A и B
 */
SetElem *Intersection(SetElem **setA, SetElem **setB) {
  if (*setA == NULL || *setB == NULL) {
    puts(_EMPTY_SET_MESSAGE);
    return NULL;
  }

  SetElem *intersectionSet = NULL;
  SetElem *currentA = *setA;

  // Проходим по всем элементам множества A
  while (currentA != NULL) {
    // Если элемент присутствует в множестве B, добавляем его в intersectionSet
    if (IsExist(setB, currentA->num)) {
      Push(&intersectionSet, currentA->num);
    }
    currentA = currentA->next;
  }

  return intersectionSet;
}

/**
 * @brief Производит операцию симметричной разности
 * @author rembov
 * @details Возвращает новое множество, содержащее элементы,
 * которые присутствуют в одном из множеств (A или B), но не в обоих
 * одновременно.
 * @param setA Указатель на множество A
 * @param setB Указатель на множество B
 * @return SetElem* Указатель на множество, содержащее симметричную разность
 * множеств A и B
 */
SetElem *SymmetricDifference(SetElem **setA, SetElem **setB) {
  SetElem *symDiffSet = NULL;

  // Если оба множества пусты, возвращаем NULL
  if (*setA == NULL && *setB == NULL) {
    puts(_EMPTY_SET_MESSAGE);
    return NULL;
  }

  SetElem *currentA = *setA;
  SetElem *currentB = *setB;

  // Добавляем элементы, которые присутствуют в A, но отсутствуют в B
  while (currentA != NULL) {
    if (!IsExist(setB, currentA->num)) {
      Push(&symDiffSet, currentA->num);
    }
    currentA = currentA->next;
  }

  // Добавляем элементы, которые присутствуют в B, но отсутствуют в A
  while (currentB != NULL) {
    if (!IsExist(setA, currentB->num)) {
      Push(&symDiffSet, currentB->num);
    }
    currentB = currentB->next;
  }

  return symDiffSet;
}
