#ifndef SUDOKU_H
#define SUDOKU_H
#define N 9  // N is the size of the 2D matrix   N*N

class Sudoku
{
public:
    Sudoku();
    ~Sudoku(){}
    void print();
    int grid[N][N];
    void setGrid(int arr[N][N]);
    bool isValid(int r, int c, int num);
    bool solve(int r, int c);
    void readData();
};
#endif