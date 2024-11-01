/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

/*
1. 벡터를 정렬한 후에 이분탐색으로 찾기
-> 벡터의 인덱스를 같이 줘야 해서 불편한 점이 있음(OlgN)
2. 벡터를 탐색할 때 해시맵에 추가하면서 탐색하기
-> 간단하고 강력함

*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ret;
        unordered_map<int, int> arr;
        for (int i = 0; i < nums.size(); i++)
        {
            int comp = target - nums[i];
            if (arr.find(comp) != arr.end())
            {
                ret.push_back(arr[comp]);
                ret.push_back(i);
                return ret;
            }
            arr[nums[i]] = i;
        }

        return ret;
    };
};
// @lc code=end
