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
//        std::cout << "V�lj ett alternativ:\n";
//        std::cout << "'y' f�r att ange fotbollsmatchers reultat och detaljer.\n";
//        std::cout << "'s' f�r att l�sa en fil.\n";
//        std::cout << "'q' f�r att avsluta programmet.\n";
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
//                std::cout << "Ange 'j' f�r ja och 'n' f�r nej: ";
//                std::cin >> choice;
//
//                if (choice == 'j') {
//                    validChoice = true;
//
//                    int numberofplayers;
//                    std::cout << "Ange antalet spelare du vill l�gga till f�r hemmalaget (max 11 spelare): ";
//                    std::cin >> numberofplayers;
//
//                    for (int i = 0; i < numberofplayers; i++) {
//                        std::string name;
//                        int age;
//
//                        std::cout << "Ange spelare " << i + 1 << "s namn: ";
//                        std::cin >> name;
//
//                        std::cout << "Ange spelare " << i + 1 << "s �lder: ";
//                        std::cin >> age;
//
//                        if (std::cin.fail() || age <= 0) {
//                            std::cout << "Ogiltig �lder. Skrive in namnet och �ldern igen." << std::endl;
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
//                    std::cout << "Ange antalet spelare du vill l�gga till f�r bortalaget (max 11 spelare): ";
//                    std::cin >> numberofplayersforteam2;
//
//                    for (int i = 0; i < numberofplayersforteam2; i++) {
//                        std::string name;
//                        int age;
//
//                        std::cout << "Ange spelare " << i + 1 << "s namn: ";
//                        std::cin >> name;
//
//                        std::cout << "Ange spelare " << i + 1 << "s �lder: ";
//                        std::cin >> age;
//
//                        if (std::cin.fail() || age <= 0) {
//                            std::cout << "Ogiltig �lder. Ange en giltig �lder." << std::endl;
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
//                std::cout << "Vill du l�gga till domarenamn? Ange 'j' f�r ja och 'n' f�r nej: ";
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
//            std::cout << "V�lja namn p� filen som kommer att spara informationen du anger:  " << std::endl;
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
//            std::cout << "Ange filnamnet p� filen: ";
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
//            std::cout << "Ogiltigt val. F�rs�k igen." << std::endl;
//        }
//    } while (true);
//
//
//}
