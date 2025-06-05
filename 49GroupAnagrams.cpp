#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class NonOptimalSolution {
    public:
        vector<vector<string>> group_anagrams(vector<string>& strs) {
            vector<string> sorted_strs;
            for(auto& str : strs) {
                string sorted_str = str;
                sort(sorted_str.begin(), sorted_str.end());
                sorted_strs.push_back(sorted_str);
            }
            vector<vector<string>> result;
            for(int i = 0; i < strs.size(); i++) {
                vector<string> group;
                for(int j = 0; j < strs.size(); j++) {
                    if(sorted_strs[i] == sorted_strs[j]) {
                        group.push_back(strs[j]);
                    }
                }
                if(!group.empty()) {
                    result.push_back(group);
                }
            }
            return result;
        }
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    NonOptimalSolution solution;
    solution.group_anagrams(strs);
    cout << "Grouped anagrams:" << endl;
    for(const auto& group : solution.group_anagrams(strs)) {
        for(const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}