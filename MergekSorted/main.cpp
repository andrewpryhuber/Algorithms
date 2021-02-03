#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> merge(const vector<vector<int>> &A)
{
    //minElements holds smallest element in each vector A[i] as well as position (i,j) in A
    priority_queue<pair<int, pair<int, int>>> minElements;
    vector<int> merged;

    for (int i = 0; i < A.size(); i++)
    {
        minElements.push(make_pair( -A[i][0], make_pair(i, 0) ));
    }

    while (!minElements.empty())
    {
        pair<int,int> minPosition = minElements.top().second;
        merged.push_back(-(minElements.top().first));
        minElements.pop();

        // if vector that contributed min still has elements, push next into minElements
        if(minPosition.second < A[minPosition.first].size() -1 )
        {
            minElements.push(make_pair(-A[minPosition.first][minPosition.second+1], make_pair(minPosition.first, minPosition.second+1) ) );
        }
    }

    return merged;
}

int main(){
    vector<vector<int>> A = {{1,2,5,7} , {1,3,8}, {2,3,4}, {2}};
    vector<int> mergedA = merge(A);

    for(auto it = mergedA.begin(); it != mergedA.end(); it++){
        cout << (*it) << " ";
    }
    cout << endl;
}