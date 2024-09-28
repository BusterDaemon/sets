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

#ifndef _LIBSETS_H
#define _LIBSETS_H
#include "libsets.h"
#endif

/**
 * @brief Создаёт новое множество с единственным элементом
 * @author BusterDaemon
 * @details Функция выделяет память под новый элемент множества,
 * записывает в него значение элемента и возвращает адрес на этот элемент.
 * Если память выделить не удалось тогда функция возвращает нулевой
 * указатель и сообщает об этом.
 * @param num Значение элемента множества
 * @return Sets* Указатель на множество/элемент множества
 */
Sets *New(int64_t num) {
  Sets *set;
  if ((set = (Sets *)malloc(sizeof(Sets))) == NULL) {
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
 * @return Sets* Указатель на множество
 */
Sets *NewEmpty(void) {
  Sets *set;
  if ((set = (Sets *)malloc(sizeof(Sets))) == NULL) {
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
void Push(Sets **tail, int64_t num) {
  if (*tail == NULL) {
    *tail = New(num);
    return;
  }

  Sets *new = New(num);

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
void Pop(Sets **tail) {
  if (*tail == NULL) {
    puts(_EMPTY_SET_MESSAGE);
    return;
  }

  Sets *current = *tail;
  Sets *prev = NULL;
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
void PrintAll(Sets **tail) {
  if (*tail == NULL) {
    puts(_EMPTY_SET_MESSAGE);
    return;
  }

  Sets *current = *tail;
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
int Size(Sets **tail) {
  int size = 0;

  Sets *current = *tail;
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
int GetElem(Sets **tail, uint position) {
  if (*tail == NULL) {
    puts(_EMPTY_SET_MESSAGE);
    return 0;
  }

  Sets *current = *tail;
  uint curpos = 0;

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
int IsExist(Sets **tail, int64_t num) {
  if (*tail == NULL) {
    puts(_EMPTY_SET_MESSAGE);
    return 0;
  }

  Sets *current = *tail;
  while (current->next != NULL) {
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
 * @param setA: указатель на множество A, из которого будут удаляться элементы, присутствующие в множестве B.
 * @param setB: указатель на множество B, элементы которого будут удалены из множества A.
 * @return int Статус существования элемента с нужным значением
 */





Sets *Difference(Sets **setA, Sets **setB) {
  if (*setA == NULL) {
    puts(_EMPTY_SET_MESSAGE);
    return NULL;
  }

  Sets *diffSet = NULL;

  Sets *currentA = *setA;

  // Проходим по всем элементам множества A
  while (currentA != NULL) {
    // Если элемент множества A отсутствует в множестве B, добавляем его в diffSet
    if (!IsExist(setB, currentA->num)) {
      Push(&diffSet, currentA->num);
    }
    currentA = currentA->next;
  }

  return diffSet;
}
