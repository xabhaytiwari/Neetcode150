#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        bool contains_duplicate(vector<int>& nums) {
            return unordered_set(nums.begin(), nums.end()).size() < nums.size();
        }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 4};

    Solution solution;
    bool result = solution.contains_duplicate(nums);
    cout << (result ? "Contains duplicate" : "No duplicates") << endl;
    return 0;
}