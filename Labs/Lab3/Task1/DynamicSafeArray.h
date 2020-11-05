#ifndef DYNAMICSAFEARRAY_H
#define DYNAMICSAFEARRAY_H
#include<iostream>
#include"DSA.cpp"

using namespace std;
using namespace DSA;

namespace OU{
    class OrderdDSA:public DynamicSafeArray{
        public:
        OrderdDSA();
        OrderdDSA(int a);
        void insertion(int val);
        void searching(int var);
        void sort();
    };

    class UnOrderedDSA:public DynamicSafeArray{
        public:
        UnOrderedDSA();
        UnOrderedDSA(int a);
        void insertion(int val);
        void searching(int var);
    };
}

#endif