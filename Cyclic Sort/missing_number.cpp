//https://leetcode.com/problems/missing-number/ 
//Amazon
#include <iostream>
using namespace std;
void swap(int arr[],int id1,int id2){
    int temp = arr[id1];
    arr[id1] = arr[id2];
    arr[id2]=temp;
}
void cyclic_sort(int arr[],int n){
    int i=0;
    while(i<n){
        int correct_index = arr[i];
        if(arr[i] < n && arr[i] != arr[correct_index]){
            swap(arr,i,correct_index);
        }
        else
        i++;
    }
    
}
int missing_number(int arr[],int n ){
        for(int i=0;i<n;i++){
            if(arr[i]!=i)
            return i;
        }
        //case 2:- when missing number is not in the aaray e.g:- 0 1 2 3 where n=4
        return n;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cyclic_sort(arr,n);
    cout<<missing_number(arr,n);
}
