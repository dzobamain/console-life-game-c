#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MODE_1D

typedef struct
{
    int currentState;
    int nextState;
} CellState;

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

CellState* updateCellState(CellState *gameField)
{
    int numbertNeighbors;

    for (int i = 0; i < LENGHT; i++)
    {
        numbertNeighbors = countNeighbors(gameField, i);

        if (gameField[i].currentState == 1) {
            if (numbertNeighbors == 1) {
                gameField[i].nextState = 1;
            } else {
                gameField[i].nextState = 0; 
            }
        } 
        else 
        {
            if (numbertNeighbors == 1) {
                gameField[i].nextState = 1;
            } else {
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

#ifdef MODE_2D
#define HEIGHT 100
#define LENGHT 100

void printArrayToConsole(CellState** gameField)
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
}

int countNeighbors(CellState** gameField, int row, int col)
{
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0)
                continue;

            int neighborRow = row + i;
            int neighborCol = col + j;

            if (neighborRow >= 0 && neighborRow < HEIGHT && neighborCol >= 0 && neighborCol < LENGHT) {
                if (gameField[neighborRow][neighborCol].currentState == 1) {
                    count++; 
                }
            }
        }
    }

    return count;
}

CellState** updateCellState(CellState **gameField)
{
    int numbertNeighbors;

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < LENGHT; j++)
        {
            numbertNeighbors = countNeighbors(gameField, i, j);

            if (gameField[i][j].currentState == 1)
            {
                if (numbertNeighbors == 2 || numbertNeighbors == 3)
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

void sleep_ms(int milliseconds);

int main()
{
#ifdef MODE_1D
    CellState* gameField = (CellState*)malloc(LENGHT * sizeof(CellState));
    if (gameField == NULL) {
        printf("Не вдалося виділити пам'ять!\n");
        return 1;
    }
    for (int i = 0; i < LENGHT; i++) 
    {
        gameField[i].currentState = 0;
        gameField[i].nextState = 0;
    }

    gameField[50].currentState = 1;
    gameField[51].currentState = 1;

    bool isStarted = true;
    do
    {
        printArrayToConsole(gameField);
        gameField = updateCellState(gameField);
        sleep_ms(750);
    } while (isStarted);
#endif
#ifdef MODE_2D
    CellState** gameField = (CellState**)malloc(HEIGHT * sizeof(CellState*));
    for (int i = 0; i < HEIGHT; i++)
    {
        gameField[i] = (CellState*)malloc(LENGHT * sizeof(CellState));
        for (int j = 0; j < LENGHT; j++) 
        {
            gameField[i][j].currentState = 0;
            gameField[i][j].nextState = 0;
        }
    }

    gameField[50][50].currentState = 1;
    gameField[51][51].currentState = 1;
    gameField[52][49].currentState = 1;
    gameField[52][50].currentState = 1;
    gameField[52][51].currentState = 1;

    bool isStarted = true;
    do
    {
        printArrayToConsole(gameField);
        gameField = updateCellState(gameField);
        sleep_ms(500);
    } while (isStarted);
    
    
#endif
    return 0;
}

void sleep_ms(int milliseconds)
{
    struct timespec time = {milliseconds / 1000, (milliseconds % 1000) * 1000000};
    nanosleep(&time, NULL);
}
