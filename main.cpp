#include "field.h"
#include <stdio.h>

int
main(int argc, char* argv[])
{
    Field x[ROW * COL] = {
        WAL, WAL, WAL, WAL, WAL,
        WAL, HUM, EMP, EMP, WAL,
        WAL, EMP, BAG, EMP, WAL,
        WAL, EMP, EMP, EMP, WAL,
        WAL, WAL, WAL, GOA, WAL,
    };

    STAGE stage(sizeof(x)/sizeof(x[0]), x);
    stage.DispField();

    int dir;
    int moveCheck = 0;
    int finishCheck = 0;
    char buf[256];
    while(!finishCheck){

        while(!moveCheck){
            cout << "動く向きを指定してください" << endl;
            cout << "↑:0 ↓:1 ←:2 →:3" << endl;
            fgets(buf, sizeof(buf), stdin);
            sscanf(buf, "%d", &dir);

            if(dir >=0 && dir <= 3) {
                moveCheck = stage.MoveCheck(dir);
            } else {
                continue;
            }
        }

        stage.MovePlayer(dir);
        stage.DispField();
        moveCheck = 0;

        finishCheck = stage.FinishCheck();
    }

    cout << "Congratulations!" << endl;

    return 0;
}

