//
// Created by Yeshin Lee on 2022/03/19.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

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

        /*
         * (constructor)
        Construct vector (public member function )
        (destructor)
        vector destructor (public member function )
        operator=
                Assign content (public member function )
        */
        explicit vector(const allocator_type& alloc = allocator_type()) {
           Alloc _alloc;
           size_type _n;
           T _val;
           iterator _first;
           iterator _last;
           vector<T, Alloc> x;
           T il;
        };
        vector(const vector& x);
        vector& operator=(const vector& vector);
        ~vector();


        /*
         * Iterators
         */

        iterator begin() {
            return _first;
        }
        iterator end() {
            return _last;
        }
        reverse_iterator rbegin() {
            return reverse_iterator(end());
        }
        reverse_iterator rend() {
            return reverse_iterator(begin());
        }
/*
        Capacity:
        size
        Return size (public member function )
        max_size
        Return maximum size (public member function )
        resize
        Change size (public member function )
        capacity
        Return size of allocated storage capacity (public member function )
        empty
        Test whether vector is empty (public member function )
        reserve
        Request a change in capacity (public member function )
        shrink_to_fit
        Shrink to fit (public member function )

        Element access:
        operator[]
        Access element (public member function )
        at
        Access element (public member function )
        front
        Access first element (public member function )
        back
        Access last element (public member function )
        data
        Access data (public member function )

        Modifiers:
        assign
        Assign vector content (public member function )
        push_back
        Add element at the end (public member function )
        pop_back
        Delete last element (public member function )
        insert
        Insert elements (public member function )
        erase
        Erase elements (public member function )
        swap
        Swap content (public member function )
        clear
        Clear content (public member function )
        emplace
        Construct and insert element (public member function )
        emplace_back
        Construct and insert element at the end (public member function )

        Allocator:
        get_allocator
        Get allocator (public member function )

        Non-member function overloads
        relational operators
        Relational operators for vector (function template )
        swap
        Exchange contents of vectors (function template )

        Template specializations
        vector<bool>
        vector of bool (class template specialization )
                */

        }
    };
}



#endif
