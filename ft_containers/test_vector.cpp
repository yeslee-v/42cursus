#include <iostream>
#include "binary_search_tree.hpp"

using namespace std;

int main() {
    ft::Bst<int, std::less<int>, std::allocator<int> > bst;

    bst.insertNode(8);
    bst.insertNode(5);
    bst.insertNode(6);

    bst.deleteNode(5);
    bst.print();
//    bst.insertNode(10);
//    bst.print();
//    cout << "------" << endl;
//
//    bst.deleteNode(10);
//    bst.print();
//    cout << "--------------------" << endl;
//
//    bst.insertNode(10);
//    bst.insertNode(8);
//    bst.print();
//    cout << "------" << endl;
//
//    bst.deleteNode(10);
//    bst.print();
//    cout << "---------------------------" << endl;
////
//    bst.insertNode(10);
//    bst.print();
//    cout << "------" << endl;
//
//    bst.deleteNode(8);
//    bst.print();
//    cout << "---------------------------" << endl;
////
//    bst.insertNode(8);
//    bst.print();
//    cout << "------" << endl;
//
//    bst.deleteNode(8);
//    bst.print();
//    cout << "-------------------------------" << endl;
////
//    bst.insertNode(11);
//    bst.print();
//    cout << "------" << endl;
//
//    bst.deleteNode(11);
//    bst.print();
//    cout << "---------------------------" << endl;
////
//    bst.insertNode(5);
//    bst.insertNode(6);
//    bst.insertNode(7);
//    bst.insertNode(8);
//    bst.print();
//    cout << "------" << endl;
//
//    bst.deleteNode(7);
//    bst.print();
//    cout << "------" << endl;
//    bst.deleteNode(10); // delete root
//    bst.print();
//    cout << "------" << endl;
//    bst.deleteNode(5);
//    bst.print();
//    bst.deleteNode(6);
//    bst.print();
    cout << "-------------------------------" << endl;
//
//    bst.insertNode(4);
//    bst.insertNode(7);
//    bst.insertNode(6);
//    bst.insertNode(5);
//    bst.print();
//    cout << "------" << endl;
//
//    bst.deleteNode(8);
//    bst.print();
//    cout << "---------------------------" << endl;

}