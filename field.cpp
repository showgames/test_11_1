#include "field.h"

STAGE::STAGE() 
{
    int i;
    for (i = 0; i < ROW*COL; i++) {
        stage.push_back(WAL);
    }
}

STAGE::STAGE(int size, Field* field)
{
    int i;

    for (i = 0; i < size; i++) {
        stage.push_back(field[i]);

        if (field[i] == HUM) {
            playerPlace = i;
        } else if (field[i] == GOA) {
            goal = i;
        } else if (field[i] == BAG) {
            bagPlace = i;
        }
    }
}

void
STAGE::DispField()
{
    int i,j;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            cout << stage[j + (i * COL)];
        }
        cout << endl;
    }
}

int
STAGE::MoveCheck(int dir)
{
    int x;
    switch(dir){
        case 0:
        x = -COL;
        break;

        case 1:
        x = COL;
        break;

        case 2:
        x = -1;
        break;

        case 3:
        x = 1;
        break;
    }

    if (stage[playerPlace + x] == EMP) {
        return 1;
    } else if (stage[playerPlace + x] == BAG) {
        if (stage[playerPlace + (2 * x)] == EMP ||
            stage[playerPlace + (2 * x)] == GOA) {
            return 1;
        }
        return 0;
    } else {
        return 0;
    }
}

void
STAGE::MovePlayer(int dir)
{
    int x;
    int tmp;
    switch(dir){
        case 0:
        x = -COL;
        break;

        case 1:
        x = COL;
        break;

        case 2:
        x = -1;
        break;

        case 3:
        x = 1;
        break;
    }

    if (stage[playerPlace + x] == EMP) {
        stage[playerPlace + x] = HUM;
        stage[playerPlace] = EMP;
        playerPlace = playerPlace + x;
    } else if (stage[playerPlace + x] == BAG) {
        stage[playerPlace + x] = HUM;
        stage[playerPlace + (2 * x)] = BAG;
        stage[playerPlace] = EMP;
        bagPlace = playerPlace + (2 * x);
        playerPlace = playerPlace + x;
    }
}

int
STAGE::FinishCheck()
{
    if (bagPlace == goal) {
        return 1;
    } else {
        return 0;
    }
}