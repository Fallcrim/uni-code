#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>


std::string remove_file_ending(const std::string& filename) {
    size_t dot = filename.find_last_of('.');
    return (dot == std::string::npos) ? filename : filename.substr(0, dot);
}

int main() {
    std::string src_file;
    std::string target_directory = "./executables/";

    std::cout << "Enter source filename: ";
    std::getline(std::cin, src_file);

    std::string filename_without_ending = remove_file_ending(src_file);
    std::string output_file = target_directory + filename_without_ending;

    std::string compile_command = "clang++ -std=c++20 -o \"" + output_file + "\" \"" + src_file + "\"";
    std::cout << "Compiling with command: " << compile_command << std::endl;

    int status = std::system(compile_command.c_str());

    if (status == 0) {
        std::cout << "Successfully compiled " << src_file << " to " << output_file << std::endl;
    } else {
        std::cout << "An error occured while compiling " << src_file << std::endl;
    }
}