#ifndef WORKER_H
#define WORKER_H

#include <student_monitor.hpp>
#include <bool_holder.hpp>
#include <memory>
#include <thread>

class Worker {
private:
    std::shared_ptr<StudentMonitor> available_student_monitor;
    std::shared_ptr<StudentMonitor> processed_student_monitor;
    std::shared_ptr<BoolHolder> done_holder;
    int index;
    std::thread *thread;
public:
    Worker(
        std::shared_ptr<StudentMonitor> available_student_monitor,
        std::shared_ptr<StudentMonitor> processed_student_monitor,
        std::shared_ptr<BoolHolder> done_holder,
        int index
    );
    void start_execution();
    void join_execution();
};

#endif
