//https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2) q.push({{i,j},0});
            }
        }
        vector<vector<int>>visited(n,vector<int>(m,0));
        int time = 0;
        int delRow[] = {-1,0,1,0};
        int delCol [] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first,col = q.front().first.second;
            visited[row][col] = 1;
            int t = q.front().second;
            time = max(time,t);
            q.pop();
            for(int k=0;k<4;k++){
                int nRow = row + delRow[k],nCol = col + delCol[k];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<n && grid[nRow][nCol] == 1 && visited[nRow][nCol] != 1)
                q.push({{nRow,nCol},t+1});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == 1)
                return -1;
            }
        }
        return time; 
    }
//Time:- O(M*N)
//Space:- O(M*N)