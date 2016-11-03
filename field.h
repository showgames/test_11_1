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
    int playerPlace;

public:

    STAGE();
    STAGE(int size, Field* field);
    void DispField();
};
