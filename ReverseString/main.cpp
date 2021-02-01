#include <iostream>
#include <string>

using namespace std;

void reverse(string& str){
    int backward = str.length() - 1;
    int forward = 0;

    while (forward < backward){
        cout << forward << " and " << backward << endl;
        char temp = str[forward];
        str[forward] = str[backward];
        str[backward] = temp;
        forward += 1;
        backward -= 1;
    }
    
}

int main(){
    string str = "Astring";

    cout << str << endl;
    reverse(str);
    cout << str << endl;
}

