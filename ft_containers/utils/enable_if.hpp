#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

// 복습 요망
namespace ft {
    //  false
    template<bool Cond, class T = void>
    struct enable_if {};

    // true
    template<class T>
    struct enable_if<true, T> { typedef T type; };
}

#endif
