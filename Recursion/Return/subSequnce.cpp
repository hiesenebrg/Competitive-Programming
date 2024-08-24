
#include <iostream>
using namespace std;
#include <string>
#include <vector>
// since this is tree view , remember base case hits many times
vector<string> getSubsequences(string str, string curr = "", int index = 0) {
    vector<string> result;
    if (index == str.length()) {
        result.push_back(curr);
        return result;
    }

    // Exclude the current character
    vector<string> exclude = getSubsequences(str, curr, index + 1);
    result.insert(result.end(), exclude.begin(), exclude.end());

    // Include the current character
    vector<string> include = getSubsequences(str, curr + str[index], index + 1);
    result.insert(result.end(), include.begin(), include.end());

    return result;
}