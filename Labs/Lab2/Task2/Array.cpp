#include <iostream>
#include "Array.h"
#include "Student.h"

using namespace std;
using namespace St;
using namespace A;

Array::Array(Student* st, int num) 
{ 
    size = num; 
    student = NULL; 
    if (num != 0) { 
        student = new Student[num]; 
        for (int i = 0; i < num; i++) 
            student[i] = st[i]; 
    } 
} 


Student& Array::operator[](int index) {
	if (index >= size || index < 0) {
		cout << "Invalid Index" << endl;
		exit(0);
	}
	else {
		return student[index];
	}
}

