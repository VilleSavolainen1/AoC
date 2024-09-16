#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <numeric>



bool isDigit(char ch){
    return std::isdigit(static_cast<unsigned char>(ch));
}


int parseNum(std::string line){
    std::string numbers;
    char num1 = '0';
    char num2 = '0';
    for(int i = 0; i < line.length(); i++){
        if(isDigit(line[i])){
            num1 = line[i];
            break;
        }
    }
    for(int i = line.length(); i >= 0; i--){
        if(isDigit(line[i])){
            num2 = line[i];
            break;
        }
    }
    numbers = std::string() + num1 + num2;
    return stoi(numbers);
}

int main(){
    std::fstream file{"input.txt"};
    if(!file){
        std::cerr<<"Error";
        return 1;
    }
    std::string line;
    std::vector<int> nums;
    while(getline(file, line)){
        nums.push_back(parseNum(line));
    }
    int result = std::accumulate(nums.begin(), nums.end(), 0);
    std::cout<<result;
    file.close();
    return 0;
}