#include <bits/stdc++.h>

using namespace std;

int red = 12;
int green = 13;
int blue = 14;

int powerOfFewestNumberOfCubes(string x){
    int fewestRed = 0;
    int fewestGreen = 0;
    int fewestBlue = 0;
    int num = 0;
    string color;
    string numString;
    for (int i = 0; i < x.length(); i++){
        if (isdigit(static_cast<unsigned char>(x[i])))
        {
            numString += string() + x[i];
        }
        else
        {
            num = stoi(numString);
            color += x[i];
            if (color == "red")
            {
               if(num > fewestRed){
                fewestRed = num;
               }
            }
            else if (color == "green")
            {
                if(num > fewestGreen){
                    fewestGreen = num;
                }
                
            }
            else if (color == "blue")
            {
                if(num > fewestBlue){
                    fewestBlue = num;
                }
            }
            if (x[i] == ',' || x[i] == ';')
            {
                color = "";
                numString = "";
            }
        }
    }
    return fewestRed * fewestGreen * fewestBlue;
}

bool canPlay(string x)
{
    string color;
    string numString;
    int num;
    int redSum = 0;
    int greenSum = 0;
    int blueSum = 0;
    for (int i = 0; i < x.length(); i++)
    {
        if (isdigit(static_cast<unsigned char>(x[i])))
        {
            numString += string() + x[i];
        }
        else
        {
            num = stoi(numString);
            color += x[i];
            if (color == "red")
            {
                redSum += num;
                if (red - redSum < 0)
                {
                    return false;
                }
            }
            else if (color == "green")
            {
                greenSum += num;
                if (green - greenSum < 0)
                {
                    return false;
                }
            }
            else if (color == "blue")
            {
                blueSum += num;
                if (blue - blueSum < 0)
                {
                    return false;
                }
            }
            if (x[i] == ',')
            {
                color = "";
                numString = "";
            }
            if(x[i] == ';'){
                redSum = 0;
                greenSum = 0;
                blueSum = 0;
                color = "";
                numString = "";
            }
        }
    }
    return true;
}

string removeSpaces(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            str.erase(str.begin() + i);
            i--;
        }
    }
    return str;
}

int main()
{
    fstream file("input.txt");
    if (!file)
    {
        cerr << "Error";
        return 1;
    }
    string line;
    int idx{0};
    int result{0};
    vector<int>fewestNumberOfCubesArray;
    int fewestNumberOfCubesResult = 0;
    while (getline(file, line))
    {
        idx++;
        regex regex(R"([\d]?[\d][\s].*)");
        smatch m;
        regex_search(line, m, regex);
        for (auto x : m)
        {
            if (canPlay(removeSpaces(x)))
            {
                result += idx;
            };
            fewestNumberOfCubesArray.push_back(powerOfFewestNumberOfCubes(removeSpaces(x)));
        }
    }
    //part 1
    cout << "part1 result " << result << '\n';
    for(auto& it : fewestNumberOfCubesArray){
        fewestNumberOfCubesResult += it;
    }
    //part 2
    cout<<"part2 result "<< fewestNumberOfCubesResult <<'\n';
    file.close();
    return 0;
}