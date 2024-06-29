#include "editor.h"
#include <string>
#include <iostream>

int main()
{
    TextEditor t;
    int cmd_num = 0;
    std::cin >> cmd_num;
    std::cin.ignore();
    while (cmd_num--) {
        std::string cmd;
        std::getline(std::cin, cmd);
        t.apply(cmd);
    }
    return 0;
}