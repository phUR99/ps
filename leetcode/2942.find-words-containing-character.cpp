/*
 * @lc app=leetcode id=2942 lang=cpp
 *
 * [2942] Find Words Containing Character
 */

// @lc code=start
/*
find 메서드는 찾은 문자의 인덱스를 반환
-> 0 인덱스를 반환시 false로 판정해서 집어넣지 않는 문제
-> 이를 해결하기 위해서 false 대신 string::npos를 확인하기
*/
class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> ret;
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i].find(x) != string::npos)
                ret.push_back(i);
        }
        return ret;
    }
};
// @lc code=end
