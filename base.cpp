#include <string>
#include "base.h"

//default constructor (unused)
BaseConvert::BaseConvert(){

    baseFrom = 10;
    baseTo = 2;
}

BaseConvert::BaseConvert(int base1, int base2){

    baseFrom = base1;
    baseTo = base2;
}

std::string BaseConvert::operator()(std::string input) const{

    int inputInBaseTen;
    std::string baseTenInputInCustomBase;
    std::string result;

    /*
    if(baseFrom == 10){
        inputInBaseTen = stoi(input);
    } else {*/
        inputInBaseTen = ToBaseTen(input);
    /*}*/

    if(inputInBaseTen == -1){
        return "Input (" + input + ") not valid in base (" + std::to_string(baseFrom) + ")";
    }

    if(baseTo == 10){
        baseTenInputInCustomBase = std::to_string(inputInBaseTen);
    } else {
        baseTenInputInCustomBase = ToCustomBase(inputInBaseTen);
    }

    result = baseTenInputInCustomBase;
    return result;
}

int BaseConvert::ToBaseTen(std::string input) const{

    std::string remainingString = input;
    char lastChar = '0';
    int lastDigit = 0;
    int basePower = 1;
    int output = 0;

    while(remainingString.size() > 0){
        lastChar = remainingString.back();
        remainingString.pop_back();

        lastDigit = lastChar - '0';
        if(lastDigit > 9){
            lastDigit -= 7;
        }

        if(lastDigit >= baseFrom){
            return -1;
        }

        output += lastDigit * basePower;
        basePower *= baseFrom;
    }

    return output;
}

std::string BaseConvert::ToCustomBase(int input) const{

    int original = input;
    int quotient = 0;
    int remainder = 0;
    std::string output = "";

    while(original != 0){

        quotient = 0;

        while(original - baseTo >= 0){

            original -= baseTo;
            quotient++;
        }

        remainder = original;
        original = quotient;

        if(remainder < 10){
            output.push_back('0' + remainder);
        } else {
            output.push_back('0' + remainder + 7);
        }
    }

    std::reverse(output.begin(), output.end());

    return output;
}
