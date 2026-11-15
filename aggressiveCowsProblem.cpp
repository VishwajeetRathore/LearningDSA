#include<iostream>
#include<vector>
#include<algorithm> //to use sort function
using namespace std;

bool isPossible(vector<int>& arr,int n, int m , int minAllowedDist){
    int cow = 1, lastStallPos = arr[0];
    for(int i=1 ; i<n ;i++){
        if(arr[i] -  lastStallPos >= minAllowedDist){
            cow++;
            lastStallPos = arr[i];
        }
        if(cow==m){
            return true;
        }
    }
    return false;
}

int minLargestDist(vector<int>& arr,int m){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int st=1;
    int end = arr[n-1]-arr[0];
    cout<<"end : "<<end<<endl;
    int ans=-1;
    while(st<=end){
        int mid= st + (end-st)/2;
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            st=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
    
}

int main(){
    vector<int> arr= {1,2,8,4,9};
    int c=3;
    cout<<"Ans : "<<minLargestDist(arr,c)<<endl;
    return 0;
}