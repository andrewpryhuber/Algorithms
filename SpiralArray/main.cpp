#include <vector>
#include <iostream>
#include <queue>

using namespace std;


bool isInvalid(int r, int c, int n){
    return (r >= n || r < 0 || c < 0 || c >= n);
}

bool isOccupied(int r, int c, const vector<vector<int>>& arr){
    return (arr[r][c] != 0);
}

vector<vector<int>> spiral(int n){
    vector<vector<int>> arr; 
    arr.resize(n,vector<int>(n,0));
    int currRow = 0;
    int currCol = 0;
    int endRow, endCol;
    int nSquare = pow(n,2);

    queue<pair<int,int>> dirs;
    dirs.push(make_pair(0,1)); // right
    dirs.push(make_pair(1,0)); // down
    dirs.push(make_pair(0,-1)); // left
    dirs.push(make_pair(-1,0)); // up

    for(int i = 0; i < nSquare; i ++){
        arr[currRow][currCol] = i+1;

        pair<int,int> nextDir = dirs.front();

        if (isInvalid(currRow + nextDir.first ,currCol + nextDir.second , n)){
            dirs.pop();
            dirs.push(nextDir);
            nextDir = dirs.front();

        }
        else {
            if(isOccupied(currRow + nextDir.first, currCol + nextDir.second,arr)){
                dirs.pop();
                dirs.push(nextDir);
                nextDir = dirs.front();
            } 
        }

        currRow = currRow + nextDir.first;
        currCol = currCol + nextDir.second;
    }
    return arr;
}


int main(){
    vector<vector<int>> test;
    test = spiral(5);

    for(auto& itRow : test){
        for(auto& itCol : itRow){
            cout << itCol ;
        }
        cout << endl;
    }
}