//
// Created by Yeshin Lee on 2022/04/20.
//

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

//#include <iterator>

namespace ft {
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template <class Iterator> class iterator_traits {

    };

    template <class T> class iterator_traits<T*> {

    };

    template <class T> class iterator_traits<const T*> {

    };

}

#endif
