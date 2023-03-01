//rat in a maze
#include<iostream>

using namespace std;

bool ratInAMaze(char arr[][10], int sol[][10], int i, int j, int m, int n)
{
    if(i == m && j == n)
    {
        for(int k = 0; k<=m; k++)
        {
            for(int l = 0; l<=n; l++)
            {
                cout<<sol[k][l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    if(arr[i][j] == 'X') return false;
    if(i>m || j>n) return false;
    sol[i][j] = 1;
    bool rightSol  = ratInAMaze(arr, sol, i, j+1, m, n);
    bool bottomSol = ratInAMaze(arr, sol, i+1, j, m, n);   
    sol[i][j] = 0;

    if(rightSol || bottomSol) return true;
    return false;
}


int main()
{
    system("cls");
    char arr[10][10] = {
        "0000",
        "000X",
        "00X0",
        "0000"
    };
    int sol[10][10] = {0};
    int m = 4, n = 4;
    bool foundPaths = ratInAMaze(arr, sol,  0, 0, m-1, n-1);
    if(!foundPaths) cout<<"No path found"<<endl;
    return 0;
}