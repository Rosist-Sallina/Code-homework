// Parser.h
#ifndef PARSER_H
#define PARSER_H

#include <map>
#include <string>

class Parser {
public:
    struct Argument {
        int defaultValue;
        std::string description;
        int value;
    };

    void add_argument(const std::string& name, int defaultValue, const std::string& description);
    void init(char* input);
    int get_argument(const std::string& name);

private:
    std::map<std::string, Argument> arguments;
    void displayHelp();
    void displayError(const std::string& message);
};

#endif // PARSER_H
