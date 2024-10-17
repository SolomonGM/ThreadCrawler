#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <map>

using namespace std;

// Function to renmove lowercase
string formatWord(const string& word) {
    string formattedWords;
    for (char c : word) {
        if (isalnum(c)) { // Keep only alphanumeric characters
            formattedWords += tolower(c); // Convert to lowercase
        }
    }
    return formattedWords;
}

// Function to count the number of sentences in the document
int countSentences(const string& text) {
    int sentenceCount = 0;
    for (char c : text) {
        if (c == '.' || c == '!' || c == '?') {
            sentenceCount++;
        }
    }
    return sentenceCount;
}

void generateSummary(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open the file." << endl;
        return;
    }

    stringstream buffer;
    buffer << file.rdbuf(); // Read entire file into a stringstream
    string content = buffer.str(); // Store the content in a string

    // Variables for word and sentence count
    int numberOfWords = 0;
    int numberOfSentences = countSentences(content);
    map<string, int> wordFrequency; // Map to hold word frequencies

    // Split content into words and count their frequency
    stringstream ss(content);
    string word;
    while (ss >> word) {
        string cleanedWord = formatWord(word);
        if (!cleanedWord.empty()) {
            wordFrequency[cleanedWord]++;
            numberOfWords++;
        }
    }

    // Close the file
    file.close();

    // Output the summary
    cout << "Number of sentences: " << numberOfSentences << endl;
    cout << "Number of words: " << numberOfWords << endl;
    cout << "Word frequencies:" << endl;

    for (const auto& pair : wordFrequency) {
        cout << pair.first << ": " << pair.second << endl;  // Display word and its frequency (count)
    }
}

int main() {
    string filepath;

    // Get the full file path from the user
    cout << "Enter the full file path: ";
    getline(cin, filepath); // Get the file path using getline to capture the entire path including spaces

    // Generate the summary for the file
    generateSummary(filepath);

    return 0;
}
