#include <input_parser.hpp>
#include <student_monitor.hpp>
#include <bool_holder.hpp>
#include <worker.hpp>
#include <vector>
#include <memory>
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Received more or less than 1 arguments" << std::endl;
        return 1;
    }

    auto input_filename = argv[1];

    InputParser input_parser;
    auto students_or_error = input_parser.read_from_file(input_filename);

    if (std::holds_alternative<std::string>(students_or_error)) {
        std::cerr << std::get<std::string>(students_or_error) << std::endl;
        return 1;
    }

    auto students = std::get<std::vector<Student>>(students_or_error);

    auto available_student_monitor = std::make_shared<StudentMonitor>();
    auto processed_student_monitor = std::make_shared<StudentMonitor>();
    auto done_holder = std::make_shared<BoolHolder>(false);

    std::vector<Worker> workers;

    for (auto i = 0; i < std::max(2, (int) students.size() / 4); i++) {
        std::cout << "Starting worker: " << i << std::endl;
        Worker worker(available_student_monitor, processed_student_monitor, done_holder, i);
        worker.start_execution();
        workers.push_back(worker);
    }

    for (auto student : students) {
        available_student_monitor->push_student(student);
    }

    done_holder->set_value(true);

    for (auto worker : workers) {
        worker.join_execution();
    }

    std::cout << "Processed " << students.size() << " students" << std::endl;
    std::cout << "\twith " << workers.size() << " workers" << std::endl;

    return 0;
}
