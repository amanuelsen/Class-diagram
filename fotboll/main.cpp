#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <memory>
#include "player.h"
#include "Referees.h"
#include "menu.h"
//Vi importerar <limits> f�r att rensa inmatningsbufferten och 
// och vi anv�nder memory f�r att anv�nda smarta pekare , f�r att hantera minnesresurser p� ett s�krt s�tt.

using namespace std;

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    menu();

    return 0;
}
