#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc !=3 )
    {
        cout<<"usage: "<< argv[0] <<" <filename> <top n>\n";
    }
    else
    {
        ifstream is(argv[1]);
        int top_n = stoi(argv[2]);
        int current_cal = 0;
        vector<int> values;
        string str;
        
        while(getline(is, str))
        {
            if ( str.length() > 0 )
            {
                int tmp_val = stoi(str);
                current_cal += tmp_val;
            }
            else
            {
                values.push_back(current_cal);
                current_cal = 0;
            }
        }

        values.push_back(current_cal); 
        sort(values.begin(), values.end(), greater<int>());

        
        int top_vals = 0;
        for (int i = 0; i < top_n; i++)
        {
            top_vals += values[i];
        }
        cout << top_vals << endl;

        }
    return 0; 
    }
