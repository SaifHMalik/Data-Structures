#include<iostream>
#include<string>
#ifndef DSA_H
#define DSA_H

using namespace std;

namespace DSA{
    class ArrayIndexOutOfBoundException{
        private:
            const char * msg;
        public:
            ;
            ArrayIndexOutOfBoundException();
            ~ArrayIndexOutOfBoundException();
            string what();
        
    };

    class DynamicSafeArray{
        protected:
            int *Data;
            int size;
        
        public:
            DynamicSafeArray();
            DynamicSafeArray(int n);
            DynamicSafeArray(const DynamicSafeArray & rhs);
            ~DynamicSafeArray();
            void Resize(int nSize);
            unsigned int getSize() const;
            DynamicSafeArray& operator = (DynamicSafeArray &rhs);
            int &operator[](unsigned int i);
            const int& operator[](unsigned int i) const;
            void operator << (DynamicSafeArray &rhs);
            void operator >> (DynamicSafeArray &rhs);
            void insertion(int val);
            void searching();
 
    };

    
}



#endif