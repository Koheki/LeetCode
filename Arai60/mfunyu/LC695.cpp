/* Max Area of Island
** https://leetcode.com/problems/max-area-of-island/description/
*/

class Solution {
public:
    int X, Y;
    int DFS(int y, int x, vector<vector<int>>& grid) {
        if (x < 0 || x >= X || y < 0 || y >= Y || !grid[y][x])
            return 0;
        int ret = 1;
        grid[y][x] = 0;
        ret += DFS(y + 1, x, grid);
        ret += DFS(y - 1, x, grid);
        ret += DFS(y, x + 1, grid);
        ret += DFS(y, x - 1, grid);
        return ret;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        Y = grid.size();
        X = grid[0].size();

        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                int size = DFS(y, x, grid);
                if (size > max) max = size;
            }
        }
        return max;
    }
};
