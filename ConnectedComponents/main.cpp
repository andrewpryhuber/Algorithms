#include <vector>
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

set<pair<int,int>> findComponent(const vector<vector<int>>& M, set<pair<int,int>>& visited, int row, int col, int tol){
    set<pair<int,int>> component;
    visited.insert(row,col);
    component.insert(row,col);
    
    //search up
    if(row >1 && visited.find(make_pair(row-1,col)) == visited.end() ) {
        //if difference within tolerance
        if (abs(M.at(row).at(col) - M.at(row-1).at(col)) < tol) {
            //insert to component and declare visited
            visited.insert(row-1,col);
            component.insert(row-1,col);
        }
    }

    //search down 
    if(row < 4 && visited.find(make_pair(row+1,col)) == visited.end() ) {
        //if difference within tolerance
        if (abs(M.at(row).at(col) - M.at(row+1).at(col)) < tol) {
            //insert to component and declare visited
            visited.insert(row+1,col);
            component.insert(row+1,col);
        }
    }



}





int main(){
    vector<vector<int>> M = {{10,9,1,0,0},{7,3,1,0,0},{1,1,0,0,1},{0,0,0,0,1},{0,0,1,1,0}};
    set<pair<int,int>> visited;
    vector<set<pair<int,int>>> components;
    int tol;

    for(int row = 0; row < 5; row ++){
        for(int col = 0;col < 5;col ++){
            if (visited.find(make_pair(row,col)) == visited.end() )
            {
                components.push_back(findComponent(M, visited, row,col,tol));
            }
            
        }
    }
    // suppose start looking for a connected component at (0,0)
        // do bfs 
        // add pixels to component
        //register pixels as visited

}