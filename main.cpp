#include <iostream>
#include <string>
#include "base.h"

using namespace std;

int main(int argc, char* argv[]){

    //we want to see the format "./convert 123 from base 10 to base 2
    //and ./convert 123 from base 10 to base 2 repeat

/*
    //agrv test
    for(int i = 0; i < argc; i++){
        cout << "argv[" << i << "] = " << argv[i] << endl;
    }
*/

    //init
    bool repeating = false;
    string input = "1";
    int base1 = 10;
    int base2 = 2;

    //need to do some basic validity checks
    if(argc < 8){
        cout << "More arguments needed" << endl;
        cout << "Format: convert X from base Y to base Z (repeat)" << endl;
        return 1;
    } else if (argc > 9){
        cout << "Too many arguments" << endl;
        cout << "Format: convert X from base Y to base Z (repeat)" << endl;
        return 1;
    }

    if(strcmp(argv[2], "from") == 0 && strcmp(argv[3], "base") == 0 && 
        strcmp(argv[5], "to") == 0 && strcmp(argv[6], "base") == 0){
    } else {
        cout << "Invalid syntax" << endl;
        cout << "Format: convert X from base Y to base Z (repeat)" << endl;
        return 1;
    }

    if(argc == 9){
        if(strcmp(argv[8], "repeat") == 0){
            repeating = true;
        } else {
            cout << "Invalid syntax on \"repeat\"" << endl;
            cout << "Format: convert X from base Y to base Z (repeat)" << endl;
            return 1;
        }
    }

    input = argv[1];
    base1 = atoi(argv[4]);
    base2 = atoi(argv[7]);

/*
    //argument value test
    cout << "number = " << number << endl;
    cout << "base1 = " << base1 << endl;
    cout << "base2 = " << base2 << endl;
*/

    if(base1 < 1 || base2 < 1){
        cout << "Invalid base" << endl;
        return 1;
    }

    //set up the base-convert functor
    BaseConvert convert(base1, base2);

    cout << "Input: " << input << endl;
    
    if(repeating){
        while(repeating){
            cout << "Result: " << convert(input) << endl;
            cout << endl << "Next input: ";
            cin >> input;
            if(input == "exit" || input == "quit" || input == "stop"){
                repeating = false;
                cout << "Repeat terminated" << endl;
            }
        }
    } else {
        cout << "Result: " << convert(input) << endl;
    }

    return 0;
}
