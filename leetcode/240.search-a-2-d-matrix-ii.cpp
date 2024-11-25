/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
/*
우상단에서 시작하는 이유
좌상단의 경우에는 이동할 방향의 결정이 힘듦(가능한 방향 모두 증가밖에 없기 때문에)
우상단의 경우에는 명확하게 정해져있음
왼쪽으로 갈 경우 반드시 작아지며
아래로 갈 경우에는 반드시 커지는 특성이 있음
*/
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = 0;
        int col = matrix[0].size() - 1;
        int m = matrix.size();
        while (row < m && col >= 0)
        {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                col--;
            else
                row++;
        }
        return false;
    }
};
// @lc code=end
