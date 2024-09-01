#include <iostream>
#include <vector>
using namespace std;

// Function to generate all subsequences of a given string
void generateSubsequences(string str, string output, int index, vector<string> &subsequences) {
    // Base case: if the current index reaches the end of the string
    if (index == str.length()) {
        subsequences.push_back(output);  // Store the current subsequence
        return;
    }

    // Exclude the current character and move to the next character
    generateSubsequences(str, output, index + 1, subsequences);

    // Include the current character in the subsequence and move to the next character
    output += str[index];
    generateSubsequences(str, output, index + 1, subsequences);
}

// Function to return all subsequences of a given string
vector<string> getAllSubsequences(string str) {
    vector<string> subsequences;
    generateSubsequences(str, "", 0, subsequences);
    return subsequences;
}

int main() {
    string str = "abc";  // Example string
    vector<string> subsequences = getAllSubsequences(str);

    // Print all subsequences
    for (const string &subseq : subsequences) {
        cout << "'" << subseq << "'" << endl;
    }

    return 0;
}
