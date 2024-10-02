#include <iostream>
#include <string>
using namespace std; //Global declaration to use directive standard (std)

// Function to encrypt the text using the given key
string encrypt(string text, int key) {
    string encryptedText = "";
    
    // Loop through each character in the text
    for (char c : text) {
        // Check if character is an uppercase letter
        if (isupper(c)) {
            encryptedText += char(int(c + key - 'A') % 26 + 'A');
        }
        // Check if character is a lowercase letter
        else if (islower(c)) {
            encryptedText += char(int(c + key - 'a') % 26 + 'a');
        }
        // If not a letter, just add the original character
        else {
            encryptedText += c;
        }
    }
    return encryptedText;
}

// Function to decrypt the text using the given key
string decrypt(string text, int key) {
    string decryptedText = "";
    
    // Loop through each character in the text
    for (char c : text) {
        // Check if character is an uppercase letter
        if (isupper(c)) {
            decryptedText += char((int(c - key - 'A' + 26) % 26) + 'A');
        }
        // Check if character is a lowercase letter
        else if (islower(c)) {
            decryptedText += char((int(c - key - 'a' + 26) % 26) + 'a');
        }
        // If not a letter, just add the original character
        else {
            decryptedText += c;
        }
    }
    return decryptedText;
}

int main() {
    string text;
    int flag, key;

    // Take input from the console
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter flag (0 for encryption, 1 for decryption): ";
    cin >> flag;
    cout << "Enter key (positive integer): ";
    cin >> key;

    // Check the flag and perform the corresponding operation
    if (flag == 0) {
        // Encrypt the text
        string encryptedText = encrypt(text, key);
        cout << "Encrypted text: " << encryptedText << endl;
    } else if (flag == 1) {
        // Decrypt the text
        string decryptedText = decrypt(text, key);
        cout << "Decrypted text: " << decryptedText << endl;
    } else {
        cout << "Invalid flag. Please enter 0 for encryption or 1 for decryption." << endl;
    }

    return 0;
}
