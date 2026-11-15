#include<iostream>
#include<vector>
#include <random>
using namespace std;

int rotatedSortedArr(vector<int>& arr, int tar){
    int st=0;
    int end=arr.size() - 1;

    while(st<=end){
        int mid=st + (end-st)/2;
        if(tar==arr[mid]){
            return mid;
        }
        if(arr[st] <= arr[mid]){
            if(tar >= arr[st] && tar < arr[mid]){ // Left search
                end=mid-1;
            }else{  //Right search
                st=mid+1;
            }
        }else{
            if(tar <= arr[end] && tar > arr[mid]){ // Left search
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums={3,4,5,6,7,0,1,2};
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0,7);

    int tar=distrib(gen);
    int ans= rotatedSortedArr(nums,13);
    cout<<"Target : "<<tar<<endl;
    //cout<<"Array : "<<nums<<endl;
    cout<<"Ans : "<<ans<<endl;
    return 0;
}