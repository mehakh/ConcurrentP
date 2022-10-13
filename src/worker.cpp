#include <worker.hpp>
#include <iostream>

Worker::Worker(
    std::shared_ptr<StudentMonitor> available_student_monitor,
    std::shared_ptr<StudentMonitor> processed_student_monitor,
    std::shared_ptr<BoolHolder> done_holder,
    int index
) {
    this->available_student_monitor = available_student_monitor;
    this->processed_student_monitor = processed_student_monitor;
    this->done_holder = done_holder;
    this->index = index;
}

void Worker::start_execution() {
    auto available_student_monitor = this->available_student_monitor;
    auto processed_student_monitor = this->processed_student_monitor;
    auto done_holder = this->done_holder;
    auto index = this->index;

    this->thread = new std::thread([=] {
        while (true) {
            auto student_optional = available_student_monitor->pop_student();

            if (!student_optional.has_value()) {
                if (done_holder->get_value()) {
                    break;
                } else {
                    continue;
                }
            }

            std::cout << "Processing student from thread: " << index << std::endl;

            std::this_thread::sleep_for(std::chrono::seconds(1));

            auto student = student_optional.value();

            this->processed_student_monitor->push_student(student);
        }
    });
}

void Worker::join_execution() {
    if (this->thread->joinable()) {
        this->thread->join();
    }
}
