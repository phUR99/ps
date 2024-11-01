/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> cache;
    int n, m;
    bool outOfBound(int x, int y)
    {
        return x < 0 || x >= n || y < 0 || y >= m;
    }

    int findLen(int i, int j, vector<vector<int>> &matrix)
    {
        int &ret = cache[i][j];
        if (ret != -1)
            return ret;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        ret = 1;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            if (outOfBound(nx, ny))
                continue;
            if (matrix[nx][ny] <= matrix[i][j])
                continue;
            ret = max(ret, findLen(nx, ny, matrix) + 1);
        }
        return ret;
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        n = matrix.size();
        m = matrix.front().size();
        int ret = 0;
        cache.resize(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ret = max(ret, findLen(i, j, matrix));
            }
        }
        return ret;
    }
};
// @lc code=end
