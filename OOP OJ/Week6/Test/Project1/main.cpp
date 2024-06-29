#include <iostream>
#include <single_include/nlohmann/json.hpp>
#include <fstream>
#include <vector>
using json = nlohmann::json;

//测试和STL库的兼容性

int main()
{
    json temp_j;
	temp_j["name"] = "nlohmann";
	temp_j["stars"] = 10;
	temp_j["contributor"] = true;
	temp_j["contributor"] = {"nlohmann", "theodelrieu",".etc"};

	std::vector<std::string> license = { "MIT", "GPL", "GNU"};
	
	temp_j["license"] = license;
	temp_j.push_back({ "C++", "JSON" });
	temp_j["pair"] = std::make_pair<int, std::string>(1, "one");
	temp_j["object"] = { {"currency", "USD"}, {"value", 42.99} };

	std::ofstream o("information.json");
	std::cout << temp_j.dump(4) << std::endl;
	o << temp_j.dump(4) << std::endl;
	o.close();
	return 0;  
	
}
