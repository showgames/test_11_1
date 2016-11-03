#include <iostream>
#include <vector>
using namespace std;

#define ROW 5
#define COL 5

enum Field {
    WAL,
    GOA,
    HUM,
    BAG,
    EMP,
};

class STAGE
{
    vector<Field> stage;
    int startPlace;

    STAGE();
    STAGE(int start, int size, Field* field);
};

STAGE::STAGE() 
{
    int i;
    for (i = 0; i < ROW*COL; i++) {
        stage.push_back(WAL);
    }
}

STAGE::STAGE(int start, int size, Field* field)
{
    startPlace = start;
    int i;
    
    for (i = 0; i < size; i++) {
        stage.push_back(field[i]);
    }
}