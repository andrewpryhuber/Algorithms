#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> returnIndices;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums.at(i) + nums.at(j) == target)
            {
                returnIndices.push_back(i);
                returnIndices.push_back(j);
            }
        }
    }
    return returnIndices;
}

vector<int> twoSumHash(vector<int> &nums, int target)
{
    vector<int> returnIndices;
    map<int,int> searchMap;

    for(int i = 0; i < nums.size(); i ++)
    {
       searchMap.insert(pair<int,int>(nums.at(i), i));
    }

    for(int i = 0; i < nums.size(); i ++)
    {
        int numToFind = nums.at(i) - target;
        if(searchMap.find(numToFind) != searchMap.end() ){
            returnIndices.push_back(i);
            returnIndices.push_back(searchMap.at(numToFind));
        }
    }
    return returnIndices;
}





int main(){
    vector<int> vect {2,11,8,6,7,15};
    int target = 11;
    
    vector<int> indices;

    indices = twoSum(vect,target);
    for(auto it = indices.begin(); it < indices.end(); it++){
        cout << *it << endl;
    }
}