#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        bool valid_anagram(string s, string t) {
            unordered_map<char, int> charCountS;
            unordered_map<char, int> charCountT;
            for(int i = 0; i < s.length(); i++) {
                charCountS[s[i]]++;
                charCountT[t[i]]++;
            }
            return charCountS == charCountT;
        }
};

int main() {
    string s = "rat";
    string t = "car";

    Solution solution;
    bool result = solution.valid_anagram(s, t);
    cout << (result ? "Valid Anagram" : "Invalid") << endl;
    return 0;
}