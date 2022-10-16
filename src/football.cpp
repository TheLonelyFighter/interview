#include<iostream>
#include<vector>
#include<algorithm>

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

    std::vector<Team> teams;

    int total_teams = 4;
    int total_matches = 6;

    // read scores for each match line by line
    for(uint i = 0; i < total_matches; i++) {
        std::string team1;
        std::string team2;
        int score1;
        int score2;
        std::string discard_char;

        std::cin >> team1 >> score1 >> discard_char >> score2 >> team2;

        // find team1 in teams vector
        auto result1 = std::find_if(teams.begin(), teams.end(), [team1](Team a) {return a.name == team1;});
        
        // add team if it doesn't exist
        if (result1 == teams.end()) {
            teams.push_back(Team(team1, 0, 0, 0));
            std::cout << "Added team " << team1 << std::endl;
        }

        // find team2 in teams vector    
        auto result2 = std::find_if(teams.begin(), teams.end(), [team2](Team a) {return a.name == team2;});

        if (result2 == teams.end()){
            teams.push_back(Team(team2, 0, 0, 0));
            std::cout << "Added team " << team2 << std::endl;
        }

        // since the list could have been modified, 
        // the iterators from the previous std:find_if call were invalidated, 
        // so we need to find the teams again
        result1 = std::find_if(teams.begin(), teams.end(), [team1](Team a) {return a.name == team1;});
        result2 = std::find_if(teams.begin(), teams.end(), [team2](Team a) {return a.name == team2;});

                    
        // update team results
        result1->goals_scored += score1;
        result1->goals_conceded += score2;
        result2->goals_scored += score2;
        result2->goals_conceded += score1;
        if (score1 > score2) 
            result1->points += 3;         
        else if (score1 < score2) 
            result2->points += 3;         
        else {
            result1->points += 1;
            result2->points += 1;
        }
}

    // sort team list in descending order by number of points
    std::sort(teams.begin(), teams.end(), [](Team a, Team b) {return a.points > b.points;});

    std::cout << "\nChampionship results:\n" << std::endl;
    for (auto& i : teams) {
        std::cout << i.name << " " << i.points << " " << i.goals_scored << " " << i.goals_conceded << std::endl;
    }

    return 0;
}

/* Lessons learned:
When using std::find and it returns an interator to the end of the vector, it means that the element was not found.
Also, if you add/remove an element to the list, the iterator to the found item is invalidated. 
So you need to call std::find if the list is changed.
*/
