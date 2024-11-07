/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
/*
o(N) 풀이
2 = 10 (1);
3 = 2 + 1 (1) = cache[2] + 1;
4 = 2 + 0 (0) = cache[2] +1 ;
cache[i] = cache[i>>1] + (i&1);
& 연산자 우선순위 주의
*/
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ret(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            ret[i] = ret[i >> 1] + (i & 1);
        }
        return ret;
    }
};
// @lc code=end
