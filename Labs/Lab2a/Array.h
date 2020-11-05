#include <iostream>
#ifndef ARRAY_H
#define ARRAY_H
#include "Student.h"

using namespace std;
using namespace St;

namespace A{
    class Array{
        private:
        Student * student;
        int size;

        public:
        Array(Student* s,int num);
        Student& operator[](int index);
    };
}

#endif