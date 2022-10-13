#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <student.hpp>
#include <vector>
#include <string>
#include <variant>

class InputParser {
public:
    std::variant<std::vector<Student>, std::string> read_from_file(std::string path);
};

#endif
