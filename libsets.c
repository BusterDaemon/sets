/**
 * @file libsets.c
 * @author BusterDaemon (bugsbunnygdi@pm.me)
 * @brief Реализация библиотеки для работы со множествами
 * @details Содержит реализацию работы библиотеки для операций над
 * множествами
 * @version 0.1
 * @date 2024-09-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

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
    perror("Cannot allocate memory");
    return NULL;
  }
  set->num = num;
  set->next = NULL;

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
    perror("Set is empty");
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
    perror("Set is empty");
    return;
  }

  Sets *current = *tail;
  do {
    printf("%ld", current->num);
    current = current->next;
    if (current != NULL)
      printf(", ");
  } while (current != NULL);
  putc('\n', stdout);
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