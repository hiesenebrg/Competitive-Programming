#include <iostream>
using namespace std;
#include <string>
#include <vector>

// returning the substring
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

// this below is the best option to get all the subsequnces
int subs(string input, string output[]) {
	if (input.empty()) {
		output[0] = "";
		return 1;
	}

	string smallString = input.substr(1);
	int smallOutputSize = subs(smallString, output);
	for (int i = 0; i < smallOutputSize; i++) {
		output[i + smallOutputSize] = input[0] + output[i];
	}
	return 2 * smallOutputSize;
}

int main() {
	string input;
	cin >> input;
	string* output = new string[1000];
	int count = subs(input, output);
	for (int i = 0; i < count; i++) {
		cout << output[i] << endl;
	}
}
//  printing the subsequnces
// void printSubsequences(string str, string curr = "", int index = 0) {
//     if (index == str.length()) {
//         cout << curr << " ";
//         return;
//     }

//     // Exclude the current character
//     printSubsequences(str, curr, index + 1);

//     // Include the current character
//     printSubsequences(str, curr + str[index], index + 1);
// }
// int main() {
//     string str;
//     cout << "Enter a string: ";
//     cin >> str;

//     cout << "All subsequences of " << str << " are: ";
//     printSubsequences(str);

//     return 0;
// }