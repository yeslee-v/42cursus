#ifndef MAP_HPP
#define MAP_HPP

#include "utils/binary_search_tree.hpp"
#include "utils/pair.hpp"
#include "utils/make_pair.hpp"
#include "utils/bidirectional_iterator.hpp"
#include "utils/iterator_traits.hpp"
#include "utils/reverse_iterator.hpp"

// map은 pair(key: T)로 이루어져있다

namespace ft
{
template <class Key,                                  // map::key_type
          class T,                                    // map::mapped_type
          class Compare = less<Key>,                  // map::key_compare
          class Alloc = allocator<ft::pair<const Key, T>> // map::allocator_type
          >
class map
{
public:
    // member types
    typedef Key key_type;
    typedef T mapped_type;
    typedef ft::pair<const key_type, mapped_type> value_type;
    typedef Compare key_compare;
    class value_compare
    {
    public:
        key_compare comp;

        value_comp() : comp(key_compare()){};
        value_comp(Compare c) : comp(c){};
        bool operator()(const value_type &x, const value_type &y) const
        {
            return comp(x.first, y.first);
        }
    }
    typedef Alloc allocator_type;
    typedef typename Alloc::reference reference;
    typedef typename Alloc::const_reference const_reference;
    typedef typename Alloc::pointer pointer;
    typedef typename Alloc::const_pointer const_pointer;
    typedef ft::bidirectioal_iterator<value_type, value_compare, Alloc, false> iterator;
    typedef ft::bidirectioal_iterator<value_type, value_compare, Alloc, true> const_iterator;
    typedef ft::reverse_iterator<iterator> reverse_iterator;
    typedef ft::reverse_iterator<const iterator> const_reverse_iterator;
    typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
    typedef difference_type size_type;

    // 일일이 쓰기 귀찮으므로 bst_type이라는 member type을 선언해준다
    typedef Bst<value_type, value_compare, Alloc> bst_type;

    typedef typename Alloc::template rebind<bst_type>::other bst_alloc;

    // member variables
private:
    bst_type* _bst;
    allocator_type _alloc;
    key_compare _key;
    bst_alloc _ba; 

    // member function
    explicit map(const key_compare &comp = key_compare(),
                 const allocator_type &alloc = allocator_type()):_alloc(alloc), _key(comp) {
                     _bst = _ba.allocate(1);
                     _ba.construct(_bst, bst_type());
                     // rebind가 되면서 자동으로 alloc이 될 것이다
                 };
    template <class InputIterator>
    map(InputIterator first, InputIterator last,
        const key_compare &comp = key_compare(),
        const allocator_type &alloc = allocator_type()): _alloc(alloc), _key(comp) {
            // map은 하나(root)를 만들어 거기에서 뻗어나가기 때문에 1개만 완전체(할당+생성자를 넣어준다)로 만들어준다
            _bst = _ba.allocate(1);
            _ba.construct(_bst, bst_type());
            for (InputIterator itr = first; itr != last; ++itr) {
                _bst.insertNode(*itr);
            }
        };
    map(const map &x) {
        // this->_bst는 이름만 있고 형체는 없는데, x의 _bst를 받으려고 한다 => 
        _bst = _ba.allocate(1);
        _ba.construct(_bst, bst_type());

        *(this->_bst) = *(x._bst);
        this->_alloc = x._alloc;
        this->_key = x._key;
        this->_ba = x._ba;
    };

    ~map();
    map &operator=(const map &x);

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
    mapped_type &operator[](const key_type &k);

    // modifiers
    pair<iterator, bool> insert(const value_type &val);
    iterator insert(iterator position, const value_type &val);
    template <class InputIterator>
    void insert(InputIterator first, InputIterator last);
    void erase(iterator position);
    size_type erase(const key_type &k);
    void erase(iterator first, iterator last);
    void swap(map &x);
    void clear();

    // observers
    key_compare key_comp() const;
    value_compare value_comp() const;

    // operations
    iterator find(const key_type &k);
    const_iterator find(const key_type &k) const;
    size_type count(const key_type &k) const;
    iterator lower_bound(const key_type &k);
    const_iterator lower_bound(const key_type &k) const;

    iterator upper_bound(const key_type &k);
    const_iterator upper_bound(const key_type &k) const;

    pair<const_iterator, const_iterator> equal_range(const key_type &k) const;
    pair<iterator, iterator> equal_range(const key_type &k);

    // allocator
    allocator_type get_allocator() const;
}

} // namespace ft
#endif
