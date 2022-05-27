#include <iostream>
#include <vector>

int main() {
    std::vector<int> foo(2, 0);
    // foo.push_back(1);
    // foo.push_back(2);
    // foo.push_back(3);
    // foo.push_back(4);

    std::vector<int> bar;

    bar.push_back(1);
    bar.push_back(2);
    bar.push_back(3);

    for (size_t i = 0; i < foo.size(); i++){
        std::cout << "foo[" << i << "] : " << foo[i] << std::endl;
    }
    std::cout << "size : " << foo.size() << " cap : " << foo.capacity() << std::endl;

    foo.assign(bar.begin(), bar.end());
    for (size_t i = 0; i < foo.size(); i++){
        std::cout << "foo[" << i << "] : " << foo[i] << std::endl;
    }
    std::allocator<int> alloc;

    int *i;
    alloc.deallocate(i, 0);
    std::cout << "size : " << foo.size() << " cap : " << foo.capacity() << std::endl;
}