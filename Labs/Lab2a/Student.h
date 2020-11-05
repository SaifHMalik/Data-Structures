#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>

namespace St{

    class Student{
    private:
        std::string ID;
        std::string *cources;
        std::string batch;
        std::string discipline;
        int expectedGY;
        int csize;

       

    public:
        Student();
        Student(std::string _ID);
        Student(std::string _ID, std::string * _cources, int _csize, std::string _batch, std::string _discipline, int _GY);


        void setID(std::string _ID);
        void setBatch(std::string _batch);
        void setDiscipline(std::string _discipine);
        void setExpectedGY(int _expectedGY);
        void setCourceSize(int _cize);
        void setCurrentCources(std::string *_cources,int _csize);

        std::string getID();
        std::string getBatch();
        std::string getDiscipline();
        int getExpectedGY();

        void showCurrentCources();

    };

}



#endif
