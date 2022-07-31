//https://leetcode.com/problems/find-the-duplicate-number/
//Amazon
#include <bits/stdc++.h>
using namespace std;
void swap(int arr[],int id1,int id2){
    int temp = arr[id1];
    arr[id1] = arr[id2];
    arr[id2]=temp;
}
void duplicate_number(int arr[],int n){
    int i=0;
    vector<int>v;
    while(i<n){
        int correct_index = arr[i]-1;
        if( arr[i] != arr[correct_index]){
            swap(arr,i,correct_index);
        }
        else
        i++;
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans;
     duplicate_number(arr,n);
    for(int i=0;i<n;i++){
        if(i+1 != arr[i])
        ans.push_back(arr[i]);
    }
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
}
