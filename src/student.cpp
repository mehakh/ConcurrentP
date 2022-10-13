#include <student.hpp>

Student::Student(std::string name, int year, double grade) {
    this->name = name;
    this->year = year;
    this->grade = grade;
}

std::string Student::get_name() {
    return this->name;
}

int Student::get_year() {
    return this->year;
}

double Student::get_grade() {
    return this->grade;
}
