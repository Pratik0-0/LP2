#include <iostream>
#include <string>
using namespace std;

// Encryption function
string encrypt(string text, int key)
{
    string result = "";

    for (int i = 0; i < key; i++)
    {
        for (int j = i; j < text.length(); j += key)
        {
            result = result + text[j];
        }
    }

    return result;
}

// Decryption function
string decrypt(string cipher, int key)
{
    int len = cipher.length();
    string result(len, ' ');

    int k = 0;

    for (int i = 0; i < key; i++)
    {
        for (int j = i; j < len; j += key)
        {
            result[j] = cipher[k++];
        }
    }

    return result;
}

int main()
{
    string text, encrypted, decrypted;
    int key;

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter key: ";
    cin >> key;

    // Encryption
    encrypted = encrypt(text, key);
    cout << "Encrypted Text: " << encrypted << endl;

    // Decryption
    decrypted = decrypt(encrypted, key);
    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}