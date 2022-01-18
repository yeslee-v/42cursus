//
// Created by Yeshin Lee on 2022/01/16.
//

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
protected:
    int idx;
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain& brain);
    Brain& operator=(const Brain& brain);
    ~Brain();

    void setIdea(const std::string idea);
    std::string getIdea(unsigned int idx) const;
};


#endif
