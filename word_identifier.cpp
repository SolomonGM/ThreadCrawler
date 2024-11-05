#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <cctype>

using namespace std;

// Function to convert a string to lowercase
string toLowerCase(string str) {
    for (char &c : str) {
        c = tolower(c);
    }
    return str;
}

// Function to check if a character is a sentence-ending punctuation
bool isSentenceEnd(char c) {
    return c == '.' || c == '!' || c == '?';
}

int main() {
    ifstream inputFile("test_input.txt"); // Replace with your input file name
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line, word;
    int sentenceCount = 0, wordCount = 0;
    map<string, pair<int, vector<int>>> wordFrequency; // Word -> (Frequency, Positions)
    int position = 0;

    while (getline(inputFile, line)) {
        stringstream lineStream(line);
        char lastChar = '\0';

        while (lineStream >> word) {
            // Check if the last character of the word is a sentence-ending punctuation
            lastChar = word.back();
            if (isSentenceEnd(lastChar)) {
                sentenceCount++;
                word.pop_back(); // Remove the punctuation for word counting
            }

            word = toLowerCase(word); // Make the word lowercase
            if (!word.empty()) {
                wordCount++;
                position++;
                wordFrequency[word].first++;
                wordFrequency[word].second.push_back(position);
            }
        }
    }

    // If the last character in the file was a sentence end, increment the sentence count
    if (isSentenceEnd(lastChar)) {
        sentenceCount++;
    }

    inputFile.close();

    // Output the results
    cout << "Total number of sentences: " << sentenceCount << endl;
    cout << "Total number of words: " << wordCount << endl;
    cout << "Word Frequency and Positions:" << endl;
    for (const auto &entry : wordFrequency) {
        cout << entry.first << ": " << entry.second.first << " times at positions: ";
        for (int pos : entry.second.second) {
            cout << pos << " ";
        }
        cout << endl;
    }

    return 0;
}
