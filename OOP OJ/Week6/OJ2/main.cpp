#include <iostream>
#include <regex>
#include <string>

bool email_valid(const std::string& email){
    std::regex reg("\\w+@[\\w.]+");
    return std::regex_match(email, reg);
}
bool user_name_valid(const std::string& user_name){
    std::regex reg("[\\w]{4,15}");
    return (std::regex_match(user_name, reg) && isalpha(user_name[0]));
}
bool password_valid(const std::string& password){
    std::regex reg("[a-zA-Z0-9]{8,20}");
    bool hasAlpha = std::regex_search(password, std::regex("[a-zA-Z]")); // Add 'std::' prefix to 'regex_search'
    bool hasDigit = std::regex_search(password, std::regex("[0-9]")); // Add 'std::' prefix to 'regex_search'
    return (std::regex_match(password, reg) && hasAlpha && hasDigit);
}

std::string true_value(const std::string &S , const std::string &key){
    std::regex pattern("\"" + key + "\"\\s*:\\s*\"([^\"]+)\"");
    std::smatch result;
    if(std::regex_search(S, result, pattern)){
        return result[1].str();
    }
    return "";
}

std::string maskinfo(const std::string & type , const std::string & value){
    if(type == "email"){
        if(email_valid(value)){
            std::string s = value;
            auto it = s.begin();
            for(; it != s.end(); it++){
                if(*it == '@' || *it == '.'){
                    continue;
                }
                *it = '*';
            }
            return s;
        }
        return "";
    }
    else if(type == "username"){
        if(user_name_valid(value)){
            std::string s = value;
            auto it = s.begin();
            int count = 0;
            for(; it != s.end(); it++){
                if(count < 3){
                    count ++;
                    continue;
                }
                *it = '*';
            }
            return s;
        }
        return "";
    }
    else if(type == "password"){
        if(password_valid(value)){
            std::string s = value;
            auto it = s.begin();
            for(; it != s.end(); it++){
                *it = '*';
            }
            return s;
        }
        return "";
    }
    return "";
}

int main(){
    std::string s;
    std::cin >> s;

    std::string username = true_value(s, "username");
    std::string email = true_value(s, "email");
    std::string password = true_value(s, "password");

    bool is_username_valid = user_name_valid(username);
    bool is_email_valid = email_valid(email);
    bool is_password_valid = password_valid(password);

    if(is_email_valid && is_username_valid && is_password_valid){
        std::cout << "Successfully registered." << "\n";
        std::cout << "username: " << maskinfo("username", username) << "\n";
        std::cout << "password: " << maskinfo("password", password) << "\n";
        std::cout << "email: " << maskinfo("email", email) << "\n";
    }
    else{
        std::cout << "Illegal ";
        if (!is_username_valid) std::cout << "username" << (!is_email_valid || !is_password_valid ? "," : "");
        if (!is_password_valid) std::cout << "password"<< (!is_email_valid ? "," : "") ;
        if (!is_email_valid) std::cout << "email";
    }
    return 0;
}