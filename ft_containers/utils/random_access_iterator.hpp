//
// Created by Yeshin Lee on 2022/05/29.
//

#ifndef INC_42CURSUS_RANDOM_ACCESS_ITERATOR_HPP
#define INC_42CURSUS_RANDOM_ACCESS_ITERATOR_HPP

// vector에서 사용하기 위한 iterator

#include "type_select.hpp"
#include "iterator_traits.hpp"

namespace ft {
    template<class T, bool isConstItr>
    class random_access_iterator {
    public: // public은 쓸 사람이 위에서 보고 사용한다, private은 쓸 사람이 안봐도 되기 때문에 public을 위로 올린다
        typedef T                                                                           value_type;
        typedef ptrdiff_t                                                                   difference_type;
        typedef typename ft::typeSelector<*value_type, const *value_type, isConstItr>::type pointer;
        typedef typename ft::typeSelector<&value_type, const &value_type, isConstItr>::type reference;
        typedef typename random_access_iterator_tag                                         iterator_category;

        random_access_iterator() {};
        random_access_iterator(pointer ptr) { value = ptr };
        random_access_iterator(random_access_iterator<value_type, false> const& rai) { value = rai.getValue(); }; // 인자는 무조건 iterator가 되어야 한다, const가 들어갈 수 없음
        random_access_iterator& operator=(random_access_iterator const& rai) { value = rai.value; return *this; }
        ~random_access_iterator() {};

        pointer getValue() const { return value };

        // 그냥 type, const type 둘 다 비교해야하므로(경우의 수: 4개) 동일한 operator를 2개씩 구현한다
        bool operator==(random_access_iterator<value_type, true> const& rai) { return value == rai.getValue(); } // iterator - const iterator, const iterator - const iterator
        bool operator==(random_access_iterator<value_type, false> const& rai) { return value == rai.getValue(); } // iterator - iterator, const iterator - iterator

        bool operator!=(random_access_iterator<value_type, true> const& rai) { return value != rai.getValue(); }
        bool operator!=(random_access_iterator<value_type, false> const& rai) { return value != rai.getValue(); }

        // *a = t도 포함된다: 둘 다 사용하기 때문에
        // *itr = 5 >> 5가 위치한 주소를 알아내기 위해서 참조(&)해야한다
        reference operator*() const { return *value; };
        pointer operator->() const { return value; }; // 복습 요망: 왜 pointer가 반환값이냐

        random_access_iterator& operator++() { ++value; return *this; };
        random_access_iterator operator++(int) { random_access_iterator tmp(*this); ++(value); return tmp; }; // *a++;

        random_access_iterator& operator--() { --value; return *this; };
        random_access_iterator operator--(int) { random_access_iterator tmp(*this); --(value); return tmp; };

        // reference로 인자를 받으면 복사를 하지 않기 때문에 속도가 빠르다
        random_access_iterator operator+(int const& n) const { return random_access_iterator(value + n); }; // value+n만큼의 위치를 가진 iterator 반환
        random_access_iterator operator-(int const& n) const { return random_access_iterator(value - n); };

        int operator-(random_access_iterator<value_type, true> const& rai) const { return value - b.getValue(); };
        int operator-(random_access_iterator<value_type, false> const& rai) const { return value - b.getValue(); };

        bool operator<(random_access_iterator<value_type, true> const& rai) const { return value < b.getValue(); };
        bool operator<(random_access_iterator<value_type, false> const& rai) const { return value < b.getValue(); };

        bool operator>(random_access_iterator<value_type, true> const& rai) const { return value > b.getValue(); };
        bool operator>(random_access_iterator<value_type, false> const& rai) const { return value > b.getValue(); };

        bool operator<=(random_access_iterator<value_type, true> const& rai) const { return value <= b.getValue(); };
        bool operator<=(random_access_iterator<value_type, false> const& rai) const { return value <= b.getValue(); };

        bool operator>=(random_access_iterator<value_type, true> const& rai) const { return value >= b.getValue(); };
        bool operator>=(random_access_iterator<value_type, false> const& rai) const { return value >= b.getValue(); };

        // 새로운 iterator가 반환되기 떄문에 불가
//        random_access_iterator operator+=(int const& n) const { return random_access_iterator(value += n); }; value+n만큼의 위치를 가진 iterator 반환
//        random_access_iterator operator-=(int const& n) const { return random_access_iterator(value -= n); };

        random_access_iterator operator+=(int const& n) const { value + n; return *this; }; // value+n만큼의 위치를 가진 iterator 반환
        random_access_iterator operator-=(int const& n) const { value - n; return *this; };

        // random_access_iterator의 특징: 특정 위치(n)으로의 접근이 가능하다
        reference operator[](int const& n) const { return value[n]; };

    private:
        value_type *value;
    };

    template<class T, bool isConstItr>
    random_access_iterator<T, isConstItr> operator+(int const& n, random_access_iterator<T, isConstItr>& rai) const {
        return rai + n;
    };

}

#endif
