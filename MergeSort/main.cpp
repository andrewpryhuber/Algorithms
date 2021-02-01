#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void print(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

// merge sorted arrays
vector<int> merge(vector<int> a, vector<int> b)
{
    vector<int> mergedVectors;

    int acounter = 0;
    int bcounter = 0;

    while (acounter < a.size() && bcounter < b.size())
    {
        if (a[acounter] <= b[bcounter])
        {
            mergedVectors.push_back(a[acounter]);
            acounter += 1;
        }
        else
        {
            mergedVectors.push_back(b[bcounter]);
            bcounter += 1;
        }
    }

    while (acounter < a.size())
    {
        mergedVectors.push_back(a[acounter]);
        acounter += 1;
    }

    while (bcounter < b.size())
    {
        mergedVectors.push_back(b[bcounter]);
        bcounter += 1;
    }

    return mergedVectors;
}

vector<int> sort(vector<int> vect)
{
    if(vect.size()<= 1) 
    {
        return vect;
    }

    int midpoint = floor(vect.size() / 2);
    vector<int> firsthalf;
    vector<int> secondhalf;

    for (int i = 0; i < midpoint; i++)
    {
        firsthalf.push_back(vect[i]);
    }

    for (int i = midpoint; i < vect.size(); i++)
    {
        secondhalf.push_back(vect[i]);
    }

    return merge(sort(firsthalf), sort(secondhalf));
}

int main()
{
    vector<int> vect;
    vect.push_back(1);
    vect.push_back(3);
    vect.push_back(5);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(4);
    vect.push_back(6);

    print(vect);
    print(sort(vect));
}
