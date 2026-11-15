#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Brute Force
void sortArr(vector <int>& arr){
    sort(arr.begin(),arr.end());
}

int countFunc(vector<int>& arr,int num){
    int count=0;
    for(int val: arr){
        if(num==val){
            count++;
        }
    }
    return count;
}
//Optimised Approach using count variable
void sortArrUsingCount(vector<int> & arr){
    int countZeros=countFunc(arr,0);
    int countOnes=countFunc(arr,1);
    int countTwos=countFunc(arr,2);
        
    for(int i=0;i<arr.size();i++){
        if(i < countZeros) arr[i] = 0;
        else if(i < countZeros + countOnes ) arr[i]=1;
        else arr[i]=2;
    }   
}

//Most optimised approach
void sortArrDutchNationalFlagAlgo(vector<int>& arr){
    int low = 0, mid = 0, high = arr.size() - 1;
    while(mid<high){
        if(arr[mid]==0){
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        }else if(arr[mid]==1){
            mid++;
        }else{
            swap(arr[high],arr[mid]);
            high--;
        }
    }
}

void printArr(vector<int> & nums){
    cout<<"Array is : ";
    for (int val : nums){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> nums={2,0,2,1,1,0,1,2,0,0};
    printArr(nums);
    //sortArr(nums);
    //sortArrUsingCount(nums);
    sortArrDutchNationalFlagAlgo(nums);
    printArr(nums);
    return 0;
}