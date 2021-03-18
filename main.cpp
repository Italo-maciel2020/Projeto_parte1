#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "sculptor.cpp"

using namespace std;

int main(void)
{
    Sculptor m(40,40,40);
    m.setColor(1,0,0,0);
    m.putVoxel(0,0,0);
    m.cutVoxel(0,0,0);
    m.putBox(0,23,0,23,0,23);
    m.cutBox(0,0,0,0,0,0);
    m.writeOFF("teste.off");
    return 0;
}
