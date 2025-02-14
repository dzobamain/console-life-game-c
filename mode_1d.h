#ifndef MODE_1D_H
#define MODE_1D_H
#ifdef MODE_1D

#define LENGHT 100

void printArrayToConsole(CellState *gameField)
{
    char sumbols[2] = {'-', '#'};
    for (int i = 0; i < LENGHT; i++)
    {
        if (gameField[i].currentState == 0)
            printf("%c", sumbols[0]);
        if (gameField[i].currentState == 1)
            printf("%c", sumbols[1]);
    }
    printf("\n");
}

int countNeighbors(CellState *gameField, int positionCell)
{
    int count = 0;

    if (positionCell > 0 && gameField[positionCell - 1].currentState == 1)
        count++;
    if (positionCell < LENGHT - 1 && gameField[positionCell + 1].currentState == 1)
        count++;

    return count;
}

CellState *updateCellState(CellState *gameField)
{
    int numbertNeighbors;

    for (int i = 0; i < LENGHT; i++)
    {
        numbertNeighbors = countNeighbors(gameField, i);

        if (gameField[i].currentState == 1)
        {
            if (numbertNeighbors == 1)
            {
                gameField[i].nextState = 1;
            }
            else
            {
                gameField[i].nextState = 0;
            }
        }
        else
        {
            if (numbertNeighbors == 1)
            {
                gameField[i].nextState = 1;
            }
            else
            {
                gameField[i].nextState = 0;
            }
        }
    }

    for (int i = 0; i < LENGHT; i++)
    {
        gameField[i].currentState = gameField[i].nextState;
    }

    return gameField;
}

#endif // MODE_1D
#endif // MODE_1D_H