//N-Queen
/*
    Place N Queens so that all queens are safe
*/
#include<iostream>

using namespace std;

bool isSafe(int board[][10], int i, int j, int n)
{
    //you can check col
    for(int row=0; row<i; row++)
    {
        if(board[row][j] == 1)
            return false;
    }

    //check for left diagonal
    int x = i;
    int y = j;

    while(x>=0 && y>=0)
    {
        if(board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    //check for right diagonal
    x = i;
    y = j;

    while(x>=0 && y<n)
    {
        if(board[x][y] == 1)
            return false;
        x--;
        y++;
    }

    //the position is safe  
    return true;
}

bool solveNQueen(int board[][10], int i, int n)
{
    //base case
    if(i==n)
    {
        //you have successfully placed queens in n rows (0...n-1)
        for(int i = 0; i<n; ++i)
        {
            for(int j = 0; j<n; ++j)
            {
               if(board[i][j] == 1)
               {
                   cout<<"Q ";
               } 
               else 
               {
                   cout<<"_ ";
               }
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    //recursive case
     //Try to place the queen in the current row and call on the remaing part which will be solved by recursion
     for(int j = 0; j<n; j++)
     {
         //I have to check if i,j th position is safe to place the queen or not
        if(isSafe(board, i, j, n))
        {
            //place the Queen- assuming i, j is the right position
            board[i][j] = 1;
            bool canPlaceNextQueen = solveNQueen(board, i+1, n);
            if(canPlaceNextQueen)
            {
                return true;
            }
            // means i,j is not right position- assumption is wrong
            board[i][j] = 0; //backtrack
        }
     }
     //you have tried for all postition in the current row but couldn't place a queen
     return false;
}

int main()
{
    int n = 4;
    system("cls");
    int board[10][10] = {0};
    solveNQueen(board, 0, n);
    return 0;
}