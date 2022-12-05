/* Number of Islands
** https://leetcode.com/problems/number-of-islands/description/
*/

class Solution {
public:
    int DFS(int y, int x, vector<vector<char>>& grid) {
        if (x < 0 || x >= X || y < 0 || y >= Y || grid[y][x] != '1')
            return 0;
        grid[y][x] = '2';
        DFS(y, x + 1, grid);
        DFS(y, x - 1, grid);
        DFS(y + 1, x, grid);
        DFS(y - 1, x, grid);
        return 1;
    }

    int numIslands(vector<vector<char>>& grid) {
        int sum = 0;
        Y = grid.size();
        X = grid[0].size();

        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                sum += DFS(y, x, grid);
            }
        }
        return sum;
    }

    int X, Y;
};
