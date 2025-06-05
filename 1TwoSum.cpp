#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> two_sum(vector<int> &nums, int target)
    {
        unordered_map<int, int> complement_map;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (complement_map.count(complement))
            {
                return {complement_map[complement], i};
            }
            else
            {
                complement_map[nums[i]] = i;
            }
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution solution;
    vector<int> result = solution.two_sum(nums, target);
    for (int i = 0; i < 2; i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}