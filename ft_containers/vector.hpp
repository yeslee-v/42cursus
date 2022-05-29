//
// Created by Yeshin Lee on 2022/03/19.
//

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <stdexcept>

#include "utils/equal_lexicographical_compare.hpp"

namespace ft {
    template < typename T, typename Alloc = std::allocator<T> >
            class vector {
            public:
                typedef T                                       value_type;
                typedef Alloc                                   allocator_type;
                typedef Alloc::reference                        reference;
                typedef Alloc::const_reference                  const_reference;
                typedef Alloc::pointer	                        pointer;
                typedef Alloc::const_pointer	                const_pointer;
                typedef ft::random_access_iterator<T, false>    iterator;
                typedef ft::random_access_iterator<T, true>     const_iterator;
                typedef ft::reverse_iterator<iterator>          reverse_iterator;
                typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;
                typedef ptrdiff_t                               difference_type;
                typedef size_t                                  size_type;

            private:
                allocator_type  _alloc;
                size_type       _n; // size
                size_type       _cap; // total size
                value_type*     _val;

            public:
                explicit vector(const allocator_type& alloc = allocator_type())
                : _alloc(alloc), _n(0), _cap(0) {
                };

                explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
                : _alloc(alloc), _n(n), _cap(n) {
                    _val = alloc.allocate(_cap);
                    while (n--) {
                        _alloc.construct(&_val[n], val);
                    }
                };

                template <class InputIterator>
                vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
                    : _alloc(alloc) {
                    // n = 0, cap = 0;
                    // 사이즈를 먼저 할당한다
                    
                    _n = 0;
                    for (InputIterator itr = first; itr != last; itr++)
                        _n++;
                    _cap = _n; 
                    _val = alloc.allocate(_cap);
                    
                    int n = 0;
                    while (first != last){
                        _val[n++] = *first;
                        first++;
                    }
                };

                vector(const vector& x) {
                    *this = x;
                };

                vector& operator=(const vector& x) {
                    clear();
                    _alloc.deallocate(_val, _cap);
                    _alloc = x._alloc;
                    _n = x._n;
                    _cap = x._n; // _cap만큼이 아닌 _n만큼만 복사한다.
                    _val = _alloc.allocate(_cap);
                    while (n--)
                        _alloc.construct(&_val[n], x._val[n]);
                };

                ~vector() {
                    clear();
                    _alloc.deallocate(_val, _cap);
                };


                /*
                 * Iterators
                 */
                iterator begin() {
                    return iterator(_val);
                }
                const_iterator begin() const {
                    return const_iterator(_val);
                }

                iterator end() {
                    return iterator(&_val[_n]);
                }
                const_iterator end() const {
                    return const_iterator(&_val[_n]);
                }

                reverse_iterator rbegin() {
                    return reverse_iterator(end());
                }
                const_reverse_iterator rbegin() const {
                    return const_reverse_iterator(end());
                }

                reverse_iterator rend() {
                    return reverse_iterator(begin());
                }
                const_reverse_iterator rend() const {
                    return const_reverse_iterator(begin());
                }

                /*
                 * Capacity
                 */
                size_type size() const {
                    return _n;
                }

                size_type max_size() const {
                    return _alloc.max_size();
                }

                void resize(size_type n, value_type val = value_type()) {
                    if (max_size() < n)
                        throw (std::length_error("vector::resize"))
                    else if (n < _n) { // resize될 값이 더 작은 경우
                        while (_n - n)
                            _alloc.destroy(&_val[--_n]);
                    }
                    else if (_cap < n) { // total size가 resize 될 값보다 작은 경우
                        size_type i = _n;
                        value_type* tmp = _alloc.allocate(n);

                        while (i--)
                            _alloc.construct(&tmp[i], _val[i]);
                        clear(); // element 하나씩 소멸자 호출
                        _alloc.deallocate(_val, _cap);
                        _val = tmp;
                        while (n - _n)
                            _alloc.construct(&tmp[_n++], val);
                        _cap = n;
                    }
                    else if (_n < n) { // resize 될 값이 더 큰 경우
                        while (n - _n)
                            _alloc.construct(&_val[_n++], val);
                    }
                }

                size_type capacity() const {
                    return _cap;
                }

                bool empty() const {
                    return !_n;
                }

                void reserve(size_type n) { // capacity를 바꾼다
                    if (_cap < n) {
                        value_type* tmp = _alloc.allocate(n);

                        for (size_type i = 0; i < _n; i++)
                            _alloc.construct(&tmp[i], _val[i]);
                        clear();
                        _alloc.deallocate(_val, _cap);
                        _val = tmp;
                        _cap = n;
                    }
                }

                /*
                 * Element access
                 */
                reference operator[] (size_type n) {
                    return _val[n]; // reference == T& 라서 굳이 넣지 않아도 된다
                }

                const reference operator[] (size_type n) const {
                    return _val[n];
                }

                reference at(size_type n) {
                    if (_n < n)
                        throw std::out_of_range(std::at);
                    return _val[n];
                }

                const_reference at(size_type n) const {
                    if (_n < n)
                        throw std::out_of_range(std::at);
                    return _val[n];
                }

                reference front() {
                    return *_val;
                }

                const_reference front() const {
                    return *_val;
                }

                reference back() {
                    return _val[_n - 1];
                }

                const_reference back() const {
                    return _val[_n - 1];
                }

                /*
                 * Modifiers
                 */
                template<class InputIterator>
                void assign(InputIterator first, InputIterator last) { // 복습 요망: assign 맡기다
                    size_type size = 0;

                    for (InputIterator itr = first; itr != last; ++itr)
                        size++;
                    if (_cap < size) { // size만큼 새롭게 만든다 -> 할당을 새로 한다 -> 값은 동일하게 넣는다
                        clear();
                        _alloc.deallocate(_val, _cap);
                        _alloc.allocate(_val, size);
                        _cap = size;
                    }
                    // (size < _cap) { // 할당을 새로 하지 않는다 -> 값은 동일하게 넣는다
                    for (size_type i = 0; i < size; i++) {
                        _alloc.construct(&_val[i], *first);
                        first++;
                    }
                    _n = size;
                }

                void assign(size_type n, const value_type& val) {
                    if (_cap < n) {
                        clear();
                        _alloc.deallocate(_val, _cap);
                        _alloc.allocate(_val, n);
                        _cap = n;
                    }
                    for (size_type i = 0; i < n; ++i)
                        _alloc.construct(&_val[i], val);
                    _n = n;
                }

                void push_back(const value_type& val) {
                    if (_cap == _n) {
                        value_type* tmp;

                        _cap = (_cap) ? (_cap * 2) : 1; // cap이 0인 경우 들어갈 자리 하나를 만들어준다
                        tmp = _alloc.allocate(_cap);
                        for (size_type i = 0; i < _n; i++) {
                            _alloc.construct(&tmp[i], _val[i]);
                        }
                        clear(); // _n == 0
                        if (_cap != 1) // _cap이 1인 경우는 어차피 254 줄에서 0이었다.
                            _alloc.deallocate(_val, (_cap / 2));
                        _val = tmp;
                    }
                    _val[_n] = val;
                    _n++;
                }

                void pop_back() { // 빈배열에서 동작하려면 std안에서 자동으로 underflow 발생
                    _alloc.destroy(_val[_n - 1]);
                    _n--;
                }

                iterator insert(iterator position, const value_type& val) {
                    size_type pos = 0;

                    for (iterator it = vector.begin(); it != position; ++it)
                        pos++;
                    // 넉넉하거나 + capacity가 부족해서 추가하는 경우
                    if (_cap < _n + 1)
                        reserve(_cap * 2);
//                        resize(_n + 1, val); // 후에 position 을 까먹을 수 있음, [1, 2, 3] 의 두번째에 5을 넣었을 때 resize를 하면 [1, 2, 3, 5, 5, 5]가 된다
                    for (size_type i = _n; i > pos; i--) // 앞은 건들지 말고 position 후의 값만 이동하면 된다
                        _val[i] = _val[i - 1];
                    _val[pos] = val;
                    ++_n;
                }

                void insert(iterator position, size_type n, const value_type& val) {
                    size_type pos = 0;

                    for (iterator it = vector.begin(); it != position; ++it)
                        pos++;
                    if (_cap * 2 <= _n + n)
                        reserve(_n + n);
                    else if (_n + n < _cap * 2)
                        reserve(_cap * 2);
                    for (size_type i = _n; i > pos; i--) // 앞은 건들지 말고 position 후의 값만 이동하면 된다
//                        _val[i] = _val[i - n + 1]; // segfault 위험성
                        _val[i + n - 1] = _val[i - 1];
                    for (size_type i = pos; i < pos + n; i++)
                        _val[i] = val;
                    _n += n;
                }

                template <class InputIterator>
                void insert(iterator position, InputIterator first, InputIterator last) {
                    size_type pos = 0;
                    size_type size = 0;

                    for (iterator it = vector.begin(); it != position; ++it)
                        pos++;
                    for (InputIterator itr = first; itr != last; ++itr)
                        size++;
                    if (_cap * 2 <= _n + size)
                        reserve(_n + size);
                    else if (_n + size < _cap * 2)
                        reserve(_cap * 2);
                    for (size_type i = _n; i > pos; i--) // 앞은 건들지 말고 position 후의 값만 이동하면 된다
                        _val[i + size - 1] = _val[i - 1];
                    for (size_type i = pos; i < pos + size; i++) {
                        _val[i] = *first;
                        first++;
                    }
                    _n += size;
                }

                iterator erase(iterator position) {
                    // *itr = _val[n] >> &(*itr) = &_val[n]
                    _alloc.destroy(&(*position));
                    for (iterator i = position; i < end() - 1; i++) // 하나 지웠기 때문에 -1가 된다
                        *i = *(i + 1);
                    _n--;
                    return position; // 첫 변동이 생긴 iterator 반환
                }

                iterator erase(iterator first, iterator last) { // range(first, last)
                    int size = last - first; // random iterator는 - 연산이 가능하다

                    for (iterator itr = first; itr != last; ++itr) {
                        _alloc.destroy(&(*first));
                        first++;
                    }
                    for (iterator i = last; i < end(); i++) // 앞으로 가져올 iterator가 존재하지 않을 수 있기 때문에 last로 초기화한다
                        *(i - size) = *i; // [1, (first), , 4(last), 5] >> [1, 4, 5]로 만들기 위해서 현재 iterator에서 size를 빼줘야한다
                    _n -= size;
                }

                void swap(vector& x) {
                    allocator_type  tmp_alloc = x._alloc;
                    size_type       tmp_n = x._n;
                    size_type       tmp_cap = x._cap;
                    value_type*     tmp_val = x._val;

                    x._alloc = this->_alloc;
                    x._n = this->_n;
                    x._cap = this->_cap;
                    x._val = this->_val;

                    this->_alloc = tmp_alloc;
                    this->_n = tmp_n;
                    this->_cap = tmp_cap;
                    this->_val = tmp_val;
                }

                void clear() {
                    for (size_type i = 0; i < _n; ++i) {
                        _alloc.destroy(&(_val[i]));
                    }
                    _n = 0;
                }

                // Allocator:
                allocator_type get_allocator() const {
                    return _alloc;
                }
            }
    // Non-member function overloads
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return equal(lhs.begin(), lhs.end(), rhs.bagin());
    }

    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return !(lhs == rhs);
    }

    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return !(lhs > rhs);
    }

    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());

    }

    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return !(lhs < rhs);
    }

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
        x.swap(y);
    }
}

#endif