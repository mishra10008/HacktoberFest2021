
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int res = 0, diff = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end)
            {
                if (nums[i] + nums[start] + nums[end] == target)
                    return target;
                else if (abs(nums[i] + nums[start] + nums[end] - target) < diff)
                {
                    diff = abs(nums[i] + nums[start] + nums[end] - target);
                    res = nums[i] + nums[start] + nums[end];
                }
                if (nums[i] + nums[start] + nums[end] < target)
                    start++;
                else
                    end--;
            }
        }
        return res;
    }
};
int main()
{
    vector<int> n = {2, 7, 99, 9, 8};
    int target = 6;
    Solution s;
    cout << s.threeSumClosest(n, target);
}