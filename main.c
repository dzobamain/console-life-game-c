#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int currentState;
    int nextState;
} CellState;


void sleep_ms(int milliseconds);

#define MODE_2D
#include "mode_1d.h"
#include "mode_2d.h"


int main()
{
#ifdef MODE_1D
    CellState *gameField = (CellState *)malloc(LENGHT * sizeof(CellState));
    if (gameField == NULL)
    {
        printf("Unable to allocate memory!\n");
        return 1;
    }
    for (int i = 0; i < LENGHT; i++)
    {
        gameField[i].currentState = 0;
        gameField[i].nextState = 0;
    }

    for (int i = 0; i < 25; i++)
    {
        int index = rand() % LENGHT;
        gameField[index].currentState = 1;
    }

    bool isStarted = true;
    do
    {
        printArrayToConsole(gameField);
        gameField = updateCellState(gameField);
        sleep_ms(50);
        // printf("\033[H\033[J");
    } while (isStarted);
#endif
#ifdef MODE_2D
    CellState **gameField = (CellState **)malloc(HEIGHT * sizeof(CellState *));
    for (int i = 0; i < HEIGHT; i++)
    {
        gameField[i] = (CellState *)malloc(LENGHT * sizeof(CellState));
        for (int j = 0; j < LENGHT; j++)
        {
            gameField[i][j].currentState = 0;
            gameField[i][j].nextState = 0;
        }
    }

    for (int i = 0; i < 1500; i++)
    {
        int row = rand() % HEIGHT;
        int col = rand() % LENGHT;
        gameField[row][col].currentState = 1;
    }

    bool isStarted = true;
    do
    {
        printArrayToConsole(gameField);
        gameField = updateCellState(gameField);
        sleep_ms(150);         
        printf("\033[H\033[J");
    } while (isStarted);

#endif
    return 0;
}

void sleep_ms(int milliseconds)
{
    struct timespec time = {milliseconds / 1000, (milliseconds % 1000) * 1000000};
    nanosleep(&time, NULL);
}
