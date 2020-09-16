#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int row = 5, col = 6;
    int **num_set = (int**)calloc(row, sizeof(int*));
    
    for (int t = 0; t < row; t++)
    {
        num_set[t] = calloc(col, sizeof(int));
    }

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            *(*(num_set+i)+j) = j;
        }
        
    }

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            printf("%d ", num_set[i][j]);
        }
        printf("\n");
    }
    
}
