#include <iostream>
#include <string>

using namespace std;


void makeLowerCase(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {  
        s.at(i) = tolower(s.at(i));
    }
}

string compressSequence(string s)
{
    char ch = s.at(0);
    int length = s.length();
    return (ch + to_string(length));
}

string compress(string s)
{
    string compressedString;
    string contiguous;
    for(int i = 0; i< s.length(); i++)
    {
        contiguous.insert(contiguous.end(),s[i]);
        if( s[i] != s[i+1] )
        {
            compressedString.append(compressSequence(contiguous));
            contiguous = "";
        }
    }
    return compressedString;
}

int main()
{
    string str = "uunIiiiqUeeeee";
    makeLowerCase(str);
    cout << str << endl;
    cout << compress(str) << endl;
}
