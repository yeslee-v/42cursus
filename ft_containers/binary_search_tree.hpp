#ifndef BINARY_SEARCH_TREE
# define BINARY_SEARCH_TREE

#include <iostream>

namespace ft {
    template < class T, class Compare, class Alloc >
    class Bst {
    private:
        class Node {
        public:
            Node* parent;
            Node* lnode;
            Node* rnode;
            T     value;

            Node(): parent(NULL), lnode(NULL), rnode(NULL), value(0) {};
            Node(T value): parent(NULL), lnode(NULL), rnode(NULL), value(value) {};
            Node(const Node& node) { *this = node; };
            Node& operator=(const Node& node) {
                this->parent = node.parent;
                this->lnode = node.lnode;
                this->rnode = node.rnode;
                this->value = node.value;

                return *this;
            };
            ~Node() {};
        };
        // allocator<Node>로 Node class 자료형으로 대체한다
        typedef typename Alloc::template rebind<Node>::other nodeAlloc;

        Node* root;
        nodeAlloc na;
        Alloc alloc;
        Compare comp;

    public:
        Bst(const Alloc& alloc = Alloc(), const Compare& comp = Compare()): root(NULL), alloc(alloc), comp(comp) {};
        ~Bst() {};

        // insert, delete, search
        // map[2] = 5처럼 값을 넣어주는 함수
        void insertNode(T value) {
            if (!root) {
                root = na.allocate(1);
                // root = Node(value) -> 자료형이 같아야 하기 때문에 Node 생성자로 value를 넣는다
                na.construct(root, Node(value));
            }
            else {
                Node* tmp = root;
                Node* prev; // tmp의 이전 노드를 가리킨다

                // node가 중간에 들어가는 경우는 없다 -> 무조건 node 끝쪽에 위치한다
                while (tmp) {
                    prev = tmp;
                    tmp = comp(tmp->value, value) ? tmp->rnode : tmp->lnode;
                }
                // 마지막으로 parent의 value와 비교하여 왼쪽에 넣을지 오른쪽에 넣을지 결정한다
                if (comp(prev->value, value)) {
                    prev->rnode = na.allocate(1);
                    na.construct(prev->rnode, Node(value));
                    prev->rnode->parent = prev;
                }
                else {
                    prev->lnode = na.allocate(1);
                    na.construct(prev->lnode, Node(value));
                    prev->lnode->parent = prev;
                }
           }
        };

        Node* searchNode(T value) {
            if (!root)
                return NULL;

            Node* tmp = root;

            while (tmp) {
                if (tmp->value == value)
                    return tmp;
                tmp = comp(tmp->value, value) ? tmp->rnode : tmp->lnode;
            }
            return NULL;
        }

        // 작은 것 중에 가장 큰 것을 먼저 확인한다
        void deleteNode(T value) {
            Node* node = searchNode(value); // 대체될 애
            Node* tmp = node; // 지워질 애

            if (node) {
                if (tmp->lnode) {
                    node = node->lnode;
                    while (node->rnode) // 최남단
                        node = node->rnode;
                    //    10            8
                    //  5        =>   5
                    //    6            6
                    //      8
                    if (node->lnode && tmp->lnode != node)
                        node->lnode->parent = node->parent;
                    if (tmp->lnode != node) {
                        node->parent->rnode = node->lnode;
                        node->lnode = tmp->lnode;
                    }
                    // 지우기 전에 지울 자리에 대체할 값을 옮긴다
                    node->parent = tmp->parent;
                    node->rnode = tmp->rnode;

                    if (tmp->parent) {
                        if (tmp->parent->lnode == tmp)
                            tmp->parent->lnode = node;
                        else
                            tmp->parent->rnode = node;
                    }
                    // node == root
                    else
                        root = node;

                    na.destroy(tmp); // 해당 node 지우기
                    na.deallocate(tmp, 1); // 지운 자리의 메모리 해제하기
                }
                else if (tmp->rnode) {
                    node = node->rnode;

                    while (node->lnode)
                        node = node->lnode;

                    // 1(tmp)         2
                    //   3(n->p) =>  3
                    // 2(node)      4
                    //   4(n->r)
                    if (node->rnode && tmp->rnode != node)
                        node->rnode->parent = node->parent;
                    if (tmp->rnode != node) {
                        node->parent->lnode = node->rnode;
                        node->rnode = tmp->rnode;
                    }
                    node->parent = tmp->parent;
                    node->lnode = tmp->lnode;
                    //    1 (tmp)          5(node)
                    //       6        =>    6
                    //  5(node) 10           10
                    if (tmp->parent) {
                        if (tmp->parent->lnode == tmp)
                            tmp->parent->lnode = node;
                        else
                            tmp->parent->rnode = node;
                    }
                    // node == root
                    else
                        root = node;

                    na.destroy(tmp); // 해당 node 지우기
                    na.deallocate(tmp, 1); // 지운 자리의 메모리 해제하기
                }
                // leaf node일 때 || root만 존재
                else {
                    if (tmp->parent) {
                        if (tmp->parent->lnode == tmp)
                            node->parent->lnode = NULL;
                        else
                            node->parent->rnode = NULL;
                    }
                    // node가 root노드 단 하나로만 존재할 때
                    else
                        root = NULL;

                    na.destroy(tmp); // 해당 node 지우기
                    na.deallocate(tmp, 1); // 지운 자리의 메모리 해제하기


                }
            }
        }

        // 중위연산
        void print() {
            print(this->root);
        }
        void print(Node* node) {
            if (!node)
                return ;
            print(node->lnode);
            std::cout << node->value << std::endl;
            print(node->rnode);
        }
    };
}

#endif
