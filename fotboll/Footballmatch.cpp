//#include "FootballMatch.h"
//
//FootballMatch::FootballMatch(const std::string& matchDate, const std::string& matchStadium, const std::string& matchScore)
//    : date(matchDate), stadium(matchStadium), score(matchScore), numOfTeams(0) {
//    for (int i = 0; i < MAX_TEAMS; ++i) {
//        teams[i] = nullptr;
//    }
//}
//
//FootballMatch::~FootballMatch() {
//    for (int i = 0; i < MAX_TEAMS; i++) {
//        delete teams[i];
//    }
//}
//
//void FootballMatch::addTeam(Team* team) {
//    if (numOfTeams < MAX_TEAMS) {
//        teams[numOfTeams++] = new Team(*team);
//    }
//    else {
//        std::cout << "Cannot add more teams" << std::endl;
//    }
//}
//
//std::string FootballMatch::homevsaway() {
//    return teams[0]->getname() + " vs " + teams[1]->getname();
//}
//
//std::string FootballMatch::getdate() {
//    return date;
//}
//
//std::string FootballMatch::getscore() {
//    return score;
//}
//
//std::string FootballMatch::getstadium() {
//    return stadium;
//}
//
//std::string FootballMatch::gethometemaplayers() {
//    return teams[0]->returnallpayer();
//}
//
//std::string FootballMatch::getawaytemaplayers() {
//    return teams[1]->returnallpayer();
//}
//
//void FootballMatch::displayMatchInfo() const {
//    if (numOfTeams == MAX_TEAMS) {
//        std::cout << teams[0]->getname() << " vs " << teams[1]->getname() << std::endl;
//        std::cout << "Date: " << date << ", Stadium: " << stadium << ", Score: " << score << std::endl;
//
//        teams[0]->showallplayers();
//        std::cout << std::endl;
//        teams[1]->showallplayers();
//    }
//    else {
//        std::cout << "Match is not fully set" << std::endl;
//    }
//}
