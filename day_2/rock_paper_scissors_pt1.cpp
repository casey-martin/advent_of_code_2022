#include <unordered_map>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

//A R 
//B P
//C S
//X R
//Y P
//Z S

unordered_map<string, int> RPS_VALUE= {
    {"X", 1},
    {"Y", 2},
    {"Z", 3}
};

unordered_map<string, int> RPS_INDEX = {
    {"A", 0},
    {"B", 1},
    {"C", 2},
    {"X", 0},
    {"Y", 1},
    {"Z", 2}
};

int SCORE_MATRIX[3][3] = {
    {3, 0, 6},
    {6, 3, 0},
    {0, 6, 3}
};

int rps(string opp, string player)
{
    int choice_score = RPS_VALUE[player];
    int outcome_score = SCORE_MATRIX [RPS_INDEX[player]] [RPS_INDEX[opp]];
    return outcome_score + choice_score;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "usage: " << argv[0] << " <filename>\n";
    }
    else
    {
        ifstream in_file(argv[1]);
        int strat_score = 0;
        string str;

        while(getline(in_file, str))
        {
            char oppChar = str.at(0);
            char playerChar = str.at(2);
            string opp;
            string player;
            opp += oppChar;        // there's likely a better way to do this
            player += playerChar;

            int outcome = rps(opp, player);
            strat_score += outcome;
        }
        cout << strat_score << endl;
        return 0;
    }
}
