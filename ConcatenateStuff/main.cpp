#include <iostream>
#include <string>
#include <vector>

using namespace std;

string concatenate(vector<string> strings){
    string allStrings = "";
    for(int i = 0; i < strings.size(); i ++){
        allStrings = allStrings + strings.at(i); 
    }
    return allStrings;
}

int main(){
     vector<string> strings;
     strings.push_back("This ");
     strings.push_back("is a ");
     strings.push_back("string.");
     cout << concatenate(strings) << endl;
}

