// Parser.cpp
#include "Parser.h"
#include <iostream>
#include <sstream>
#include <algorithm>

void Parser::add_argument(const std::string& name, int defaultValue, const std::string& description) {
    arguments[name] = {defaultValue, description, defaultValue};
}

void Parser::init(char* input) {
    std::string args(input);
    std::istringstream iss_0(args);
    std::istringstream iss(args);
    std::string arg;
    bool helpRequested = false;

    while (iss_0 >> arg) {
        if (arg == "--help") {
			helpRequested = true;
			break;
		}
	}   
    
    while (iss >> arg) {
        if (arg == "--help") {
            helpRequested = true;
            break;
        }

        if (helpRequested) {
            displayHelp();
            break;
        }

        if (arguments.find(arg) == arguments.end() && helpRequested == false) {
            displayError("unrecognized arguments: " + arg);
            return;
        }

        std::string valueStr;
        if (!(iss >> valueStr) && helpRequested == false) {
            displayError("argument " + arg + ": expected an argument");
            return;
        }

        // Check if the next value is another argument or not an integer
        if ((valueStr.rfind("--", 0) == 0 || !std::all_of(valueStr.begin(), valueStr.end(), ::isdigit)) && helpRequested == false) {
            displayError("argument " + arg + ": invalid int value: '" + valueStr + "'");
            return;
        }

        int value = std::stoi(valueStr);
        arguments[arg].value = value;
    }

    if (helpRequested) {
        displayHelp();
    }
}


int Parser::get_argument(const std::string& name) {
    return arguments["--" + name].value;
}

void Parser::displayHelp() {
    std::cout << "usage: ./main [--help] ";
    for (const auto& arg : arguments) {
        std::string tempt = arg.first.substr(2);
        std::transform(tempt.begin(), tempt.end(), tempt.begin(), ::toupper);
        std::cout << "[" << arg.first << " " << tempt << "] ";
    }
    std::cout << "\n\noptional arguments:\n";
    std::cout << "--help   show this help message and exit\n";
    for (const auto& arg : arguments) {
        std::string tempt = arg.first.substr(2);
        std::transform(tempt.begin(), tempt.end(), tempt.begin(), ::toupper);
        std::cout << arg.first << " " << tempt << "   " << arg.second.description << "\n";
    }
    exit(0);
}

void Parser::displayError(const std::string& message) {
    std::cout << "usage: ./main [--help] ";
    for (const auto& arg : arguments) {
        std::string tempt = arg.first.substr(2);
        std::transform(tempt.begin(), tempt.end(), tempt.begin(), ::toupper);
        std::cout << "[" << arg.first << " " << tempt << "] ";
    }
    std::cout << "\n./main: error: " + message << std::endl;
    exit(0);
}
