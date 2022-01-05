//
// Created by Yeshin Lee on 2022/01/05.
//

#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>

enum Level {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Karen;

typedef struct s_level {
    std::string level;
    void (Karen::*p)(void);
}               t_level;

class Karen {
private:
    t_level list[4];
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
public:
    Karen();
    ~Karen();
    void filter(std::string level);

};


#endif
