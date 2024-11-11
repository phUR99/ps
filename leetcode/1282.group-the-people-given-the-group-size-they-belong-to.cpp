/*
 * @lc app=leetcode id=1282 lang=cpp
 *
 * [1282] Group the People Given the Group Size They Belong To
 */

// @lc code=start
/*
선언을 여러번 하는 것보다는 선언 후 초기화를 하는 방식이 시간 효율이 더 높음
*/
class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        vector<vector<int>> ret;
        vector<pair<int, int>> temp;
        vector<int> tmp;
        int n = groupSizes.size();
        for (int i = 0; i < n; i++)
        {
            temp.push_back({groupSizes[i], i});
        }
        sort(temp.begin(), temp.end());
        int idx = 0;
        while (idx < n)
        {
            tmp.clear();
            for (int i = 0; i < temp[idx].first; i++)
            {
                tmp.push_back(temp[idx + i].second);
            }
            idx += temp[idx].first;
            ret.push_back(tmp);
        }

        return ret;
    }
};
// @lc code=end
