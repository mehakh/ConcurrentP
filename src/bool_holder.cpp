#include <bool_holder.hpp>

BoolHolder::BoolHolder(bool initialValue) {
    this->value = initialValue;
}

void BoolHolder::set_value(bool value) {
    std::lock_guard<std::mutex> lock(this->value_mutex);
    this->value = value;
}

bool BoolHolder::get_value() {
    std::lock_guard<std::mutex> lock(this->value_mutex);
    return this->value;
}
