#include <iostream>
#include <string>
#include <limits>
#include "player.h" // Assuming "player.h" contains the necessary class definitions

using namespace std;

int main() {
    string date, stadium, result;
    cout << "Ange matchens datum: ";
    getline(cin, date);

    cout << "Ange matchens arena: ";
    getline(cin, stadium);

    cout << "Ange matchresultat: ";
    getline(cin, result);

    FootballMatch* footballmatch = new FootballMatch(date, stadium, result);

    string home, away;
    cout << "Ange hemmalaget: ";
    getline(cin, home);

    cout << "Ange bortalaget: ";
    getline(cin, away);
    cout << "hej";

    Team* hometeam = new Team(home);
    Team* awayteam = new Team(away);

    footballmatch->addTeam(hometeam);
    footballmatch->addTeam(awayteam);

    char choice;
    bool validChoice = false;

    do {
        cout << "Vill du ange spelarna som spelade i matchen?" << endl;
        cout << "Ange 'j' för ja och 'n' för nej: ";
        cin >> choice;

        if (choice == 'j') {
            validChoice = true;

            int numberofplayers;
            cout << "Ange antalet spelare du vill lägga till för hemmalaget (max 11 spelare): ";
            cin >> numberofplayers;

            for (int i = 0; i < numberofplayers; i++) {
                string name;
                int age;

                cout << "Ange spelare " << i + 1 << "s namn: ";
                cin >> name;

                cout << "Ange spelare " << i + 1 << "s ålder: ";
                cin >> age;

                if (cin.fail() || age <= 0) {
                    cout << "Ogiltig ålder. Ange en giltig ålder." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    i--;
                    continue;
                }

                FootballPlayer* player = new FootballPlayer(name, age);
                hometeam->addPlayer(player);
            }

            int numberofplayersforteam2;
            cout << "Ange antalet spelare du vill lägga till för bortalaget (max 11 spelare): ";
            cin >> numberofplayersforteam2;

            for (int i = 0; i < numberofplayersforteam2; i++) {
                string name;
                int age;

                cout << "Ange spelare " << i + 1 << "s namn: ";
                cin >> name;

                cout << "Ange spelare " << i + 1 << "s ålder: ";
                cin >> age;

                if (cin.fail() || age <= 0) {
                    cout << "Ogiltig ålder. Ange en giltig ålder." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    i--;
                    continue;
                }

                FootballPlayer* player = new FootballPlayer(name, age);
                awayteam->addPlayer(player);
            }
        }
        else if (choice == 'n') {
            validChoice = true;
            break;
        }
        else {
            cout << "Ogiltigt val. Ange 'j' eller 'n'." << endl;
        }
    } while (!validChoice);

    char refereeChoice;
    Referees* ref = new Referees();

    do {
        cout << "Vill du lägga till domarenamn? Ange 'j' för ja och 'n' för nej: ";
        cin >> refereeChoice;
        cin.ignore();

        if (refereeChoice == 'j') {
            cout << "Skriv in domarens namn: ";
            string refereeName;
            getline(cin, refereeName);
            ref = new MatchRefere(refereeName);
            break;
        }
        else if (refereeChoice == 'n') {
            break;
        }
        else {
            cout << "Ogiltigt val. Ange 'j' eller 'n'." << endl;
        }
    } while (true);

   
      cout << "Domarens namn: " << ref->toString() << endl;


    footballmatch->displayMatchInfo();

    delete footballmatch;
    delete hometeam;
    delete awayteam;
    delete ref;

    return 0;
}
