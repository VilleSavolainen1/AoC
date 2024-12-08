#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream file("input.txt");
    string line;
    int floor = 0;
    int firstCharPosition = 0;
    bool isFound = false;
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
            if(floor == -1 && !isFound){
                isFound = true;
                firstCharPosition = i+1;
            }
        }
    }
    cout << "PART ONE: " << floor << '\n';
    cout << "PART TWO: " << firstCharPosition << '\n';
    file.close();
    return 0;
}