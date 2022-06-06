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
    // key 비교
    typedef Compare key_compare;
    // pair 비교
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
            insert(first, last);
        };
    map(const map &x) {
        // this->_bst는 이름만 있고 형체는 없는데, x의 _bst를 받으려고 한다 => 
        _bst = _ba.allocate(1);
        _ba.construct(_bst, bst_type());

        this->_alloc = x._alloc;
        this->_key = x._key;
        this->_ba = x._ba;
        // _bst는 class이기 때문에, 여기서 bst의 operator=를 사용한다
        *(this->_bst) = *(x._bst);
    };

    ~map() { clear(); _ba.destroy(_bst); _ba.deallocate(_bst, 1); };
    map &operator=(const map &x) {
        this->_alloc = x._alloc;
        this->_key = x._key;
        this->_ba = x._ba;
        // x는 reference 이기 때문에 변수 참조, _bst는 포인터이기 때문에 포인터 참조
        // _bst는 class이기 때문에, 여기서 bst의 operator=를 사용한다
        *(this->_bst) = *(x._bst);

        return *this;
    };

    // iterators: 중위순회(lnode->root->rnode)
    // 제일 작은 노드 찾기
    iterator begin() {
        Node* node = _bst->root;
        
        while (node->lnode != _bst->null_node)
            node = node->lnode;
        return iterator(node, _bst->null_node);
    };
    const_iterator begin() const {
        Node* node = _bst->root;
        
        while (node->lnode != _bst->null_node)
            node = node->lnode;
        return const_iterator(node, _bst->null_node);
    };
    // vector의 end()처럼 마지막 다음 노드(값이 없음)를 가리키는 것이기 때문에 null_node를 보내준다
    iterator end() { return iterator(_bst->null_node, _bst->null_node); };
    const_iterator end() const { return const_iterator(_bst->null_node, _bst->null_node); };

    reverse_iterator rbegin() { return reverse_iterator(end()); };
    const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); };

    reverse_iterator rend() { return reverse_iterator(begin()); };
    const_reverse_iterator rend() const { return const_reverse_iterator(begin()); };

    // capacity
    bool empty() const { return !_bst->size; };
    size_type size() const { return bst->size; };
    size_type max_size() const { return _ba.max_size(); };

    // element access
    mapped_type &operator[](const key_type &k) {
        _bst::Node* node;

        node = _bst->searchNode(ft::pair<key_type, mapped_type>(k, mapped_type()));
        if (node)
            return node->value.second;
        // iterator는 value_type을 갖고 있다 
        return insert(begin(), ft::pair<key_type, mapped_type>(k, mapped_type()))->second;
    };

    // modifiers
    // insert 성공 여부
    ft::pair<iterator, bool> insert(const value_type &val) {
        bool is_exist = false;
        // key가 존재하지 않는 경우 -> insert 실행
        if (!_bst->searchNode(val))
            is_exist = true;
        return ft::pair<iterator, bool>(insert(_bst->begin(), val), is_exist); // _bst->begin()은 의미 없음
        // key가 존재하는 경우 -> 기존 key값 반환
    };
    iterator insert(iterator position, const value_type &val) {
        // position: 힌트, vector의 position과 다르다. position이 주어져도 val와 주변 value를 비교해 알맞는 곳에 넣어야한다
        (void)position;

        return iterator(_bst->insertNode(val), _bst->null_node);
    };
    template <class InputIterator>
    void insert(InputIterator first, InputIterator last) {
        for (InputIterator itr = first; itr != last; ++itr)
            _bst->insertNode(*itr);
    };
    void erase(iterator position) { _bst->deleteNode(*position); };
    size_type erase(const key_type &k) { return _bst->deleteNode(ft::pair<key_type, mapped_type>(k, mapped_type())); };
    void erase(iterator first, iterator last) {
        // itr를 지우게 되면 itr++로 이동하지 못하기 때문에 itr++의 값을 가지는 tmp 선언해 먼저 이동한 다음 itr을 지운다
        iterator tmp;
        
        for (iterator itr = first; itr != last; ) {
            tmp = itr;
            itr++;
            erase(tmp);
        }
    };
    void swap(map &x) {
        bst_type* bt_tmp;
        allocator_type at_tmp;
        key_compare kc_tmp;
        bst_alloc ba_tmp;

        bt_tmp = this->_bst;
        at_tmp = this->_alloc;
        kc_tmp = this->_key;
        ba_tmp = this->_ba;

        this->_bst = x._bst;
        this->_alloc = x._alloc;
        this->_key = x._key;
        this->_ba = x._ba;

        x._bst = bt_tmp;
        x._alloc = at_tmp;
        x._key = kc_tmp;
        x._ba = ba_tmp;
    };
    void clear() { _bst->clear(); };

    // observers
    key_compare key_comp() const { return _key; };
    value_compare value_comp() const { return value_compare(); };

    // operations
    iterator find(const key_type &k) {
       Node* node;

       node = _bst->searchNode(ft::pair<key_type, mapped_type>(k, mapped_type()));
       if (node)
           return iterator(node, _bst->null_node);
       return end();
    };
    const_iterator find(const key_type &k) const {
        Node* node;

        node = _bst->searchNode(ft::pair<key_type, mapped_type>(k, mapped_type());
        if (node)
            return const_iterator(node, _bst->null_node);
        return end();
    };
    // k의 존재 여부 반환 -> bool이라고 생각하 => 중복key가 있는 map이 존재하므로 통일성을 위해 count라는 이름의 method
    size_type count(const key_type &k) const {
        if (_bst->searchNode(ft::pair<key_type, mapped_type>(k, mapped_type()))
            return 1;
        return 0;
    };
    // 하한선: 값을 오름차순으로 정렬 후, k보다 크거나 같은 값을 가리키는 iterator 반환
    iterator lower_bound(const key_type &k) {
        for (iterator itr = begin(); itr != end(); ++itr) {
            if (!key_compare(itr->first, k))
                return itr;
        }
        // 못찾은 경우: [3, 5, 6] vs k = 10
        return end();
    };
    const_iterator lower_bound(const key_type &k) const {
        for (const_iterator itr = begin(); itr != end(); ++itr) {
            if (!key_compare(itr->first, k))
                return itr;
        }
        return end();
    };

    // 상한선: 값을 오름차순으로 정렬 후, k보다 작거나 같은 값을 가리키는 iterator 반환
    iterator upper_bound(const key_type &k) {
        for (iterator itr = begin(); itr != end(); ++itr) {
            if (!key_compare(k, itr->first))
                return itr;
        }
        return end();
    };
    const_iterator upper_bound(const key_type &k) const {
        for (const_iterator itr = begin(); itr != end(); ++itr) {
            if (!key_compare(k, itr->first))
                return itr;
        }
        return end();
    };
    // 범위 반환
    ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const {
        return ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
    };
    ft::pair<iterator, iterator> equal_range(const key_type &k) {
        return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
    };

    // allocator
    allocator_type get_allocator() const { return _alloc; };
}

} // namespace ft
#endif
