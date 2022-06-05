#include <map>
#include <iostream>

int main(void) {
    std::map<int, int> m;

    std::cout << (m.find(1) != m.end() ? "찾음" : "못찾음") << "\n";
    m[1] = 10;
    std::cout << m.begin()->first << " " << m.begin()->second << std::endl;
    return (0);
}