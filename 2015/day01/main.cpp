#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream file("input.txt");
    string line;
    int floor = 0;
    if (!file)
    {
        cerr << "Error";
        return 1;
    }
    while (getline(file, line)){
        for(int i = 0; i < line.length(); i++){
            if(line[i] == '('){
                floor++;
            } else{
                floor--;
            }
        }
    }
    cout << "PART ONE: " << floor << '\n';
    file.close();
    return 0;
}