#include <vector>
#include <iostream>

using namespace std;

vector<int> nextSeq(vector<int> s){
    vector<int> result;
    if(s.size() == 0){
        return s;
    }
    if(s.size() == 1){
        result.push_back(1);
        result.push_back(s[0]);
    }
    int currRunCount = 1;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] == s[i+1] ){
            currRunCount += 1;
        }
        else{
            result.push_back(currRunCount);
            result.push_back(s[i]);
            currRunCount = 1;
        }
    }
    result.push_back(currRunCount);
    result.push_back(s[s.size()-1]);

    return result;
}

int main(){
    vector<int> curr = {3,1,2,2,1,1};
    vector<int> next;
    next = nextSeq(curr);

    for(auto it: next){
        cout << it;
    }
    cout << endl;

}