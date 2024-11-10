/*
 * @lc app=leetcode id=2433 lang=cpp
 *
 * [2433] Find The Original Array of Prefix Xor
 */

// @lc code=start
/*
정해 : XOR의 특성 이용하기
a ^ a = 0 임을 이용하여
pref[i+1] ^ pref[i] = (arr[0] ^ arr[1] ...) ^ (arr[0] ^ arr[1] ...) ^ arr[i+1];
arr[i+1] = pref[i+1] ^ pref[i];
공간복잡도 O(1) 풀이
역순으로 이 공식을 적용
*/
class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        int n = pref.size();
        for (int i = n - 1; i > 0; i--)
        {
            pref[i] = pref[i] ^ pref[i - 1];
        }
        return pref;
    }
};
// @lc code=end
