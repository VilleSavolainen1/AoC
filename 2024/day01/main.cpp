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
    vector<int> first;
    vector<int> second;
    vector<int> divs;
    vector<int> similarities;
    while (getline(file, line))
    {
        int end = line.find("   ");
        while (end != -1)
        {
            first.push_back(stoi(line.substr(0, end)));
            line.erase(line.begin(), line.begin() + end + 1);
            end = line.find("   ");
            second.push_back(stoi(line.substr(0, end)));
        }
    }
    sort(begin(first), end(first));
    sort(begin(second), end(second));
    for (int i = 0; i < 1000; ++i)
    {
        int score = 0;
        divs.push_back(abs(second[i] - first[i]));
        for (int j = 0; j < 1000; ++j)
        {
            if (second[j] == first[i])
            {
                score++;
            }
        }
        similarities.push_back(first[i] * score);
    }
    int totalDistance = 0;
    for (auto i : divs)
    {
        totalDistance += i;
    }

    // Part one
    cout << totalDistance << '\n';
    // Part two
    cout << accumulate(similarities.begin(), similarities.end(), 0);
    file.close();
    return 0;
}