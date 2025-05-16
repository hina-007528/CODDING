#include<iostream>
using namespace std;

int findLargest(int arr[],int n){
    int largest=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
largest=arr[i];
        }
    }
    return largest;
}
int main(){
    int n;
    cout<<"Enter no of  elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int largest=findLargest(arr,n);
    cout<<"Largest element is"<<largest<<endl;
    return 0;
}