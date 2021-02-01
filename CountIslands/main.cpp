#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <iostream>


using namespace std;

void findIsland(int currRow, int currCol, int maxRow, int maxCol, vector<vector<int>> &grid, set<pair<int, int>> &visited)
{
    queue<pair<int, int>> searchList;
    searchList.push(make_pair(currRow, currCol));

    while (!searchList.empty())
    {
        pair<int, int> currPair = searchList.front();
        searchList.pop();
        if (currPair.first < 0 || currPair.first >= maxRow || currPair.second < 0 || currPair.second >= maxCol ||
            visited.find(currPair) != visited.end())
        {
            continue;
        }
        else
        {
            visited.insert(currPair);
            if (grid.at(currPair.first).at(currPair.second) == 1)
            {
                searchList.push(make_pair(currPair.first + 1, currPair.second)); //look down
                searchList.push(make_pair(currPair.first - 1, currPair.second)); //look up
                searchList.push(make_pair(currPair.first, currPair.second + 1)); //look right
                searchList.push(make_pair(currPair.first, currPair.second - 1)); //look left
            }
        }
    }
}

int main()
{
    int islandCount = 0;
    vector<vector<int>> grid{{0, 1, 1, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 1, 1}}; //assume this is rectangle
    set<pair<int, int>> visited;

    int maxRow = grid.size();
    int maxCol = grid.at(0).size();

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.at(i).size(); j++)
        {
            if (visited.find(make_pair(i, j)) == visited.end())
            {
                if (grid.at(i).at(j) == 1)
                {
                    findIsland(i, j, maxRow, maxCol, grid, visited);
                    islandCount++;
                }
                else
                {
                    visited.insert(make_pair(i, j));
                }
            }
        }
    }

    cout << "Number of islands is " << islandCount << endl;
}
