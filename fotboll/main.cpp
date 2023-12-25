#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include "player.h"
#include "HandleMatch.h"
#include "Referees.h"

using namespace std;

int main() {
    char program;

    do {
        std::cout << "V�lj ett alternativ:\n";
        std::cout << "'y' f�r att ange fotbollsmatchers reultat och detaljer.\n";
        std::cout << "'s' f�r att l�sa en fil.\n";
        std::cout << "'q' f�r att avsluta programmet.\n";

        while (true) {
            std::cin >> program;
            std::cin.ignore();

            if (program == 'y' || program == 's' || program == 'q') {
                break; 
            }
            else {
                std::cout << "Ogiltigt val. F�rs�k igen.\n";
            }
        }

        if (program == 'y') {
            std::string date, stadium, result;
            std::cout << "Ange matchens datum: ";
            std::getline(std::cin, date);

            std::cout << "Ange matchens arena: ";
            std::getline(std::cin, stadium);

            std::cout << "Ange matchresultat: ";
            std::getline(std::cin, result);

            FootballMatch* footballmatch = new FootballMatch(date, stadium, result);

            std::string home, away;
            std::cout << "Ange hemmalaget: ";
            std::getline(std::cin, home);

            std::cout << "Ange bortalaget: ";
            std::getline(std::cin, away);

            Team* hometeam = new Team(home);
            Team* awayteam = new Team(away);

            footballmatch->addTeam(hometeam);
            footballmatch->addTeam(awayteam);

            char playerChoice;
            bool validPlayerChoice = false;

            do {
                std::cout << "Vill du ange spelarna som spelade i matchen?" << std::endl;
                std::cout << "Ange 'j' f�r ja och 'n' f�r nej: ";
                std::cin >> playerChoice;

                if (playerChoice == 'j' || playerChoice == 'n') {
                    break;

                    if (playerChoice == 'j') {
                        int numberofplayers;
                        std::cout << "Ange antalet spelare du vill l�gga till f�r hemmalaget (max 11 spelare): ";
                        std::cin >> numberofplayers;

                        for (int i = 0; i < numberofplayers; i++) {
                            std::string name;
                            int age;

                            std::cout << "Ange spelare " << i + 1 << "s namn: ";
                            std::cin >> name;

                            std::cout << "Ange spelare " << i + 1 << "s �lder: ";
                            std::cin >> age;

                            if (std::cin.fail() || age <= 0) {
                                std::cout << "Ogiltig �lder. Skriv in namnet och �ldern igen." << std::endl;
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                i--;
                                continue;
                            }

                            FootballPlayer* player = new FootballPlayer(name, age);
                            hometeam->addPlayer(player);
                        }
                    }
                }
                else {
                    

                    std::cout << "Ogiltigt val. Ange 'j' eller 'n'." << std::endl;
                }
            } while (true);

            char refereeChoice;
            Referees* ref = new Referees();

            do {
                std::cout << "Vill du l�gga till domarenamn? Ange 'j' f�r ja och 'n' f�r nej: ";
                std::cin >> refereeChoice;
                std::cin.ignore();

                if (refereeChoice == 'j' || refereeChoice == 'n') {
                    if (refereeChoice == 'j') {
                        std::cout << "Skriv in domarens namn: ";
                        std::string refereeName;
                        std::getline(std::cin, refereeName);
                        ref->setRefName(refereeName);
                    }
                }
                else {
                    std::cout << "Ogiltigt val. Ange 'j' eller 'n'." << std::endl;
                }
            } while (refereeChoice != 'j' && refereeChoice != 'n');

            std::cout << "Ange namn p� filen f�r att spara informationen , (OBS! om namnen finns redan s� kommer den att ers�ttas med den nya informationen): ";
            std::string textname;
            std::getline(std::cin, textname);
            std::ofstream newfile(textname + ".txt");
            if (newfile.is_open()) {
                newfile << "-----------------------------------" << std::endl;

                newfile << "Match: " << footballmatch->homevsaway() << std::endl;
                newfile << "Stadium: " << footballmatch->getstadium() << std::endl;
                newfile << "Resultat: " << footballmatch->getscore() << std::endl;
                newfile << "Datum: " << footballmatch->getdate() << std::endl;
                newfile << "Domaren: " << ref->getRefName() << std::endl;

                newfile << "Hemmalagets spelare: " << std::endl;
                newfile << hometeam->returnallpayer() << std::endl;
                newfile << "Bortalagets spelare: " << std::endl;
                newfile << awayteam->returnallpayer() << std::endl;

                newfile << "-----------------------------------" << std::endl;

                newfile.close();
            }

            delete footballmatch;
            delete hometeam;
            delete awayteam;
            delete ref;

        }
        else if (program == 's') {
            std::cout << "Ange filnamnet p� filen: ";
            std::string textnamn;
            std::cin >> textnamn;

            std::ifstream file(textnamn + ".txt");
            if (file.is_open()) {
                std::string line;
                while (getline(file, line)) {
                    std::cout << line << std::endl;
                }
                file.close();
            }
            else {
                std::cout << "Kunde inte �ppna filen. F�rs�k igen med ett existerande filnamn." << std::endl;
            }
        }
        else if (program == 'q') {
            std::cout << "Avslutar programmet." << std::endl;
            break;
        }
    } while (true);

    return 0;
}
