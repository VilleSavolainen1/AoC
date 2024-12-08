#include <bits/stdc++.h>
using namespace std;

// length l, width w, and height h
// 2*l*w + 2*w*h + 2*h*l
// 2x3x4 requires 2*6 + 2*12 + 2*8 = 52

int main()
{
    fstream file("input.txt");
    string line;
    int squareFeet = 0;
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
        squareFeet += count;
    }
    cout << "PART ONE " << squareFeet << '\n';
    file.close();
    return 0;
}