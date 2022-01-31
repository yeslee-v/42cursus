//
// Created by Yeshin Lee on 2022/01/29.
//

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span {
private:
    std::vector<int> vec;
    unsigned int N;
public:
    Span(unsigned int N);
    Span(const Span& span);
    Span& operator=(const Span& span);
    ~Span();

    void addNumber(unsigned int n);
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    unsigned int shortestSpan();
    unsigned int longestSpan();

    class FullException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class OneOrNotExistException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};



#endif
