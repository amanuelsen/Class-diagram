#include "menu.h"


void menu()
{
    
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
            int num;
            std::cout << "Enter how many matches you want the save?: ";
            std::cin >> num;
            std::cin.ignore();
            Resulthandler numofmatch(num);
            // h�r ska jag l�gga till result handler
            for (int k = 0;k < num; k++) {
                std::string name, date, stadium, result, score;
                int division;

                std::cout << "Enter match name: ";
                std::getline(std::cin, name);

                std::cout << "Enter match division: ";
                std::cin >> division;
                std::cin.ignore(); // Ignore the newline character left in the buffer

                std::cout << "Enter match date: ";
                std::getline(std::cin, date);

                std::cout << "Enter match stadium: ";
                std::getline(std::cin, stadium);



                std::cout << "Enter match score: ";
                std::getline(std::cin, score);

                Match match(name, division, date, stadium, score);

                std::string home, away;
                std::cout << "Ange hemmalaget: ";
                std::getline(std::cin, home);


                std::cout << "Ange bortalaget: ";
                std::getline(std::cin, away);

                Team hometeam(home);
                Team awayteam(away);



                match.addTeam(hometeam);
                match.addTeam(awayteam);



                char playerChoice;
                bool validPlayerChoice = false;

                do {
                    std::cout << "Vill du ange spelarna som spelade i matchen?" << std::endl;
                    std::cout << "Ange 'j' f�r ja och 'n' f�r nej: ";
                    std::cin >> playerChoice;

                    if (playerChoice == 'j' || playerChoice == 'n') {


                        if (playerChoice == 'j') {
                            int numberOfPlayers;
                            std::cout << "Enter the number of players you want to add (max 11 players): ";
                            std::cin >> numberOfPlayers;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                            for (int i = 0; i < numberOfPlayers; i++) {
                                std::string name, personnummer;
                                int age, position, jerseyNr, goalsScored;

                                std::cout << "Enter player " << i + 1 << "'s name: ";
                                std::getline(std::cin, name);

                                std::cout << "Enter player " << i + 1 << "'s age: ";
                                std::cin >> age;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                if (std::cin.fail() || age <= 0) {
                                    std::cout << "Invalid age. Please enter the name and age again." << std::endl;
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    i--;
                                    continue;
                                }

                                std::cout << "Enter player " << i + 1 << "'s personnummer: ";
                                std::getline(std::cin, personnummer);

                                std::cout << "Enter player " << i + 1 << "'s position: ";
                                std::cin >> position;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                std::cout << "Enter player " << i + 1 << "'s jersey number: ";
                                std::cin >> jerseyNr;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                std::cout << "Enter player " << i + 1 << "'s goals scored: ";
                                std::cin >> goalsScored;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                Player* player = new Player(name, age, personnummer, position, jerseyNr, goalsScored);
                                // Assuming the 'hometeam' object is available
                                hometeam.addPlayer(player);
                            }
                            break;
                        }
                        else if (playerChoice == 'n')
                        {
                            break;

                        }

                    }
                    else {
                        std::cout << "Ogiltigt val. Ange 'j' eller 'n'." << std::endl;
                    }
                } while (true);

                char refereeChoice;
                std::unique_ptr<Referees> ref(new Referees());

                do {
                    std::cout << "Do you want to add the referee's info? Enter 'j' for yes and 'n' for no: ";
                    std::cin >> refereeChoice;
                    std::cin.ignore();

                    if (refereeChoice == 'j') {
                        std::string refereeName, personnummer;
                        int age, yearsExperience, highestDivision;

                        std::cout << "Enter the referee's name: ";
                        std::getline(std::cin, refereeName);

                        std::cout << "Enter the referee's age: ";
                        std::cin >> age;
                        std::cin.ignore();

                        std::cout << "Enter the referee's personnummer: ";
                        std::getline(std::cin, personnummer);

                        std::cout << "Enter the referee's years of experience: ";
                        std::cin >> yearsExperience;
                        std::cin.ignore();

                        std::cout << "Enter the referee's highest division: ";
                        std::cin >> highestDivision;
                        std::cin.ignore();
                        //match.addReferee( age, personnummer, yearsExperience, highestDivision, refereeName);
                        ref = std::make_unique<Referees>( age, personnummer, yearsExperience, highestDivision, refereeName);
                        numofmatch.addMatch(match);
                    }
                    else if (refereeChoice == 'n') {
                        break;
                    }
                    else
                    {
                        std::cout << "Invalid choice. Please enter 'j' or 'n'." << std::endl;

                    }
                } while (refereeChoice != 'n' && refereeChoice != 'j');
            }

            /*std::cout << "Ange namn p� filen f�r att spara informationen: ";
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
            }*/

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
}
