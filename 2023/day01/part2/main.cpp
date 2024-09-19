#include <bits/stdc++.h>

using namespace std;

bool isDigit(char ch)
{
    return isdigit(static_cast<unsigned char>(ch));
}

int parseNum(string line){
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

int convert(string &line)
{
    auto digits = map<string, char>{
        {"one", '1'}, {"two", '2'}, {"three", '3'}, {"four", '4'}, {"five", '5'}, {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'}};

    auto converted = string(line);
    for(auto d : digits){
        auto pos = 0;
        while((pos = converted.find(d.first, pos)) != string::npos){
            converted.insert(converted.begin() + pos + 1, 1, d.second);
            pos += 2;
        }
    }
    
    return parseNum(converted);
}

int main()
{
    fstream file{"input.txt"};
    if (!file)
    {
        cerr << "Error";
        return 1;
    }
    string line;
    vector<int> nums;
    while (getline(file, line))
    {
        nums.push_back(convert(line));
    }
    int result = accumulate(nums.begin(), nums.end(), 0);
    cout << result;
    file.close();
    return 0;
}