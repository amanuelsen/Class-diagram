//#pragma once
//
//#include "Footballmatch.h"
//#include "Footballplayer.h"
//#include "Match.h"
//#include "MatchReferee.h"
//#include "player.h"
//#include "Referees.h"
//#include "Team.h"
//#include <fstream>
//#include <iostream>
//#include <string>
//#include <limits>
//
////class Handlematch {
////public:
////    int run() {
////       
////};
//
//void run() {
//    char program;
//
//    do {
//        std::cout << "Välj ett alternativ:\n";
//        std::cout << "'y' för att ange fotbollsmatchers reultat och detaljer.\n";
//        std::cout << "'s' för att läsa en fil.\n";
//        std::cout << "'q' för att avsluta programmet.\n";
//        std::cin >> program;
//        std::cin.ignore();
//
//        if (program == 'y') {
//            std::string date, stadium, result;
//            std::cout << "Ange matchens datum: ";
//            std::getline(std::cin, date);
//
//            std::cout << "Ange matchens arena: ";
//            std::getline(std::cin, stadium);
//
//            std::cout << "Ange matchresultat: ";
//            std::getline(std::cin, result);
//
//            FootballMatch* footballmatch = new FootballMatch(date, stadium, result);
//
//            std::string home, away;
//            std::cout << "Ange hemmalaget: ";
//            std::getline(std::cin, home);
//
//            std::cout << "Ange bortalaget: ";
//            std::getline(std::cin, away);
//
//            Team* hometeam = new Team(home);
//            Team* awayteam = new Team(away);
//
//            footballmatch->addTeam(hometeam);
//            footballmatch->addTeam(awayteam);
//
//            char choice;
//            bool validChoice = false;
//
//            do {
//                std::cout << "Vill du ange spelarna som spelade i matchen?" << std::endl;
//                std::cout << "Ange 'j' för ja och 'n' för nej: ";
//                std::cin >> choice;
//
//                if (choice == 'j') {
//                    validChoice = true;
//
//                    int numberofplayers;
//                    std::cout << "Ange antalet spelare du vill lägga till för hemmalaget (max 11 spelare): ";
//                    std::cin >> numberofplayers;
//
//                    for (int i = 0; i < numberofplayers; i++) {
//                        std::string name;
//                        int age;
//
//                        std::cout << "Ange spelare " << i + 1 << "s namn: ";
//                        std::cin >> name;
//
//                        std::cout << "Ange spelare " << i + 1 << "s ålder: ";
//                        std::cin >> age;
//
//                        if (std::cin.fail() || age <= 0) {
//                            std::cout << "Ogiltig ålder. Skrive in namnet och åldern igen." << std::endl;
//                            std::cin.clear();
//                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                            i--;
//                            continue;
//                        }
//
//                        FootballPlayer* player = new FootballPlayer(name, age);
//                        hometeam->addPlayer(player);
//                    }
//
//                    int numberofplayersforteam2;
//                    std::cout << "Ange antalet spelare du vill lägga till för bortalaget (max 11 spelare): ";
//                    std::cin >> numberofplayersforteam2;
//
//                    for (int i = 0; i < numberofplayersforteam2; i++) {
//                        std::string name;
//                        int age;
//
//                        std::cout << "Ange spelare " << i + 1 << "s namn: ";
//                        std::cin >> name;
//
//                        std::cout << "Ange spelare " << i + 1 << "s ålder: ";
//                        std::cin >> age;
//
//                        if (std::cin.fail() || age <= 0) {
//                            std::cout << "Ogiltig ålder. Ange en giltig ålder." << std::endl;
//                            std::cin.clear();
//                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                            i--;
//                            continue;
//                        }
//
//                        FootballPlayer* player = new FootballPlayer(name, age);
//                        awayteam->addPlayer(player);
//                    }
//                }
//                else if (choice == 'n') {
//                    validChoice = true;
//                    break;
//                }
//                else {
//                    validChoice = false;
//                    std::cout << "Ogiltigt val. Ange 'j' eller 'n'." << std::endl;
//                }
//            } while (!validChoice);
//
//            char refereeChoice;
//            Referees* ref = new Referees();
//
//            do {
//                std::cout << "Vill du lägga till domarenamn? Ange 'j' för ja och 'n' för nej: ";
//                std::cin >> refereeChoice;
//                std::cin.ignore();
//
//                if (refereeChoice == 'j') {
//                    std::cout << "Skriv in domarens namn: ";
//                    std::string refereeName;
//                    std::getline(std::cin, refereeName);
//                    ref = new MatchRefere(refereeName);
//                    break;
//                }
//                else if (refereeChoice == 'n') {
//                    break;
//                }
//                else {
//                    std::cout << "not valid choice enter again" << std::endl;
//                }
//            } while (true);
//
//            std::cout << "Välja namn på filen som kommer att spara informationen du anger:  " << std::endl;
//            std::string textname;
//            std::getline(std::cin, textname);
//            std::ofstream newfilw(textname + ".txt");
//            if (newfilw.is_open()) {
//                std::string line;
//                newfilw << "-----------------------------------" << std::endl;
//
//                newfilw << "Match: " << footballmatch->homevsaway() << std::endl;
//                newfilw << "Stadium: " << footballmatch->getstadium() << std::endl;
//                newfilw << "Resultaten: " << footballmatch->getscore() << std::endl;
//                newfilw << "Datum: " << footballmatch->getdate() << std::endl;
//                newfilw << "Domaren: ";
//                newfilw << ref->toString() << std::endl;
//
//                newfilw << "Hemma lagest spelare: " << std::endl;
//                newfilw << hometeam->returnallpayer() << std::endl;
//                newfilw << "Borta lagets Spelare: " << std::endl;
//                newfilw << awayteam->returnallpayer() << std::endl;
//                newfilw << "-----------------------------------" << std::endl;
//
//                newfilw.close();
//            }
//
//            delete footballmatch;
//            delete hometeam;
//            delete awayteam;
//            delete ref;
//        }
//        else if (program == 's') {
//            std::string textnamn;
//            std::cout << "Ange filnamnet på filen: ";
//            std::getline(std::cin, textnamn);
//
//            std::ifstream file(textnamn + ".txt");
//            if (file.is_open()) {
//                std::string line;
//                while (getline(file, line)) {
//                    std::cout << line << std::endl;
//                }
//                file.close();
//            }
//            else {
//                std::cout << "Kunde inte inte filen, ta menyval (s) igen och ange en fil som existerar." << std::endl;
//            }
//        }
//        else if (program == 'q') {
//            std::cout << "Avslutar programmet." << std::endl;
//            break;
//        }
//        else {
//            std::cout << "Ogiltigt val. Försök igen." << std::endl;
//        }
//    } while (true);
//
//
//}
