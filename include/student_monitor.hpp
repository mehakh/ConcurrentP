#ifndef STUDENT_MONITOR_H
#define STUDENT_MONITOR_H

#include <student.hpp>
#include <vector>
#include <mutex>
#include <optional>

class StudentMonitor {
private:
    std::vector<Student> students;
    std::mutex student_mutex;
public:
    void push_student(Student student);
    std::optional<Student> pop_student();
};

#endif
