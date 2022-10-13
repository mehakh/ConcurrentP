#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    int year;
    double grade;
public:
    Student(std::string name, int year, double grade);

    std::string get_name();
    int get_year();
    double get_grade();
};

#endif
