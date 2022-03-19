//
// Created by Yeshin Lee on 2022/03/19.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace ft {
    class Vector {
    private:
    public:
        Vector();
        Vector(const Vector& vector);
        Vector& operator=(const Vector& vector);
        ~Vector();
    };
}



#endif
