#include <iostream>
#include <cmath>
using namespace std;

// Function to find gcd
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function for modular exponentiation
long long power(long long base, long long exp, long long mod) {
    long long result = 1;

    while (exp > 0) {
        result = (result * base) % mod;
        exp--;
    }

    return result;
}

int main() {
    int p = 3, q = 11;

    // Step 1: Calculate n
    int n = p * q;

    // Step 2: Calculate phi
    int phi = (p - 1) * (q - 1);

    // Step 3: Choose e
    int e;
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1)
            break;
    }

    // Step 4: Calculate d
    int d;
    for (d = 1; d < phi; d++) {
        if ((d * e) % phi == 1)
            break;
    }

    cout << "Public Key (e, n): (" << e << ", " << n << ")" << endl;
    cout << "Private Key (d, n): (" << d << ", " << n << ")" << endl;

    // Message
    int msg = 7;

    // Encryption
    long long encrypted = power(msg, e, n);
    cout << "Encrypted Message: " << encrypted << endl;

    // Decryption
    long long decrypted = power(encrypted, d, n);
    cout << "Decrypted Message: " << decrypted << endl;

    return 0;
}