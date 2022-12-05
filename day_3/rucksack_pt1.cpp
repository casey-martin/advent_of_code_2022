#include <algorithm>
#include <iostream>
#include <fstream>
#include <set>
#include <stdio.h>
#include <string>
#include <map>

using namespace std;

// Compute the sack priority according to the rules for the value of each character:
// Stolen shameless from Matt Might: 
// reference: https://github.com/mattmight/advent-of-code-2022/blob/main/day-3/rucksack.c
int sack_priority (char c)
{
  if (c >= 'a') 
    return (c - 'a') + 1;

  return (c - 'A') + 27 ;
}

char max_key(
    map<char, int> sampleMap)
{
 
    // Reference variable to help find
    // the entry with the highest value
    pair<char, int> entryWithMaxValue
        = make_pair(0, 0);
 
    // Iterate in the map to find the required entry
    map<char, int>::iterator currentEntry;
    for (currentEntry = sampleMap.begin();
        currentEntry != sampleMap.end();
        ++currentEntry) {
 
        // If this entry's value is more
        // than the max value
        // Set this entry as the max
        if (currentEntry->second
            > entryWithMaxValue.second) {
 
            entryWithMaxValue
                = make_pair(
                    currentEntry->first,
                    currentEntry->second);
        }
    }
 
    return entryWithMaxValue.first;
}


int sack_process (string sack) 
{
    int compart_size = sack.length() / 2;
    string left = sack.substr(0, compart_size);
    string right = sack.substr(compart_size, compart_size);

    map<char, int> left_counts;
    map<char, int> right_counts;
    map<char, int> total_counts;
    // couldn't get set instantiation and operations to work
    //set<char> left_set(left.begin(), left.end());
    //set<char> right_set(right.begin(), right.end());
    //set<char> intersect = set_intersection(left_set, right_set); 

    // get unique elements of left and right compartments.
    for (char c: left)
    {
        left_counts[c]++;
    }
    for (char c: right)
    {
        right_counts[c]++;
    }

    // find set union of both compartments
    for (const auto &myPair : left_counts)
    {
        total_counts[myPair.first]++;
    }
    for (const auto &myPair : right_counts)
    {
        total_counts[myPair.first]++;
    }
    char high_priority = max_key(total_counts);
    int priority_score = sack_priority(high_priority);
    return priority_score;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "usage: " << argv[0] << " <filename>\n";
    }
    else
    {
        ifstream in_file (argv[1]);
        int total_score = 0;
        string str;
        while(getline(in_file, str))
        {
            int out = sack_process(str);
            total_score += out;
            //cout << str << endl;
        }
        cout << total_score << endl;
        return 0;
    }
}
