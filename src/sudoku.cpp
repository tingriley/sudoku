#include <iostream>
#include <fstream>
#include <string>
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
    cout << "==================" <<endl;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    cout << "------------------" << endl << endl;
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

void Sudoku::readData(){
    std::ifstream file; 
    file.open("./data/grid.txt");
    int x = 0;
    if ( file.is_open() ) { 
        for(int i = 0; i < N ; i++){
            for (int j = 0; j < N; j++){
                file >> x; 
                grid[i][j] = x;
            }
        }
        
    }
}

int main()
{
    Sudoku sudoku;
    sudoku.readData();
    sudoku.print();
    if(sudoku.solve(0, 0)){
        sudoku.print();
    }

}