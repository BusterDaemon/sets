/**
 * @file libsets.h
 * @author BusterDaemon (bugsbunnygdi@pm.me)
 * @brief Определения для работы со множествами
 * @details Содержит определения структуры и функций для работы со множествами и их созданием
 * @version 0.1
 * @date 2024-09-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Структура представляющая элемент множества
 * @author BusterDaemon
 * 
 */
typedef struct Sets {
  int64_t num; /**< Значение элемента множества */
  struct Sets *next; /**< Ссылка на следующий элемент множества */
} Sets;

/**
 * @brief Создаёт новое множество с единственным элементом
 * @author BusterDaemon
 * @param num Значение первого элемента множества
 * @return Sets* Указатель на множество
 */
Sets *New(int64_t num);

/**
 * @brief Добавляет новый элемент множества
 * @author BusterDaemon
 * @param tail Указатель на множество
 * @param num Значение нового элемента
 */
void Push(Sets **tail, int64_t num);

/**
 * @brief Удаляет последний элемент из множества
 * @author BusterDaemon
 * @param tail Указатель на множество
 */
void Pop(Sets **tail);

/**
 * @brief Выводит все элементы множества
 * @author BusterDaemon
 * @param tail Указатель на множество
 */
void PrintAll(Sets **tail);