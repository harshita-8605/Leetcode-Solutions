class Solution {
public:

    void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>> &visited){
        queue<pair<int, int>> q;
        q.push({i,j});
        visited[i][j] = true;
        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            // har direction main neighbour ko dekho
            for(int k = 0; k<directions.size(); k++){
                int nx = it.first + directions[k].first;
                int ny = it.second + directions[k].second;
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1' && !visited[nx][ny]){
                    q.push({nx , ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if(grid[i][j] == '1' and !visited[i][j]){
                    bfs(grid, i, j, visited);
                    count++;
                }
            }
        }

        return count;
    }
};