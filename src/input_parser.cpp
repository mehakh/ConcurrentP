#include <input_parser.hpp>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

std::variant<std::vector<Student>, std::string> InputParser::read_from_file(std::string path) {
    std::vector<Student> students;

    std::ifstream input_stream(path);

    if (!input_stream.is_open()) {
        return "Failed to open input file";
    }

    auto data = json::parse(input_stream);

    for (auto student_object : data["students"]) {
        Student student(
            student_object["name"],
            student_object["year"],
            student_object["grade"]
        );

        students.push_back(student);
    }

    return students;
}
