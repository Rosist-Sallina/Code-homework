#ifndef Editor_H
#define Editor_H

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <sstream>

// 你可以根据需要修改此文件

class TextEditor
{
private:
    using Position = std::pair<int, int>;
    std::vector<std::string> data;
    Position pos;
    std::list<std::vector<std::string>> history;
    std::list<Position> history_pos;

public:
    TextEditor(){
        data.push_back("");
        Position pos = {0, 0};
    };
    void move(Position dest){
        if(dest.first >= 0 && dest.first < data.size() && dest.second >= 0 && dest.second <= data[dest.first].size()){
            pos = dest;
        }
        else{
            if(dest.first < 0 ){
                pos = dest;
                pos.first = 0;
                return;
            }
            if(dest.second < 0){
                pos = dest;
                pos.second = 0;
                return;
            }
            if(dest.first >= data.size()){
                pos = dest;
                pos.first = data.size() - 1;
				if (data[pos.first].size() < pos.second) {
					pos.second = data[pos.first].size();
				}
                return;
            }
            if(dest.second > data[dest.first].size()){
                pos = dest;
                pos.second = data[dest.first].size();
                return;
            }
        }
        return;
    };
    void write(const std::string &str){
        data[pos.first].insert(pos.second, str);
        pos.second += str.size();
        history.push_back(data);
        history_pos.push_back(pos);
    };
    void newline(){
        std::string new_line = data[pos.first].substr(pos.second);
        data[pos.first].erase(pos.second);
        data.insert(data.begin() + pos.first + 1, new_line);
        pos.first++;
        pos.second = 0;
        history.push_back(data);
        history_pos.push_back(pos);
    };
    void del(){
        if(pos.second == 0){
			if (pos.first == 0) {
				return;
			}
			pos.second = data[pos.first - 1].size();
			data[pos.first - 1] += data[pos.first];
			data.erase(data.begin() + pos.first);
			pos.first--;
        }
        else{
            data[pos.first].erase(pos.second - 1, 1);  
            pos.second -= 1;
        }
        history.push_back(data);
        history_pos.push_back(pos);
    };
    void screenShot(){
        std::cout << "### ScreenShot BEGIN ###" << std::endl;
        for(int i = 0 ; i < data.size() ; i++){
            if(i == pos.first){
                for(int j = 0 ; j <= data[i].size() ; j++){
                    if(j == pos.second){
                        std::cout << "*";
                    }
                    std::cout << data[i][j];
                }
                std::cout << std::endl;
                continue;
            }
            std::cout << data[i] << std::endl;
        }
		std::cout << "### ScreenShot END ###" << std::endl;
    };
    void undo(){
        if(history.size() == 0){
            return;
        }
		if (history.size() == 1) {
            data = { " " };
			pos = { 0, 0 };
		}
        history.pop_back();
        history_pos.pop_back();
        data = history.back();
        pos = history_pos.back();
    };
    void apply(const std::string &opt){
        if(opt == "NEWLINE"){
            newline();
        }
        else if(opt == "DELETE"){
            del();
        }
        else if(opt == "SCREEN"){
            screenShot();
        }
        else if(opt == "UNDO"){
            undo();
        }
        else if (opt[0] == 'W') {
			std::string tmp = opt.substr(6 , opt.size()-6);
			write(tmp);
        }
        else if (opt[0] == 'M') {
            std::stringstream ss(opt);
            std::string tmp;
			while (ss >> tmp) {
                if (tmp == "MOVE") {
					int x, y;
					ss >> x >> y;
					move({x, y});
				}
			}
        }
    };
};

#endif // Editor_H