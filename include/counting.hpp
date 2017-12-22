//  "Copyright [2017] <MGTU IU8-33>"
//  COUNTING.HPP

/*!
    \file
    \brief count_sort
    \details В данном заголовочном файле реализован шаблонный алгоритм устойчивой сортировки COUNTING.
    \author Кошкина Ульяна
    \date 17/12/2017
*/

#ifndef _COUNTING_HPP_
#define _COUNTING_HPP_

#include <iostream>
#include <chrono>
#include <cstring>
#include "message.hpp"

/*!
Функция counting_sort.
Сортирует массив алгоритмом устойчивой сортировки COUNTING.

\param[in] arr[] - Массив, который необходимо отсортировать.
\param[in] size - Размер передаваемого массива.
\param[in] rad - Параметр для получения n-го порядка числа.
\snippet counting.cpp counting_sort_example
*/

template <typename T>
void counting_sort(T arr[], int size, int rad) {
    // Создаем временный пустой массив и заполняем его 0.
    T temp[size];
    memset(temp, 0, sizeof(temp));

    // Создаем массив для подсчета количества элементов
    // заполняем его 0.
    int count[rad], i;
    memset(count, 0, sizeof(count));

    // Подсчитываем число повторений каждого
    // значения в сортируемом массиве
    // и вносим полученное количество в массив count
    // по индексу проверяемого числа.
    for (i = 0; i < size; i++)
        ++count[arr[i]];

    // Проходим по массиву count и складываем значения
    // текущей ячейки со значением в предыдущей.
    // Для получения актуального положения элемента.
    for (i = 1; i < rad; i++)
        count[i] += count[i-1];

    // Заполняем временный массив temp, сопоставляя
    // значения сортируемого массива с индексом
    // в массиве count.
    for (i = 0; i < size; i++) {
        temp[ count[ arr[i] ] - 1 ] = arr[i];
        --count[arr[i]];
    }

    // Копируем значения из массива temp
    // в сортируемый массив.
    for (i = 0; i < size; ++i)
        arr[i] = temp[i];
}

#endif  // _COUNTING_HPP_
