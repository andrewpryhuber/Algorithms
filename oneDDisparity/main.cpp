#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// left = [0, 1, 2, 3, 4]
// right = [1000, 0, 1, 2, 3]

// find_disparity(left, right) -> [1, 1, 1, 1, 0]

// left_bad.= [0, 1, 2, 3, 4]
// right_bad = [1, 0, 1, 2, 3]

// disp = x_right - x_left
// depth = 1/disp * basline_length

int main() {
    vector<int> left = {0,1,2,3,4};
    vector<int> right = {1000,0,1,2,3};
    vector<int> disparity;
    int lastRightMatch = 0;
    
    //for each left pixel, compare to right
    for(int leftMatch = 0 ; leftMatch < left.size(); leftMatch++){
        while(lastRightMatch < right.size()) {
            //if pixels match, compute disparity as difference in left and right indices
            if(left[leftMatch] == right[lastRightMatch]){
                disparity.push_back(lastRightMatch - leftMatch);
                lastRightMatch++;
                break;
            }
            lastRightMatch++;
        }

        if(lastRightMatch >= right.size()){
            disparity.push_back(0);
            break;
        }
    }
        
    for(int i = 0; i < disparity.size(); i++){
        cout<< disparity[i] << " " ;
    }
    cout << endl;

    return 0;
}
