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
            cout << "player is in " << i << endl;
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