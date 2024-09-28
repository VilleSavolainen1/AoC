#include <bits/stdc++.h>

using namespace std;

int red = 12;
int green = 13;
int blue = 14;

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
    vector<int> possibleId;
    vector<string> games;
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
        }
    }
    cout << "result " << result << '\n';
    file.close();
    return 0;
}