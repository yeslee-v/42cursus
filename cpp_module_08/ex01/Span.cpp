//
// Created by Yeshin Lee on 2022/01/29.
//

#include "Span.hpp"

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span& span) {
    *this = span;
}

Span& Span::operator=(const Span& span) {
    this->N = span.N;
    return *this;
}

Span::~Span() {}

void Span::addNumber(unsigned int n) {
    if (vec.size() == n || N <= vec.size())
        throw Span::FullException();
    vec.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    std::vector<int>::iterator i;

    for (i = begin; i < end; i++)
        Span::addNumber(*i);
}

unsigned int Span::shortestSpan() {
    int result;

    if (vec.size() < 2)
        throw Span::OneOrNotExistException();

    std::sort(vec.begin(), vec.end());
    std::vector<int>::iterator first = vec.begin();
    std::vector<int>::iterator last = vec.begin() + 1;
    result = *last - *first;
    for (int i = 0; i < vec.size() - 1; i++) {
        result = std::min(result, *last - *first);
        first++;
        last++;
    }
    return result;

}

unsigned int Span::longestSpan() {
    if (vec.size() < 2)
        throw OneOrNotExistException();

    int min = *std::min_element(vec.begin(), vec.end());
    int max = *std::max_element(vec.begin(), vec.end());

    return max - min;

}

const char* Span::FullException::what() const throw() {
    return "There are NO numbers stored";
}

const char* Span::OneOrNotExistException::what() const throw() {
    return "There is ONLY one or NO span to find";
}