//https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm
//bfs:-
class Solution {
public:
    void bfs(vector<vector<int>>&visited,vector<vector<int>>&image,int newColor,int i,int j,int inColor,
    int delRow[],int delCol[]){
          queue<pair<int,int>>q;
          int n = image.size(),m = image[0].size();
          q.push({i,j});
          while(!q.empty()){
             int row = q.front.first,col = q.front.second;
             image[row][col] = newColor;
             q.pop();
             for(int i=0;i<4;i++){
                 int drow = row + delRow[i],dcol = col + delCol[i];
                 if(drow>=0 && drow<n && dcol>=0 && dcol<m && image[drow][dcol] == inColor)
                 q.push(image[drow][dcol]);
             }
          }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(),m = image[0].size();
        vector<vector<int>>visited(n,vector<int>(m,-1));
        int inColor = image[sr][sc];
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        bfs(visited,edge,newColor,sr,sc,inColor,delRow,delCol);
    }
};

//dfs:-
class Solution {
    private:
      void bfs(vector<vector<int>>&visited,vector<vector<int>>&image,int newColor,int i,int j,int inColor,
    int delRow[],int delCol[]){
          image[i][j] = newColor;
          int n = image.size(),m = image[0].size();
         
             for(int k=0;k<4;k++){
                 int drow =i + delRow[k],dcol = j + delCol[k];
                 if(drow>=0 && drow<n && dcol>=0 && dcol<m && image[drow][dcol] == inColor)
                 bfs(visited,image,newColor,drow,dcol,inColor,delRow,delCol);
             }
          
    }
public:
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(),m = image[0].size();
        vector<vector<int>>visited(n,vector<int>(m,-1));
        int inColor = image[sr][sc];
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        bfs(visited,image,newColor,sr,sc,inColor,delRow,delCol);
        return image;
    }
};