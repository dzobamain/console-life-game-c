#ifndef MODE_2D_H
#define MODE_2D_H

#ifdef MODE_2D
#define HEIGHT 20
#define LENGHT 100

void printArrayToConsole(CellState **gameField)
{
    char sumbols[2] = {'-', '#'};
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < LENGHT; j++)
        {
            if (gameField[i][j].currentState == 0)
                printf("%c", sumbols[0]);
            if (gameField[i][j].currentState == 1)
                printf("%c", sumbols[1]);
        }
        printf("\n");
    }
    printf("\n");
}

int countNeighbors(CellState **gameField, int row, int col)
{
    int count = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue;

            int neighborRow = row + i;
            int neighborCol = col + j;

            if (neighborRow >= 0 && neighborRow < HEIGHT && neighborCol >= 0 && neighborCol < LENGHT)
            {
                if (gameField[neighborRow][neighborCol].currentState == 1)
                {
                    count++;
                }
            }
        }
    }

    return count;
}

CellState **updateCellState(CellState **gameField)
{
    int numbertNeighbors;
    int B = 3;
    int S[2] = {2, 3};

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < LENGHT; j++)
        {
            numbertNeighbors = countNeighbors(gameField, i, j);

            if (gameField[i][j].currentState == 1)
            {
                if (numbertNeighbors == S[0] || numbertNeighbors == S[1])
                    gameField[i][j].nextState = 1;
                else
                    gameField[i][j].nextState = 0;
            }
            else
            {
                if (numbertNeighbors == 3)
                    gameField[i][j].nextState = 1;
                else
                    gameField[i][j].nextState = 0;
            }
        }
    }

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < LENGHT; j++)
        {
            gameField[i][j].currentState = gameField[i][j].nextState;
        }
    }

    return gameField;
}
#endif // MODE_2D
#endif // MODE_1D_H