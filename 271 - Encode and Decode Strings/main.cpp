#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
 * @param strs: a list of strings
 * @return: encodes a list of strings to a single string.
 */
string encode(vector<string> &strs) {
    string enc = "";
    string word = "";
    for (string s : strs) {
        for (char c : s) {
            if (c == '|')
                word += '|';
            word += c;
        }
        enc += word + "|";
        word = "";
    }
    return enc;
}

/*
 * @param str: A string
 * @return: dcodes a single string to a list of strings
 */
vector<string> decode(string &str) {
    vector<string> dec;
    string word = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '|' && str[i+1] == '|') {
            word += '|';
            i++;
            continue;
        }
        if (str[i] == '|') {
            dec.push_back(word);
            word = "";
            continue;
        } else
            word += str[i];

    }
    return dec;
}

int main() {
    vector<string> input{"lint","code","love","you"};
    string encoded = encode(input);
    vector<string> decoded = decode(encoded);
    cout << boolalpha << (input == decoded);
    return 0;
}