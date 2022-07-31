//https://leetcode.com/problems/find-the-duplicate-number/
//Amazon
#include <bits/stdc++.h>
using namespace std;
void swap(int arr[],int id1,int id2){
    int temp = arr[id1];
    arr[id1] = arr[id2];
    arr[id2]=temp;
}
void cyclic_sort(int arr[],int n){
    int i=0;
    while(i<n){
        int correct_index = arr[i]-1;
        if( arr[i] != arr[correct_index] && arr[correct_index] != correct_index + 1){
            swap(arr,i,correct_index);
        }
        else
        i++;
    }
    
}
int duplicate_number(int arr[],int n ){
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1)
              return arr[i];
        }
        return 0;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cyclic_sort(arr,n);
   cout<<duplicate_number(arr,n);
}
