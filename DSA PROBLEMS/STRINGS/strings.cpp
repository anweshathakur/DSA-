#include <iostream>
#include <string>
using namespace std;

int main() {

    string str;
    cout << "enter a string: ";
    getline (cin , str);

    // convert to uppercase
    for (int i=0;  i < str.length() ; ++i){

        str[i] = toupper(str[i]);

    }
    cout << str << endl;
    

}