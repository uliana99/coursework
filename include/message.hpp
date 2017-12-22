//  "Copyright [2017] <MGTU IU8-33>"
//  MESSAGE.HPP

#ifndef _MESSAGE_HPP_
#define _MESSAGE_HPP_

#include <iostream>

template <typename T>
void message(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

#endif  // _MESSAGE_HPP_
