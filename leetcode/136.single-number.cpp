/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
/*
xor 해싱
각 값이 2번씩 전달된다는 것을 이용하기
ret = a ^ a ^ b ^ b ^c ^c.... ^z;
ret = 0 ^ 0 ^ 0 ^... z;
ret =z;
x*/
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};
// @lc code=end
