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
    int goalx, goaly;
    int num;
    int goalnum;
    int h;

}node;

//Calculate distance between two nodes
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

//assign h(n) to each node
int estimate(node puzzle)
{
    int h;

    h = CalcDistance(puzzle.x, puzzle.y, puzzle.goalx, puzzle.goaly);

    return(h);
}


void printPuzzle(node puzzle[3][3], int g)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << puzzle[j][i].num;
            cout << " ";
        }
        cout << endl;
    }

    cout << "-----" << endl << g << "   " << puzzle[0][0].h;
    cout << endl << endl;
}

void fixPuzzle(node puzzle[3][3], priority_queue<int, vector<int>, compare > que, int g)
{
   
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (puzzle[i][j].num != puzzle[i][j].goalnum)
            {
                puzzle[i][j].num = puzzle[i][j].goalnum;
                puzzle[i][j].x = puzzle[i][j].goalx;
                puzzle[i][j].y = puzzle[i][j].goaly;
                g++;
            }

            puzzle[1][0].num = 2;
            printPuzzle(puzzle, g);

        }

        cout << endl;
    }

 
}

int main()
{
    int g = 0;
    int f; //f(n) = g(n)+h(n)
    priority_queue<int, vector<int>, compare > que;
    node puzzle[3][3];

    //1st row
    puzzle[0][0].num = 2;
    puzzle[0][0].goalnum = 1;
    puzzle[0][0].x = 0;
    puzzle[0][0].y = 0;
    puzzle[0][0].goalx = 1;
    puzzle[0][0].goaly = 0;

    puzzle[1][0].num = 8;
    puzzle[1][0].goalnum = 2;
    puzzle[1][0].x = 1;
    puzzle[1][0].y = 0;
    puzzle[1][0].goalx = 0;
    puzzle[1][0].goaly = 1;

    puzzle[2][0].num = 3;
    puzzle[2][0].goalnum = 3;
    puzzle[2][0].x = 2;
    puzzle[2][0].y = 0;
    puzzle[2][0].goalx = 2;
    puzzle[2][0].goaly = 0;

    //2nd row
    puzzle[0][1].num = 6;
    puzzle[0][1].goalnum = 8;
    puzzle[0][1].x = 0;
    puzzle[0][1].y = 1;
    puzzle[0][1].goalx = 1;
    puzzle[0][1].goaly = 2;

    puzzle[1][1].num = 7;
    puzzle[1][1].goalnum = 0;
    puzzle[1][1].x = 1;
    puzzle[1][1].y = 1;
    puzzle[1][1].goalx = 0;
    puzzle[1][1].goaly = 2;

    puzzle[2][1].num = 4;
    puzzle[2][1].goalnum = 4;
    puzzle[2][1].x = 2;
    puzzle[2][1].y = 1;
    puzzle[2][1].goalx = 2;
    puzzle[2][1].goaly = 1;

    //3rd row
    puzzle[0][2].num = 1;
    puzzle[0][2].goalnum = 7;
    puzzle[0][2].x = 0;
    puzzle[0][2].y = 2;
    puzzle[0][2].goalx = 0;
    puzzle[0][2].goaly = 0;

    puzzle[1][2].num = 5;
    puzzle[1][2].goalnum = 6;
    puzzle[1][2].x = 1;
    puzzle[1][2].y = 2;
    puzzle[1][2].goalx = 2;
    puzzle[1][2].goaly = 2;

    puzzle[2][2].num = 0;
    puzzle[2][2].goalnum = 5;
    puzzle[2][2].x = 2;
    puzzle[2][2].y = 2;
    puzzle[2][2].goalx = 1;
    puzzle[2][2].goaly = 1;

    int goal[3][3] = { {1,2,3}, {8,0,4}, {7,6,5,} }; // <-- zero represents - in puzzle


    cout << "Starting Puzzle: " << endl;
    //push nodes to prio que
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (puzzle[i][j].num != 0)
            {
                que.push(puzzle[i][j].num);
            }
            cout << puzzle[j][i].num;
            cout << " ";
        }
        cout << endl;
    }


    //loop to assign h(n) to each node
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            puzzle[i][j].h = estimate(puzzle[i][j]);

        }
    }

    cout << "Starting algorithm..." << endl;
    fixPuzzle(puzzle, que, g);




   return(0);
}