//https://www.codingninjas.com/codestudio/problem-details/frog-jump_3621012
//Recursion:-
int result(in index,vector<int>nums){
    if(i==0) return 0;
    int left = result(index-1,nums) + abs(nums[i]-nums[i-]);
    int right=INT_MAX;
    if(i>1) 
    right = result(index-2,nums)+ abs(nums[i]-nums[i-2]);
    return min(left,right);
 }
 //Dp:-
 int result(in index,vector<int>nums,vector<int>dp){
    if(i==0) return 0;
    if(dp[i] != -1) return dp[i];
    int left = result(index-1,nums) + abs(nums[i]-nums[i-]);
    int right=INT_MAX;
    if(i>1) 
    right = result(index-2,nums)+ abs(nums[i]-nums[i-2]);
    return dp[i] = min(left,right);
 }
 //Tabulation:-
 vector<int>dp(nums.size());
 dp[0] = 0;
 for(int i=1;i<n;i++){
     int ls=0,rs = INT_MAX;
     ls = dp[i-1]+abs(nums[i-1]-nums[i]);
     if(i>1)
     rs = dp[i-2]+abs(nums[i]-nums[i-2]);
      dp[i] = min(ls,rs);
 }
 return dp[nums.size()-1];
 //Two Pointer:-
 int prev2 = 0,prev =1;
 for(int i=2;i<n;i++){
     int ls = 0,rs = INT_MAX;
     ls = prev2 + abs(nums[i-2]-nums[i]);
     if(i>1)
     rs = prev+abs(nums[i-1]-nums[i])
     int curr =min(ls,rs);
     prev2 = prev;
     prev = curr;
 }
 return curr;

