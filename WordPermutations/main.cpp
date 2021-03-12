//UNFINISHED

// given an input word, return a vector of string
// containing all permutations of letters in word

// example: cat should return
// [act,atc,cat,cta,tac,tca]

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> getPermutations(string str)
{
    vector<string> perms;
    // base case
    if (str.size() == 0)
    {
        perms.push_back("");
        return perms;
    }
    // for each character in string, remove it and find all permutations of remaining substring
    for (int i = 0 ; i < str.size(); i++ )
    {
        char currChar = str.at(i);
        string shortstr = str.erase(i,1);
        
        vector<string> smallerPerms = getPermutations(shortstr);
        for (auto itPerm = smallerPerms.begin(); itPerm < smallerPerms.end(); itPerm++)
        {
            string currPerm = *itPerm;
            //add removed character back in front of smaller permutations
            perms.push_back(currChar + currPerm);

        }
    }
    return perms;
}

int main()
{
    string str = "cat";
    vector<string> permutations = getPermutations(str);

    for (auto it = permutations.begin(); it < permutations.end(); it++)
    {
        cout << (*it) << endl;
    }

    return 0;
}