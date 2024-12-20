#include <iostream>
#include "sudoku.h"

using namespace std;

Sudoku::Sudoku(){
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            grid[i][j] = 0;
    }
}

/* A utility function to print grid */
void Sudoku::print()
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

void Sudoku::setGrid(int arr[N][N]){
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            grid[i][j] = arr[i][j];
    }
}

bool Sudoku::isValid(int r, int c, int num){
    for(int i = 0; i < N; i++){
        if(grid[r][i] == num) return false;
        if(grid[i][c] == num) return false;
    }

    // Check if we find the same num in 
    // the particular 3*3 matrix,
    // we return false
    int startRow = r - r % 3;
    int startCol = c - c % 3;
  
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
            
    }
    return true;
}

bool Sudoku::solve(int r, int c)
{
    if (r == N - 1 && c == N) return true;
    if(c == N){
        c = 0;
        r++;
    }

    if(grid[r][c]!=0)
        return solve(r, c+1);

    for(int i = 1; i <= N; i++){
        if(isValid(r, c, i)){
            grid[r][c] = i;
            if(solve(r,c))return true;
        }
        grid[r][c] = 0;
    }
    return false;
    
}

int main()
{
    // 0 means unassigned cells
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    
    Sudoku sudoku;
    sudoku.setGrid(grid);
    if(sudoku.solve(0, 0)){
        sudoku.print();
    }

}