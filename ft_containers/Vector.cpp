//
// Created by Yeshin Lee on 2022/03/19.
//

#include "Vector.hpp"

Vector::Vector() {
}

Vector::Vector(const Vector& vector) {
    *this = vector;
}

Vector& Vector::operator=(const Vector& vector) {
    return *this;
}

Vector::~Vector() {
}

/*
value_type	The first template parameter (T)
allocator_type	The second template parameter (Alloc)	defaults to: allocator<value_type>
reference	allocator_type::reference	for the default allocator: value_type&
const_reference	allocator_type::const_reference	for the default allocator: const value_type&
pointer	allocator_type::pointer	for the default allocator: value_type*
const_pointer	allocator_type::const_pointer	for the default allocator: const value_type*
iterator	a random access iterator to value_type	convertible to const_iterator
const_iterator	a random access iterator to const value_type
reverse_iterator	reverse_iterator<iterator>
const_reverse_iterator	reverse_iterator<const_iterator>
difference_type	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
size_type	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

(constructor)
Construct vector (public member function )
(destructor)
Vector destructor (public member function )
operator=
Assign content (public member function )

Iterators:
begin
Return iterator to beginning (public member function )
end
Return iterator to end (public member function )
rbegin
Return reverse iterator to reverse beginning (public member function )
rend
Return reverse iterator to reverse end (public member function )
cbegin
Return const_iterator to beginning (public member function )
cend
Return const_iterator to end (public member function )
crbegin
Return const_reverse_iterator to reverse beginning (public member function )
crend
Return const_reverse_iterator to reverse end (public member function )

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

*/

