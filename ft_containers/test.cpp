#include <map>
#include <iostream>
#include "utils/binary_search_tree.hpp"

using namespace std;

int main(void) {
    ft::Bst<int, std::less<int>, std::allocator<int> > bst;

//    bst.insertNode(8);
//    bst.insertNode(5);
//    bst.insertNode(6);
//
//    bst.deleteNode(5);
//    bst.print();
        bst.insertNode(10);
        bst.print();
        cout << "------" << endl;

        bst.deleteNode(10);
        bst.print();
        cout << "--------------------" << endl;

        bst.insertNode(10);
        bst.insertNode(8);
        bst.print();
        cout << "------" << endl;

        bst.deleteNode(10);
        bst.print();
        cout << "---------------------------" << endl;
    //
        bst.insertNode(10);
        bst.print();
        cout << "------" << endl;

        bst.deleteNode(8);
        bst.print();
        cout << "---------------------------" << endl;
    //
        bst.insertNode(8);
        bst.print();
        cout << "------" << endl;

        bst.deleteNode(8);
        bst.print();
        cout << "-------------------------------" << endl;
    //
        bst.insertNode(11);
        bst.print();
        cout << "------" << endl;

        bst.deleteNode(11);
        bst.print();
        cout << "---------------------------" << endl;
    //
        bst.insertNode(5);
        bst.insertNode(6);
        bst.insertNode(7);
        bst.insertNode(8);
        bst.print();
        cout << "----------------------------------------------------------------" << endl;

        bst.deleteNode(7);
        bst.print();
        cout << "------" << endl;
        bst.deleteNode(10); // delete root
        bst.print();
        cout << "------" << endl;
        bst.deleteNode(5);
        bst.print();
        bst.deleteNode(6);
        bst.print();
    cout << "-------------------------------" << endl;
    //
        bst.insertNode(4);
        bst.insertNode(7);
        bst.insertNode(6);
        bst.insertNode(5);
        bst.print();
        cout << "------" << endl;

        bst.deleteNode(8);
        bst.print();
        cout << "---------------------------" << endl;

//    std::map<int, int> m;
//
//    std::cout << (m.find(1) != m.end() ? "찾음" : "못찾음") << "\n";
//    m[1] = 10;
//    std::cout << m.begin()->first << " " << m.begin()->second << std::endl;
    return (0);
}