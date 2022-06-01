#ifndef MAP_HPP
# define MAP_HPP

// map은 pair(key: T)로 이루어져있다

namespace ft {
	template < class Key,                                     // map::key_type
			   class T,                                       // map::mapped_type
			   class Compare = less<Key>,                     // map::key_compare
			   class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
			   > class map;

// member function
explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type());
template <class InputIterator>
  map (InputIterator first, InputIterator last,
       const key_compare& comp = key_compare(),
       const allocator_type& alloc = allocator_type());
map (const map& x);

~map();
map& operator= (const map& x);

// iterators
      iterator begin();
const_iterator begin() const;

      iterator end();
const_iterator end() const;

      reverse_iterator rbegin();
const_reverse_iterator rbegin() const;

      reverse_iterator rend();
const_reverse_iterator rend() const;

// capacity
bool empty() const;
size_type size() const;
size_type max_size() const;

// element access
mapped_type& operator[] (const key_type& k);

// modifiers
pair<iterator,bool> insert (const value_type& val);
iterator insert (iterator position, const value_type& val);
template <class InputIterator>
void insert (InputIterator first, InputIterator last);
void erase (iterator position);
size_type erase (const key_type& k);
void erase (iterator first, iterator last);
void swap (map& x);
void clear();

// observers
key_compare key_comp() const;
value_compare value_comp() const;

// operations
iterator find (const key_type& k);
const_iterator find (const key_type& k) const;
size_type count (const key_type& k) const;
      iterator lower_bound (const key_type& k);
const_iterator lower_bound (const key_type& k) const;

      iterator upper_bound (const key_type& k);
const_iterator upper_bound (const key_type& k) const;

pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
pair<iterator,iterator>             equal_range (const key_type& k);

// allocator
allocator_type get_allocator() const;

}
#endif
