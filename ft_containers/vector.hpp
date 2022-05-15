//
// Created by Yeshin Lee on 2022/03/19.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <stdexcept>

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
                typedef ft::random_access_iterator<T>           iterator;
                typedef ft:random_access_iterator<const T>      const_iterator;
                typedef ft::reverse_iterator<iterator>          reverse_iterator;
                typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;
                typedef ptrdiff_t                               difference_type;
                typedef size_t                                  size_type;

            private:
                allocator_type  _alloc;
                size_type       _n; // size
                size_type       _cap;
                value_type*     _val;
                value_type*     _first;
                value_type*     _last;

            public:
                explicit vector(const allocator_type& alloc = allocator_type())
                : _alloc(alloc), _n(0), _cap(0) {
                    _val = _alloc.allocate(0);
                    _first = _val;
                    _last = _val;
                };

                explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
                : _alloc(alloc), _n(n), _cap(0) {
                    while (_cap < _n) {
                        size_type new_cap = (_cap * 2 > 0) ? (_cap * 2) : 1;
                        _cap = new_cap;
                    }
                    _val = alloc.allocate(_cap);
                    _first = _val;
                    _last = _first;
                    for (n--) {
                        _alloc.construct(_last, val);
                        _last++;
                    }
                };

                template <class InputIterator> // iterator 공부하고 나서 진행해야
                        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
                        : _alloc(alloc) {
                        };

                vector(const vector& x) {
                    *this = x;
                };

                vector& operator=(const vector& vector) {
                    _alloc = vector._alloc;
                    _n = vector._n;
                    _cap = vector._cap;
                    _val = _alloc.allocate(_cap);
                    _first = _val;
                    _last = _first;
                    for (n--) {
                        _alloc.construct(_last, val);
                        _last++;
                    }
                };

                ~vector() {
                    clear();
                    _alloc.deallocate(_val, _cap);
                };


                /*
                 * Iterators
                 */
                iterator begin() {
                    return iterator(_first);
                }

                iterator end() {
                    return iterator(_last);
                }

                reverse_iterator rbegin() {
                    return reverse_iterator(end());
                }

                reverse_iterator rend() {
                    return reverse_iterator(begin());
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
                        else if (n < _n) {
                            clear();
                            for (size_type i = 0; i < n; i++)
                                _alloc.construct(_last, val);
                        }
                    else if (_n < n) {
                        while (n - _n)
                            _alloc.construct(_last, val);
                    }
                    else if (_cap < n) {
                        _alloc.deallocate(_first, _val);
                        while (n--)
                            _alloc.allocate(_first, val);
                    }
                }

                size_type capacity() const {
                    return _cap;
                }

                bool empty() const {
                    return (_n == 0) ? 1 : 0;
                }

                void reserve(size_type n) {
                    if (max_size() < n)
                        std::length_error("vector::reserve");
                    _alloc.deallocate(_first, _val);
                    for (size_type i = 0; i < n, i++)
                        _alloc.allocate(_first, i);
                }

                /*
                 * Element access
                 */
                reference operator[] (size_type n) {
                    return reference(_first + n);
                }

                const reference operator[] (size_type n) const {
                    return reference(_first + n);
                }

                reference at(size_type n) {
                    if (_cap < n)
                        throw std::out_of_range(std::at);
                    return reference(_first + n);
                }

                const_reference at(size_type n) const {
                    if (_cap < n)
                        throw std::out_of_range(std::at);
                    return reference(_first + n);
                }

                reference front() {
//                    if (_first == _last)
                        // undefined behavior
                    return _first;
                }

                const_reference front() const {
                    // if (_first == _last)
                    // undefined behavior
                    return _first;
                }

                reference back() {
                    return _last;
                }

                const_reference back() const {
                    return _last;
                }

                /*
                 * Modifiers
                 */
                template<class InputIterator>
                void assign(InputIteratorfirst, InputIterator last) {
                }

                void assign(size_type n, const value_type& val) {
                    _alloc.allocate(n);
                    for (size_type i = 0; i < n; ++i) {
                        _alloc.construct(_last, val);
                        _last++;
                    }
                }

                void push_back(const value_type& val) {
                    if (_cap < _n + 1) {
                        ~vector();
                        for (size_type i = 0; i <= _n; ++i) {
                            _alloc.allocate(_last, _val);
                        }
                    }
                    vector[_last + 1] = val; // 위치를 어떻게 잡아야하지?
                }
                void pop_back() {
                    _alloc.destroy(_last);
                    if (_first == _last) {
                        _alloc.deallocate();
                    }
                }
                iterator insert(iterator position, const value_type& val) {
                    if (_cap < _n + 1)
                        resize(_n + 1, val);
                    for (std::vector<T>::iterator it = vector.begin(); it < vector.end(); ++it) {
                        if (it == position)
                            *it = val;
                        // 뒤로 한 칸씩 미루퍄
                    }
                }
                void insert(iterator position, size_type n, const value_type& val) {

                }
                template <class InputIterator>
                        void insert(iterator position, InputIterator first, InputIterator last) {
                        }

                iterator erase(iterator posiiton) {
                }

                iterator erase(iterator first, iterator last) { // range(first, last)
                }

                void swap(vector& x) {
                    allocator_type  tmp_alloc = x._alloc;
                    size_type       tmp_n = x._n;
                    size_type       tmp_cap = x._cap;
                    value_type*     tmp_val = x._val;
                    value_type*     tmp_first = x._first;
                    value_type*     tmp_last = x._last;

                    x._alloc = this->_alloc;
                    x._n = this->_n;
                    x._cap = this->_cap;
                    x._val = this->_val;
                    x._first = this->_first;
                    x._last = this->_last;

                    this->_alloc = tmp_alloc;
                    this->_n = tmp_n;
                    this->_cap = tmp_cap;
                    this->_val = tmp_val;
                    this->_first = tmp_first;
                    this->_last = tmp_last;
                }

                void clear() {
                    for (size_type i = 0; i < _n; ++i) {
                        _last--;
                        _alloc.destroy(_last);
                    }
                    _n = 0;
                }

//        Allocator:
//        get_allocator
//        Get allocator (public member function )
//
//        Non-member function overloads
//        relational operators
//        Relational operators for vector (function template )
//        swap
//        Exchange contents of vectors (function template )
//
//        Template specializations
//        vector<bool>
//        vector of bool (class template specialization )

        }
    };
}



#endif
