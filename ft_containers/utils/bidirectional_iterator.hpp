#ifndef BIDIRECTIOAL_ITERATOR_HPP
# define BIDIRECTIOAL_ITERATOR_HPP

#include "../map.hpp"

#include "type_select.hpp"
#include "iterator_traits.hpp"

namespace ft {
    template<class T, class value_compare, class Alloc, bool is_const>
    class bidirectional_iterator {
    public:
        typedef T                                                                           value_type;
        typedef ptrdiff_t                                                                   difference_type;
        typedef value_compare                                                               comp;
        typedef Alloc                                                                       allocator_type;
        typedef typename ft::typeSelector<value_type*, const value_type*, is_const>::type   pointer;
        typedef typename ft::typeSelector<value_type&, const value_type&, is_const>::type   reference;
        typedef typename ft::bidirectional_iterator_tag                                     iterator_category;
        typedef typename ft::Bst<T, comp, Alloc>::Node                                      Node;

        bidirectional_iterator() {};
        bidirectional_iterator(Node* node, Node* null_node): _node(node), _null_node(null_node) {};
        bidirectional_iterator(bidirectional_iterator<value_type, comp, allocator_type, false> const& bi) { _node = bi.get_node(); _null_node = bi.get_null_node(); }; // 인자는 무조건 iterator가 되어야 한다, const가 들어갈 수 없음
        bidirectional_iterator& operator=(bidirectional_iterator const& bi) { _node = bi._node; _null_node = bi._null_node; return *this; }
        ~bidirectional_iterator() {};

        Node* get_node() const { return _node; };
        Node* get_null_node() const { return _null_node; };

        bool operator==(bidirectional_iterator<value_type, comp, allocator_type, true> const& bi) { return _node == bi.get_node(); } // iterator - const iterator, const iterator - const iterator
        bool operator==(bidirectional_iterator<value_type, comp, allocator_type, false> const& bi) { return _node == bi.get_node(); } // iterator - iterator, const iterator - iterator

        bool operator!=(bidirectional_iterator<value_type, comp, allocator_type, true> const& bi) { return _node != bi.get_node(); }
        bool operator!=(bidirectional_iterator<value_type, comp, allocator_type, false> const& bi) { return _node != bi.get_node(); }

        // pair 반환
        reference operator*() const { return _node->value; };
        pointer operator->() const { return &(operator*()); };

        bidirectional_iterator& operator++() {
            // 오른쪽 노드가 있다면 오른쪽으로 한 칸 이동
            if (_node->rnode != _null_node) {
                _node = _node->rnode;
                // 왼쪽 노드가 있다면 왼쪽 노드 최남단으로 이동
                while (_node->lnode != _null_node)
                    _node = _node->lnode;
            }
            // 오른쪽 노드가 존재하지 않는 경우
            else {
                // 현재 내 노드가 부모의 오른쪽 노드가 아닐 때까지
                while (_node->parent && _node == _node->parent->rnode) {
                    _node = _node->parent;         
                }
                // 어차피 lnode이기 때문에 parent로 쓴다
                _node = _node->parent;
            }
            // 순회는 end()에서 끝나기 때문에 노드가 NULL이라면 null_node(end()인지 구분하는 인자)로 바꿔준다
            if (_node == NULL)
                _node = _null_node;
            return *this;
        };
        
        bidirectional_iterator operator++(int) { bidirectional_iterator tmp(*this); ++(*this); return tmp; }; // *a++;

        bidirectional_iterator& operator--() {
            if (_node == _null_node) {
               while (_node->rnode != _null_node)
                   _node = _node->rnode;
            }
            // 큰 값에서 작은 값으로 이동한다
            else if (_node->lnode != _null_node) {
                _node = _node->lnode;
                while (_node->rnode != _null_node)
                    _node = _node->rnode;
            }
            else {
                while (_node->parent && _node == _node->parent->lnode) {
                    _node = _node->parent;
                }
                _node = _node->parent;
            }
            // begin의 전(parent)을 보기 때문에 NULL을 반환한다
            return (*this);
        };

        bidirectional_iterator operator--(int) { bidirectional_iterator tmp(*this); --(*this); return tmp; };

    private:
        Node* _node;
        Node* _null_node;
    };
}

#endif
