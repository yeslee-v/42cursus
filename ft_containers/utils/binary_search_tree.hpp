#ifndef BINARY_SEARCH_TREE
# define BINARY_SEARCH_TREE

#include <iostream>

namespace ft {
    template <class T, class Compare, class Alloc>
    class Bst {
    public:
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
    private:
        // allocator<Node>로 Node class 자료형으로 대체한다
        typedef typename Alloc::template rebind<Node>::other node_alloc;

        Node* root;
        Node* null_node; // leaf node가 NULL을 가리키는지 확인하는 노드(값이 NULL이다), parent(root)의 parent가 가리키는 NULL과 분리해서 구분하려는 의도
        node_alloc na;
        Alloc alloc;
        Compare comp;
        size_t size;

    public:
    // class를 선언할 때만 ;을 넣어준다
        Bst(const Alloc& alloc = Alloc(), const Compare& comp = Compare()): root(NULL), alloc(alloc), comp(comp), size(0) {
            // 생성자에서 할당하고 초기화해준다
            null_node = na.allocate(1);
            na.construct(null_node, 1);
        };
        Bst(const Bst& bst) {
            root = NULL;
            alloc = bst.alloc;
            comp = bst.comp;
            size = 0;

            null_node = na.allocate(1);
            na.construct(null_node, 1);
            
            // 전위순회를 하며 node에 값을 하나씩 넣어준다
            copy(bst.root);            
        }
        Bst& operator=(const Bst& bst) {
            if (this->root)
                clear();

            copy(bst.root);
            
            return *this;
        }
        ~Bst() {
            clear();
            // 어차피 없어지니까 root를 NULL 초기화하는 작업은 진행하지 않는다
        };

        void copy(Node* node) {
            if (!node)
                return ;
            insertNode(node->value);
            copy(node->lnode);
            copy(node->rnode);
        }

        void clear(){
            clear(this->root);
            this->size = 0;
            this->root = NULL;
        }

        void clear(Node* node) {
            if (!node || node == null_node)
                return ;
            clear(node->lnode);
            clear(node->rnode);
            na.destroy(node);
            na.deallocate(node, 1);            
        }

        

        // map[2] = 5처럼 값을 넣어주는 함수
        void insertNode(T value) {
            if (!root) {
                root = na.allocate(1);
                // root = Node(value) -> 자료형이 같아야 하기 때문에 Node 생성자로 value를 넣는다
                na.construct(root, Node(value));
                root->lnode = null_node;
                root->rnode = null_node;
            }
            else {
                Node* tmp = root;
                Node* prev; // tmp의 이전 노드를 가리킨다

                // node가 중간에 들어가는 경우는 없다 -> 무조건 node 끝쪽에 위치한다
                // tmp != NULL 변형 : null_node는 NULL을 가지고 있다
                while (tmp != null_node) {
                    prev = tmp;
                    tmp = comp(tmp->value, value) ? tmp->rnode : tmp->lnode;
                }
                // 마지막으로 parent의 value와 비교하여 왼쪽에 넣을지 오른쪽에 넣을지 결정한다
                if (comp(prev->value, value)) {
                    prev->rnode = na.allocate(1);
                    na.construct(prev->rnode, Node(value));
                    prev->rnode->parent = prev;
                    // 새로 생긴 노드의 왼쪽 오른쪽 노드에 null_node를 설정한다
                    prev->rnode->lnode = null_node;
                    prev->rnode->rnode = null_node;
                }
                else {
                    prev->lnode = na.allocate(1);
                    na.construct(prev->lnode, Node(value));
                    prev->lnode->parent = prev;
                    prev->lnode->lnode = null_node;
                    prev->lnode->rnode = null_node;
                }
            }
            size++;
        };

        Node* searchNode(T value) {
            if (!root)
                return NULL;

            Node* tmp = root;

            while (tmp != null_node) {
                if (tmp->value == value)
                    return tmp;
                tmp = comp(tmp->value, value) ? tmp->rnode : tmp->lnode;
            }
            return NULL;
        }

        // 작은 것 중에 가장 큰 것을 먼저 확인한다
        bool deleteNode(T value) {
            Node* node = searchNode(value); // 대체될 애
            Node* tmp = node; // 지워질 애

            if (node) {
                if (tmp->lnode != null_node) {
                    node = node->lnode;
                    while (node->rnode != null_node) // 최남단
                        node = node->rnode;
                    //    10            8
                    //  5        =>   5
                    //    6            6
                    //      8
                    if (node->lnode != null_node && tmp->lnode != node)
                        node->lnode->parent = node->parent;
                    if (tmp->lnode != node) {
                        node->parent->rnode = node->lnode;
                        node->lnode = tmp->lnode;
                        node->lnode->parent = node;
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
                else if (tmp->rnode != null_node) {
                    node = node->rnode;

                    while (node->lnode != null_node)
                        node = node->lnode;

                    // 1(tmp)         2
                    //   3(n->p) =>  3
                    // 2(node)      4
                    //   4(n->r)
                    if (node->rnode != null_node && tmp->rnode != node)
                        node->rnode->parent = node->parent;
                    if (tmp->rnode != node) {
                        node->parent->lnode = node->rnode;
                        node->rnode = tmp->rnode;
                        node->rnode->parent = node;
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
                            node->parent->lnode = null_node;
                        else
                            node->parent->rnode = null_node;
                    }
                    // node가 root노드 단 하나로만 존재할 때
                    else
                        root = NULL;

                    na.destroy(tmp); // 해당 node 지우기
                    na.deallocate(tmp, 1); // 지운 자리의 메모리 해제하기


                }
                size--;
            }
            else
                return false;
            return true; 
        }

        // 중위연산
        void print() {
            print(this->root);
        }
        void print(Node* node) {
            if (!node || node == null_node)
                return ;
            print(node->lnode);
            std::cout << node->value << std::endl;
            print(node->rnode);
        }
    };
}

#endif
