#include <stdio.h>

#define N 9

void printSudoku(int sudoku[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%2d", sudoku[i][j]);
            if (j < N - 1)
            {
                if ((j + 1) % 3 == 0)
                    printf(" |");
                else
                    printf("  ");
            }
        }
        printf("\n");
        if (i < N - 1 && (i + 1) % 3 == 0)
            printf("-----------+-----------+-----------\n");
    }
}

int isSafe(int sudoku[N][N], int row, int col, int num)
{
    for (int x = 0; x < N; x++)
        if (sudoku[row][x] == num || sudoku[x][col] == num)
            return 0;

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (sudoku[i + startRow][j + startCol] == num)
                return 0;

    return 1;
}

int solveSudoku(int sudoku[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (sudoku[row][col] == 0)
            {
                for (int num = 1; num <= N; num++)
                {
                    if (isSafe(sudoku, row, col, num))
                    {
                        sudoku[row][col] = num;
                        if (solveSudoku(sudoku))
                            return 1;
                        sudoku[row][col] = 0; 
                    }
                }
                return 0; 
            }
        }
    }
    return 1; 
}

int main()
{
    int sudoku[N][N];

    printf("Enter the Sudoku puzzle (use 0 for empty cells):\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &sudoku[i][j]);

    if (solveSudoku(sudoku))
    {
        printf("\nSolved Sudoku Puzzle:\n");
        printSudoku(sudoku);
    }
    else
    {
        printf("\nNo solution exists.\n");
    }

    return 0;
}