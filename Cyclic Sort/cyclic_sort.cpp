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
        int correct_index = arr[i]-1;
        if(arr[i] != arr[correct_index]){
            swap(arr,i,correct_index);
        }
        else
        i++;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cyclic_sort(arr,n);
}
