/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
/*
백트래킹 시도 o(4^n*m)

*/
class Solution
{
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int n, m;

    vector<vector<bool>> visited;

    int findUniquePaths(pair<int, int> pos, int remain, vector<vector<int>> &grid)
    {
        int x = pos.first;
        int y = pos.second;
        if (grid[x][y] == 2)
            return remain == 0;

        int ret = 0;
        visited[x][y] = true;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (grid[nx][ny] == -1 || visited[nx][ny])
                continue;
            ret += findUniquePaths({nx, ny}, remain - 1, grid);
        }
        visited[x][y] = false;
        return ret;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int ret = 0;
        n = grid.size();
        m = grid[0].size();
        visited.resize(n, vector<bool>(m, false));
        pair<int, int> st;
        int r = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    st.first = i;
                    st.second = j;
                }
                r += (grid[i][j] == 0);
            }
        }
        ret = findUniquePaths(st, r, grid);
        return ret;
    }
};
// @lc code=end
