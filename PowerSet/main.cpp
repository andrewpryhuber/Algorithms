#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

vector<char> intToStr(int i, const vector<char> &s)
{
    vector<char> result;
    int index = 0;
    for (int j = i; j>0; j = j >> 1)
    {
        if ( (j & 1) == 1 )
        {
            result.push_back(s[index]);
        }
        index++;
    }
    return result;
}

vector<vector<char>> pSet(const vector<char> &s)
{
    vector<vector<char>> result;
    int maxSize = 1 << s.size();
    for (int i = 0; i < maxSize; i++)
    {
        result.push_back(intToStr(i, s));
    }
    return result;
}

int main()
{
    vector<char> s = {'t', 'e', 's', 't'};
    vector<vector<char>> pset = pSet(s);

    for (auto itR : pset)
    {
        for (auto itC : itR)
        {
            cout << itC;
        }
        cout << endl;
    }
}