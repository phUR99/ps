/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
/*
o(n) 풀이
-> 배열이 증가하는 순서대로 정렬되어있음
절댓값은 1) 왼쪽이 항상 크거나 2) 오른쪽이 항상 크거나 3) 중간에 부호가 바뀌는 지점이 있거나
경우를 체크하기 위해서 투포인터 활용
양쪽 중 하나가 항상 제일 큰 숫자임을 보장하므로 배열의 뒤에서부터 채우기
*/
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ret(n);
        int l = 0;
        int r = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (abs(nums[l]) > abs(nums[r]))
            {
                ret[i] = nums[l] * nums[l];
                l++;
            }
            else
            {
                ret[i] = nums[r] * nums[r];
                r--;
            }
        }
        return ret;
    }
};
// @lc code=end
