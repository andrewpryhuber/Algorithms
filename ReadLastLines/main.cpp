#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int k = 3;
    ifstream myfile("file.txt");
    vector<string> allLines;
    string line;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            allLines.push_back(line);
        }
        myfile.close();
    }

    int numLines = allLines.size();

    if (numLines < k)
    {
        k = numLines;
    }
    
    for (int i = numLines - k; i < numLines ; i++)
    {
        cout << allLines.at(i) << endl;
    }
}