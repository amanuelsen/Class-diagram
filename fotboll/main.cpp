#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <memory>
#include "player.h"
#include "Referees.h"
#include "menu.h"
//Vi importerar <limits> för att rensa inmatningsbufferten och 
// och vi använder memory för att använda smarta pekare , för att hantera minnesresurser på ett säkrt sätt.

using namespace std;

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    menu();

    return 0;
}
