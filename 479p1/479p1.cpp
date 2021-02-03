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


typedef struct
{
    int x, y;
    int num;
    int h;
}node;


int CalcDistance(int row1, int column1, int row2, int column2)
{
    int rowDistance = row2 - row1;
    if (rowDistance < 0)
    {
        rowDistance *= -1;
    }
    int columnDistance = column2 - column1;
    if (columnDistance < 0)
    {
        columnDistance *= -1;
    }
    return rowDistance + columnDistance;
};



int main()
{
    int g = 0;
    int f; //f(n) = g(n)+h(n)
    priority_queue<int, vector<int>, compare > que;
    


    node puzzle[3][3];

    //1st row
    puzzle[0][0].num = 2;   
    puzzle[0][0].x = 0;
    puzzle[0][0].y = 0;

    puzzle[1][0].num = 8;
    puzzle[1][0].x = 1;
    puzzle[1][0].y = 0;

    puzzle[2][0].num = 3;
    puzzle[2][0].x = 2;
    puzzle[2][0].y = 0;

    //2nd row
    puzzle[0][1].num = 6;
    puzzle[0][1].x = 0;
    puzzle[0][1].y = 1;

    puzzle[1][1].num = 7;
    puzzle[1][1].x = 1;
    puzzle[1][1].y = 1;

    puzzle[2][1].num = 4;
    puzzle[2][1].x = 2;
    puzzle[2][1].y = 1;

    //3rd row
    puzzle[0][2].num = 1;
    puzzle[0][2].x = 0;
    puzzle[0][2].y = 2;

    puzzle[1][2].num = 5;
    puzzle[1][2].x = 1;
    puzzle[1][2].y = 2;

    puzzle[2][2].num = 0;
    puzzle[2][2].x = 2;
    puzzle[2][2].y = 2;
 
    int goal[3][3] = { {1,2,3}, {8,0,4}, {7,6,5,} }; // <-- zero represents - in puzzle


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            que.push(puzzle[i][j].num);
            cout << puzzle[i][j].num;
            cout << " ";
        }
        cout << endl;
    }

}