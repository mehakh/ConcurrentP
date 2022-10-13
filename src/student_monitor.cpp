#include <student_monitor.hpp>

void StudentMonitor::push_student(Student student) {
    std::lock_guard<std::mutex> lock(this->student_mutex);
    this->students.push_back(student);
}

std::optional<Student> StudentMonitor::pop_student() {
    std::lock_guard<std::mutex> lock(this->student_mutex);

    if (this->students.size() == 0) {
        return {};
    }

    Student student = this->students[this->students.size() - 1];
    this->students.pop_back();
    return student;
}
