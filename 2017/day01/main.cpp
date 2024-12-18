#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream file("input.txt");
    if (!file)
    {
        cerr << "Error";
        return 1;
    }
    string line;
    vector<int> matches;
    vector<int> matches2;
    while (getline(file, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == line[i + 1])
            {
                matches.push_back(line[i] - '0');
            }
            else if (line[i] == line[i + 1] & line[i] != line[i + 2])
            {
                matches.push_back(line[i] - '0');
                i += 2;
            }
        }
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == line[i+(line.length()/2)])
            {
                matches2.push_back((line[i] - '0') * 2);
            }
        }
    }
    cout << "PART ONE " << accumulate(matches.begin(), matches.end(), 0) << '\n';
    cout << "PART TWO " << accumulate(matches2.begin(), matches2.end(), 0);
    return 0;
}