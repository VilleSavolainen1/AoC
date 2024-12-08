#include <bits/stdc++.h>
using namespace std;

int main()
{
    fstream file("input.txt");
    string line;
    int squareFeet = 0;
    int ribbon = 0;
    if (!file)
    {
        cerr << "Error";
        return 1;
    }
    while (getline(file, line))
    {
        string str = line;
        stringstream ss(str);
        string t;
        char del = 'x';
        vector<int> nums;
        vector<int> sides;
        while (getline(ss, t, del))
        {
            nums.push_back(stoi(t));
        }
        int l = nums[0] * nums[1];
        int w = nums[1] * nums[2];
        int h = nums[2] * nums[0];
        sides.push_back(l);
        sides.push_back(w);
        sides.push_back(h);
        vector<int>::iterator min = min_element(sides.begin(), sides.end());
        int count = (2 * (l)) + (2 * (w)) + (2 * (h)) + *min;
        sort(nums.begin(), nums.end());
        int ribbonCount = (nums[0] + nums[0] + nums[1] + nums[1]) + (nums[0] * nums[1] * nums[2]);
        squareFeet += count;
        ribbon += ribbonCount;
    }
    cout << "PART ONE " << squareFeet << '\n';
    cout << "PART TWO " << ribbon << '\n';
    file.close();
    return 0;
}