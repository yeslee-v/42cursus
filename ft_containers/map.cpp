//
// Created by Yeshin Lee on 2022/04/19.
//

//member type
//key_type	The first template parameter (Key)
//mapped_type	The second template parameter (T)
//value_type	pair<const key_type,mapped_type>
//key_compare	The third template parameter (Compare)	defaults to: less<key_type>
//value_compare	Nested function class to compare elements	see value_comp
//allocator_type	The fourth template parameter (Alloc)	defaults to: allocator<value_type>
//reference	allocator_type::reference	for the default allocator: value_type&
//const_reference	allocator_type::const_reference	for the default allocator: const value_type&
//pointer	allocator_type::pointer	for the default allocator: value_type*
//const_pointer	allocator_type::const_pointer	for the default allocator: const value_type*
//iterator	a bidirectional iterator to value_type	convertible to const_iterator
//const_iterator	a bidirectional iterator to const value_type
//reverse_iterator	reverse_iterator<iterator>
//const_reverse_iterator	reverse_iterator<const_iterator>
//difference_type	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
//size_type	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

//Member functions
//(constructor)
//Construct map (public member function )
//(destructor)
//Map destructor (public member function )
//operator=
//        Copy container content (public member function )
//
//        Iterators:
//        begin
//        Return iterator to beginning (public member function )
//        end
//        Return iterator to end (public member function )
//        rbegin
//        Return reverse iterator to reverse beginning (public member function )
//        rend
//        Return reverse iterator to reverse end (public member function )
//        cbegin
//        Return const_iterator to beginning (public member function )
//        cend
//        Return const_iterator to end (public member function )
//        crbegin
//        Return const_reverse_iterator to reverse beginning (public member function )
//        crend
//        Return const_reverse_iterator to reverse end (public member function )
//
//        Capacity:
//        empty
//        Test whether container is empty (public member function )
//        size
//        Return container size (public member function )
//        max_size
//        Return maximum size (public member function )
//
//        Element access:
//        operator[]
//        Access element (public member function )
//        at
//        Access element (public member function )
//
//        Modifiers:
//        insert
//        Insert elements (public member function )
//        erase
//        Erase elements (public member function )
//        swap
//        Swap content (public member function )
//        clear
//        Clear content (public member function )
//        emplace
//        Construct and insert element (public member function )
//        emplace_hint
//        Construct and insert element with hint (public member function )
//
//        Observers:
//        key_comp
//        Return key comparison object (public member function )
//        value_comp
//        Return value comparison object (public member function )
//
//        Operations:
//        find
//        Get iterator to element (public member function )
//        count
//        Count elements with a specific key (public member function )
//        lower_bound
//        Return iterator to lower bound (public member function )
//        upper_bound
//        Return iterator to upper bound (public member function )
//        equal_range
//        Get range of equal elements (public member function )
//
//        Allocator:
//        get_allocator
//        Get allocator (public member function )