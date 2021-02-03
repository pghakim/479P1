// CIS 479 P1
// Program made by Emma Zorn and Patrick Hakim
#include <queue>
#include <string>
#include <iostream>
using namespace std;


//for creating a priority que, smaller value = greater priority
struct compare
{
    bool operator()(const int& l, const int& r)
    {
        return l > r;
    }
};

int CalcDistance(int row1, int column1, int row2, int column2) {
    int rowDistance = row2 - row1;
    if (rowDistance < 0) {
        rowDistance *= -1;
    }
    int columnDistance = column2 - column1;
    if (columnDistance < 0) {
        columnDistance *= -1;
    }
    return rowDistance + columnDistance;
}

int main() 
{

    priority_queue<int, vector<int>, compare > que;
    int puzzle[3][3] = {{2,8,3}, {6,7,4}, {1,5,0,}}; // <-- zero represents - in puzzle
    int goal[3][3] = {{1,2,3}, {8,0,4}, {7,6,5,}}; // <-- zero represents - in puzzle


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            que.push(puzzle[i][j]);
            cout <<  puzzle[i][j];
        }
        cout << endl;
    }

}