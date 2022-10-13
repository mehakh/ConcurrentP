#ifndef BOOL_HOLDER_H
#define BOOL_HOLDER_H

#include <mutex>

class BoolHolder {
private:
    bool value;
    std::mutex value_mutex;
public:
    BoolHolder(bool initialValue);
    void set_value(bool value);
    bool get_value();
};

#endif
