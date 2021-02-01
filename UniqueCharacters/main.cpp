#include <iostream>
#include <string>
#include <set>

using namespace std;

bool hasUniqueChars(string str){
    bool result = true;
    set<char> foundChars;
    for(int i = 0; i < str.length() ; i++){
        if( foundChars.find(str[i]) == foundChars.end() ){
            foundChars.insert(str[i]);
        }
        else {
            result = false;
            break;
        }
    }

    return result;
}

int main(){
    string str = "has unique";
    cout << hasUniqueChars(str) << endl;
}