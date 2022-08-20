//https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces
class Solution {
  public:
  void dfs(vector<int>&visited,vector<int>edges[],int i){
      visited[i] = 1;
      for(int u : edges[i]){
      if(!visited[u]){
          dfs(visited,edges,u);
      }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> edges[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]!=0 && i!=j){
                edges[i].push_back(j);
                edges[j].push_back(i);
                }
            }
        }
        vector<int>visited(V,0);
        int c=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                ++c;
                dfs(visited,edges,i);
            }
        }
        return c;
    }
};