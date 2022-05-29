#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
    template <class Iterator>
    class reverse_iterator {
    public:
        typedef Iterator                                        iterator_type;
        typedef typename iterator_traits<Iterator>::iterator_category    iterator_category;
        typedef typename iterator_traits<Iterator>::value_type           value_type;
        typedef typename iterator_traits<Iterator>::difference_type      difference_type;
        typedef typename iterator_traits<Iterator>::pointer              pointer;
        typedef typename iterator_traits<Iterator>::reference            reference;

        // constructor
        reverse_iterator() {};
        explicit reverse_iterator (iterator_type it) { itr = it; };

        // 다른 template으로 들어옴, 그대로 하면 다른 template이라고 error 발생
        template <class Iter>
        reverse_iterator (const reverse_iterator<Iter>& rev_it) { itr = rev_it.base(); };

        template <class Iter>
        reverse_iterator& operator=(const reverse_iterator<Iter>& ri) { itr = ri.base(); return *this; };

        iterator_type base() const { return itr; }; // getter

        reference operator*() const { return *(itr - 1); };
        reverse_iterator operator+(difference_type n) const { return reverse_iterator(itr - n); };

        reverse_iterator& operator++() { --itr; return *this; };
        reverse_iterator operator++(int) { reverse_iterator tmp(*this); --(itr); return tmp; };

        // reference는 지역변수를 반환하지 않는다 -> 반환값에 reverse_iterator를 쓰지 않는다
        reverse_iterator& operator+=(difference_type n) { itr = itr - n; return *this; };
        reverse_iterator operator-(difference_type n) const { return reverse_iterator(itr + n); };

        reverse_iterator& operator--() { ++itr; return *this; };
        reverse_iterator operator--(int) { reverse_iterator tmp(*this); ++(itr); return tmp; };

        reverse_iterator& operator-=(difference_type n) { itr = itr + n; return *this; };

        pointer operator->() const { return &(operator*()); };

        reference operator[] (difference_type n) const { return *(itr - 1 - n); };

    private:
        iterator_type itr;

    };

    // Non-member function overloads
    template <class Iterator>
            bool operator== (const reverse_iterator<Iterator>& lhs,
                    const reverse_iterator<Iterator>& rhs) { return lhs.base() == rhs.base(); };

    template <class Iterator>
    bool operator!= (const reverse_iterator<Iterator>& lhs,
                     const reverse_iterator<Iterator>& rhs) { return lhs.base() != rhs.base(); };
    template <class Iterator>
    bool operator< (const reverse_iterator<Iterator>& lhs,
                     const reverse_iterator<Iterator>& rhs) { return lhs.base() > rhs.base(); };
    template <class Iterator>
    bool operator<= (const reverse_iterator<Iterator>& lhs,
                     const reverse_iterator<Iterator>& rhs) { return lhs.base() >= rhs.base(); };
    template <class Iterator>
    bool operator> (const reverse_iterator<Iterator>& lhs,
                     const reverse_iterator<Iterator>& rhs) { return lhs.base() < rhs.base(); };
    template <class Iterator>
    bool operator>= (const reverse_iterator<Iterator>& lhs,
                    const reverse_iterator<Iterator>& rhs) { return lhs.base() <= rhs.base(); };


    template <class Iterator>
            // n + itr
            reverse_iterator<Iterator> operator+ (
                    typename reverse_iterator<Iterator>::difference_type n,
                    const reverse_iterator<Iterator>& rev_it) { return rev_it + n; };

    template <class Iterator>
            typename reverse_iterator<Iterator>::difference_type operator- (
                    const reverse_iterator<Iterator>& lhs,
                    const reverse_iterator<Iterator>& rhs) { return rhs.base() - lhs.base(); }; // reverse라서 뒤에서 앞을 뺀다, reverse_iterator - reverse_iterator는 없기 때문에 base를 붙여준다
}

#endif
