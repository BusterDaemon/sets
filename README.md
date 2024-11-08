# LibSets
## Библиотека для работы со множествами на языке C

Данная библитоека позволяет работать с математическими множествами на языке C и
предоставляет массу возможностей для этого.
Эта библиотека предоставляет эффективные и гибкие инструменты для создания, манипулирования и анализа множеств целых чисел. 
Она разработана с упором на удобство и простоту использования, предоставляя разработчикам удобный интерфейс для реализации сложных алгоритмов, связанных с множествами.
В данном документе вы найдете подробное описание функций библиотеки "LibSets", включая примеры использования и пояснения к каждому методу.
Мы рассмотрим создание множеств, операции над множествами (объединение, пересечение, разность, симметрическая разность), проверку принадлежности элементов, итерацию по элементам множества и так далее.

Общие сведения:
Множество – математический объект, который является совокупностью (т.е.
объединением в одно целое) некоторого количества определенных, вполне
различимых реальных или абстрактных объектов.
Объекты, которые составляют множества называются элементами
множеств.
Каждый объект может служить лишь одним
элементом множества т.е. все элементы
одного и того же множества отличны друг от друга.
Наработки методических указаний: 


### Методические указания по написанию кода для работы с множествами на языке C

Следуя методическим указаниям вам нужно написать код для работы с множествами на языке C.  Фрагмент реализует односвязный динамический список для представления множества.
#### 1.  Понимание структуры данных:

Предоставленный код использует структуру `SetElem` для представления множества:

```c
typedef struct SetElem {
  int64_t num;
  struct SetElem *next;
} SetElem;
```

Каждый элемент `SetElem` хранит число (`num`) и указатель на следующий элемент (`next`).  Множество представлено как односвязный список, где первый элемент списка является "головой" множества.

#### 2.  Изучение предоставленных функций:

`New(int64_t num)`: Создает новое множество, содержащее только один элемент со значением `num`.
`NewEmpty(void)`: Создает пустое множество.
`Push(SetElem **tail, int64_t num)`: Добавляет новый элемент `num` в начало множества (в начало списка).
`Pop(SetElem **tail)`: Удаляет первый элемент множества. Обратите внимание, что функция модифицирует указатель `tail`.

#### 3.  Основные операции над множествами:

1. Создание нового множества(New) - Создаёт множество с начальным элементом.
2. Создание пустого множества(NewEmpty) - Создаёт множество без элементов.
3. Добавление нового элемента(Push) - Добавляет указанный элемент в существующее множество.
4. Удаление первого элемента(Pop) - Удаляет указанный элемент в существующего множества.
5. Вывод множества(PrintAll) - Выводит в консоль все элементы множества.
6. Определение размера множества(Size) - Выводит количeство элементов множества.
7. Получение значений элемента(GetElem) - Выводит в консоль элемент находящийся на указанной позиции.
8. Проверка существования элемента(IsExist) - Проверяет наличие указанного элемента в множестве.

#### 4.  Примеры использования:

##### a) Объединение:

```c
    SetElem *A = NewEmpty();
    SetElem *B = NewEmpty();
    // ...
    // Данная функция создаёт из множеств А и В множество С
    SetElem *C = Union(&A, &B);
    // ...
```

##### b) Проверка принадлежности:

```c
    // ...
    // Данная функция выполняет проверку наличия в множестве элеиента 27, в случае если он отсутствует добавляет его
    if (!IsExist(A, 27)) {
        Push(&A, 27);
    // ...
    }
```

##### c) Добавление элементов:

```c
    // ...
    //  Данная функция выполняет добавление элемента в множество
    fscanf(stdin, "%d", &data);
    Push(&A, data);
    // ...
```

##### d) удаление элементов:

```c
    // ...
    //  Данная функция выполняет удаление последнего элемента в множестве
     Pop(&A);
    // ...
```

##### e) вывод элементов:

```c
    // ...
    //  Данная функция выполняет вывод всех элементов множества в консоль
     PrintAll(&A);
    // ...
```

##### f) Получение значения выбранного элемента:
```c
    // ...
    // Получение значения 4-го элемента (нумерация с нуля)
    int x = GetElem(&A, 3);
    // ...
```

##### g)Разность множеств:

```c
    // ...
    //  Данная функция вычисляет разность двух указанных множеств и записывает её в третье множество
    C = Difference(&A, &B);
    // ...
```

##### h) Симетричная разность множеств:

```c
    // ...
    //  Данная функция вычисляет симетричную разность двух указанных множеств и записывает её в третье множество
     C = SymmetricDifference(&A, &B);
    // ...
```

##### i) Пересечения множеств:

```c
    // ...
    //  Данная функция выполняет поиск пересекающихся элементов двух указанных множеств и записывает результат в третье множество
     C = Intersection(&A, &B);
    // ...
```

##### j) Дополнение множества:
```c
    // ...
    // Функция выполняет дополнение множества в границах, указанных пользователем
    puts("Введите минимум");
    fscanf(stdin, "%d", &min);
    puts("Введите максимум");
    fscanf(stdin, "%d", &max);
    C = Complement(&А, min, max);
    // ...
```

