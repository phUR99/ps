/*
 * @lc app=leetcode id=1478 lang=cpp
 *
 * [1478] Allocate Mailboxes
 */

// @lc code=start
/*
1. 완전탐색 알고리즘
1_1) 구간을 K개로 분리(정렬 필요)
1-2) 선택한 구간의 편차를 구한 후에 다음 구간을 완전탐색하면서 K개의 편차를 구함
-> 중복되는 부분 : 구간의 편차를 계속 구함
따라서 메모이제이션을 이용해서 이 부분을 최적화하기
cache[begin][parts] : begin에서 시작해서 parts 수 만큼의 k가 남았을 때 편차의 최솟값의 합
2. 주의점
평균으로 편차를 구했을 때 최소값이 아니라 중앙값으로 편차를 구해야 최솟값이 나온다.
평균으로 구할 경우 끝 값의 과대평가로 인해서 오히려 밀릴 수 있음


*/
class Solution
{
public:
    int n;
    vector<vector<int>> cache;
    const int MX = 987654321;
    int deviation(int left, int right, vector<int> &houses)
    {
        int ret = 0;
        int median = houses[(left + right + 1) / 2];
        for (int i = left; i <= right; i++)
        {
            ret += abs(median - houses[i]);
        }

        return ret;
    }

    int minSumError(int begin, int parts, vector<int> &houses)
    {
        if (begin == n)
            return 0;
        if (parts == 0)
            return MX;
        int &ret = cache[begin][parts];
        if (ret != -1)
            return ret;
        ret = MX;
        for (int panel = 1; panel + begin <= n; panel++)
        {
            ret = min(ret, deviation(begin, begin + panel - 1, houses) + minSumError(begin + panel, parts - 1, houses));
        }
        return ret;
    }

    int minDistance(vector<int> &houses, int k)
    {
        n = houses.size();
        sort(houses.begin(), houses.end());
        cache.resize(n, vector<int>(k + 1, -1));
        int ret = minSumError(0, k, houses);
        return ret;
    }
};
// @lc code=end
