//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<int>>&visited,vector<vector<char>>grid,int i,int j){
        visited[i][j]=1;
        int n = grid.size(),m=grid[0].size();
        for(int deli = -1;deli<=1;deli++){
            for(int delj = -1;delj<=1;delj++){
                int drow =i+ deli;
                int dcol = j+ delj;
                if(drow>=0 && drow <n && dcol>=0 && dcol <m &&
                visited[drow][dcol] == -1 && grid[drow][dcol] ==1){
                    dfs(visited,grid,drow,dcol);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(),col = grid[0].size();
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),-1));
        int count =0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1 && visited[i][j] == -1){
                    dfs(visited,grid,i,j);
                    count++;
                }
            }
        }
    }
};
//bfs:- 
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(vector<vector<int>>&visited,vector<vector<char>>grid,int i,int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        int n = grid.size(),m = grid[0].size();
        while(!q.empty()){
            int row = q.front().first,col = q.front().second;
            visited[row][col] = 1;
            q.pop();
            for(int delRow = -1;delRow<=1;delRow++){
                for(int delCol = -1;delCol<=1;delCol++){
                    int nRow = row + delRow,nCol = col + delCol;
                    if(nRow>=0 && nRow<n && nCol>=0 && nCol < n && visited[nRow][nCol] == -1)
                    q.push({nRow,nCol});
                }
            }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(),col = grid[0].size();
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),-1));
        int count =0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1 && visited[i][j] == -1){
                    bfs(visited,grid,i,j);
                    count++;
                }
            }
        }
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
