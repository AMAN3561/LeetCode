
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<tuple<int, int, int>> q;
        vector<vector<bitset<1024>>> visited(m, vector<bitset<1024>>(n));

        int start = grid[0][0];
        q.push({0, 0, start});
        visited[0][0][start] = true;

        int dx[] = {0, 1};
        int dy[] = {1, 0};
        int ans = INT_MAX;
        while (!q.empty()) {
            auto [row, col, XOR] = q.front();
            q.pop();
            if (row == m - 1 && col == n - 1){
                ans = min(ans, XOR);
                continue;
            }
            for (int i = 0; i < 2; i++){
                int newR = row + dx[i];
                int newC = col + dy[i];

                if (newR < m && newC < n){
                    int newXOR = XOR ^ grid[newR][newC];

                    if (!visited[newR][newC][newXOR]){
                        visited[newR][newC][newXOR] = true;
                        q.push({newR, newC, newXOR});
                    }
                }
            }
        }
        return ans;
    }
};
