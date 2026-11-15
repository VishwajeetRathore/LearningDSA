#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int>& arr,int n, int m, int mid){
    int stu=1, pgs=0;
    for(int i=0; i<n;i++){
        if(arr[i]>mid){ //mid => maxAllowedPages
            return false;
        }
        if(pgs+arr[i] <= mid){ 
            pgs += arr[i];
        }else{
            stu++;
            pgs=arr[i];
        }
    }
    return (stu<=m); // valid => true and invalid => false
}
int allocateBook(vector<int>& book,int m){// m => no. of students  , n => no. of books  , ith book has Book[i] no. of pgs
    int n=book.size();
    if(m>n) return -1;
    int ans;

    int st=0;
    int end=0;
    for(int pgs: book){
        end+=pgs;   //end = sum of all pages 
    }

    while(st<=end){ //Binary Search
        int mid =  st + (end-st)/2;
        if(isValid(book,n,m,mid)){  // valid => left search
            ans =  mid;
            end = mid-1;
        }else{  //invalid => right search
            st = mid+1;
        }
    }
    return ans;

}

int main(){
    vector<int> arr={15,17,20};
    int minPossibleMaxPg = allocateBook(arr,2);
    cout<<"Min Poss. Max pg : "<<minPossibleMaxPg<<endl;
    return 0;
}