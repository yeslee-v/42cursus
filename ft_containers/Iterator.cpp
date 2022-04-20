//
// Created by Yeshin Lee on 2022/04/20.
//

#include <iterator>

template <class Iterator> class iterator_traits {

};

template <class T> class iterator_traits<T*> {

};

template <class T> class iterator_traits<const T*> {

};
