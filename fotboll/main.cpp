#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include "player.h"

using namespace std;

int main() {
    char program;

    do {
        cout << "V�lj ett alternativ:\n";
        cout << "'y' f�r att ange fotbollsmatchers reultat och detaljer.\n";
        cout << "'s' f�r att l�sa en fil.\n";
        cout << "'q' f�r att avsluta programmet.\n";
        cin >> program;
        cin.ignore();

        if (program == 'y') {


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

            Team* hometeam = new Team(home);
            Team* awayteam = new Team(away);

            footballmatch->addTeam(hometeam);
            footballmatch->addTeam(awayteam);

            char choice;
            bool validChoice = false;

            do {
                cout << "Vill du ange spelarna som spelade i matchen?" << endl;
                cout << "Ange 'j' f�r ja och 'n' f�r nej: ";
                cin >> choice;

                if (choice == 'j') {
                    validChoice = true;

                    int numberofplayers;
                    cout << "Ange antalet spelare du vill l�gga till f�r hemmalaget (max 11 spelare): ";
                    cin >> numberofplayers;

                    for (int i = 0; i < numberofplayers; i++) {
                        string name;
                        int age;

                        cout << "Ange spelare " << i + 1 << "s namn: ";
                        cin >> name;

                        cout << "Ange spelare " << i + 1 << "s �lder: ";
                        cin >> age;

                        if (cin.fail() || age <= 0) {
                            cout << "Ogiltig �lder. Skrive in namnet och �ldern igen." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            i--;
                            continue;
                        }

                        FootballPlayer* player = new FootballPlayer(name, age);
                        hometeam->addPlayer(player);
                    }

                    int numberofplayersforteam2;
                    cout << "Ange antalet spelare du vill l�gga till f�r bortalaget (max 11 spelare): ";
                    cin >> numberofplayersforteam2;

                    for (int i = 0; i < numberofplayersforteam2; i++) {
                        string name;
                        int age;

                        cout << "Ange spelare " << i + 1 << "s namn: ";
                        cin >> name;

                        cout << "Ange spelare " << i + 1 << "s �lder: ";
                        cin >> age;

                        if (cin.fail() || age <= 0) {
                            cout << "Ogiltig �lder. Ange en giltig �lder." << endl;
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
                cout << "Vill du l�gga till domarenamn? Ange 'j' f�r ja och 'n' f�r nej: ";
                cin >> refereeChoice;
                cin.ignore();

                if (refereeChoice == 'j') {
                    cout << "Skriv in domarens namn: ";
                    string refereeName;
                    getline(cin, refereeName);
                    ref = new MatchRefere(refereeName);
                    break;
                }
                else if (refereeChoice == 'n')
                {
                    break;

                }
                else {
                    cout << "not valid choice enter again" << endl;
                }
            } while (true);


            cout << "V�lja namn p�  filen som kommer att spara informationen du anger:  " << endl;
            string textname;
            getline(cin, textname);
            ofstream newfilw(textname + ".txt");
            if (newfilw.is_open()) {
                string line;
                newfilw << "-----------------------------------" << endl;

                newfilw << "Match: " << footballmatch->homevsaway() << endl;
                newfilw << "Stadium: " << footballmatch->getstadium() << endl;
                newfilw << "Resultaten: " << footballmatch->getscore() << endl;
                newfilw << "Datum: " << footballmatch->getdate() << endl;
                newfilw << "Domaren: ";
                newfilw << ref->toString() << endl;

                newfilw << "Hemma lagest spelare: " << endl;
                newfilw << hometeam->returnallpayer() << endl;
                newfilw << "Borta lagets Spelare: " << endl;
                newfilw << awayteam->returnallpayer() << endl;
                newfilw << "-----------------------------------" << endl;

                newfilw.close();
            }

            delete footballmatch;
            delete hometeam;
            delete awayteam;
            delete ref;
        }
        else if (program == 's') {
            string textnamn;
            cout << "Ange filnamnet p� filen: ";
            getline(cin, textnamn);

            ifstream file(textnamn + ".txt");
            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    cout << line << endl;
                }
                file.close();
            }
            else {
                cout << "Kunde inte inte filen, ta menyval (s) igen och ange en fil som existerar." << endl;
            }
        }
        else if (program == 'q') {
            cout << "Avslutar programmet." << endl;
            break;
        }
        else {
            cout << "Ogiltigt val. F�rs�k igen." << endl;
        }
    } while (true);

    return 0;
}