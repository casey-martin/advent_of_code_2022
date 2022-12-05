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
//X lose
//Y draw 
//Z win

unordered_map<string, int> RPS_VALUE = {
    {"A", 1},
    {"B", 2},
    {"C", 3}
};

unordered_map<string, int> SCORE = {
    {"X", 0},
    {"Y", 3},
    {"Z", 6}
};


unordered_map<string, int> RPS_INDEX = {
    {"A", 0},
    {"B", 1},
    {"C", 2},
    {"X", 0},
    {"Y", 1},
    {"Z", 2}
};

string CHOICE_MATRIX[3][3] = {
    {"C", "A", "B"}, // rock
    {"A", "B", "C"}, // paper
    {"B", "C", "A"}  // scissors
};

int rps(string opp, string outcome)
{
    int outcome_score = SCORE[outcome];
    string choice = CHOICE_MATRIX [RPS_INDEX[opp]] [RPS_INDEX[outcome]];
    int choice_score = RPS_VALUE[choice];
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
            char outcomeChar = str.at(2);
            string opp;
            string outcome;
            opp += oppChar;        // there's likely a better way to do this
            outcome += outcomeChar;

            int outcome_score = rps(opp, outcome);
            strat_score += outcome_score;
        }
        cout << strat_score << endl;
        return 0;
    }
}
