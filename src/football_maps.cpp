#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

class Team {
    public:
    std::string name;
    int points;
    int goals_scored;
    int goals_conceded;

    Team(std::string name_arg = "None", int points_arg = 0, int goals_scored_arg = 0, int goals_conceded_arg = 0) {
        name = name_arg;
        points = points_arg;
        goals_scored = goals_scored_arg;
        goals_conceded = goals_conceded_arg;
    }
};


int main() {

    std::map<std::string, Team> teams;

    int total_teams = 4;
    int total_matches = 6;

    for (auto it = teams.begin(); it != teams.end(); it++) {
        std::cout <<"key: " << it->first << ";   team name:" << it->second.name <<std::endl;
    }

    for(uint i = 0; i < total_matches; i++) {
        std::string team1;
        std::string team2;
        int score1;
        int score2;     
        std::string discard_char;

        std::cin >> team1 >> score1 >> discard_char >> score2 >> team2;

        if (teams.find(team1) == teams.end())
            teams.insert(std::pair<std::string, Team>(team1, Team(team1, 0, 0, 0)));
        if (teams.find(team2) == teams.end())
            teams.insert(std::pair<std::string, Team>(team2, Team(team2, 0, 0, 0)));
        
        teams[team1].goals_scored += score1;
        teams[team1].goals_conceded += score2;
        teams[team2].goals_scored += score2;
        teams[team2].goals_conceded += score1;
        if (score1 > score2) 
            teams[team1].points += 3;         
        else if (score1 < score2) 
            teams[team2].points += 3;         
        else {
            teams[team1].points += 1;
            teams[team2].points += 1;
        }
    }

    // Create new vector with all the map values so that we can sort teams by points
    std::vector<Team> sorted_teams;
    sorted_teams.reserve(teams.size());
    for (auto it = teams.begin(); it != teams.end(); it++) {
        sorted_teams.push_back(it->second);
    }

    std::sort(sorted_teams.begin(), sorted_teams.end(), [](Team a, Team b) {return a.points > b.points;});

    for (auto i : sorted_teams) {
        std::cout << i.name << " " << i.points << " " << i.goals_scored << " " << i.goals_conceded << std::endl;
    }
    
    return 0;
}

/* Lessons learned:
When using std::find and it returns an interator to the end of the vector, it means that the element was not found.
Also, if you add/remove an element to the list, the iterator to the found item is invalidated. 
So you need to call std::find if the list is changed.
*/
