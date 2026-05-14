#include <iostream>
#include <string>
#include <numeric>
using namespace std;

int main()
{
    string data = "IamPeace";
    cout << "DATA :  " << data <<endl;
    // string andData = "";
    cout << "\n\n AND :  ";
    for(int i = 0; i < data.size(); i++){
        char g = data[i] & 31;
        cout << g << " ";
    }
    
    // cout << "\n\n AND :  ";
    
    // string xorData = "";
    cout << "\n\n XOR :  ";
    for(int i = 0; i < data.size(); i++){
        char g = data[i] ^ 32;
        cout << g << " ";
    }
    // cout << "\n\n XOR :  " << andData <<endl;
    cout << char(99);
    

    return 0;
}



// Range

// Type

// Examples

// 0 – 31

// Control Characters

// NULL, TAB, ENTER

// 32

// Space

// ' '

// 33 – 47

// Special Symbols

// ! " # $ % &

// 48 – 57

// Digits

// 0–9

// 58 – 64

// Symbols

// : ; < = > ? @

// 65 – 90

// Uppercase Letters

// A–Z

// 91 – 96

// Symbols

// `[ \ ] ^ _ ``

// 97 – 122

// Lowercase Letters

// a–z

// 123 – 126

// Symbols

// `{

// 127

// DEL

// Delete character