#include<iostream>
#include<vector>
#include<list>
#include<iterator> //to use advance() function used in list 
#include<map>
using namespace std;

//vector iterators
void vecIterators(){
    vector<int> vec={1,2,3,4,5};

    //forward loop
    for(vector<int>::iterator it=vec.begin();it!=vec.end();it++){
        cout<<*(it)<<" ";
    }cout<<endl;
 
    //backward loop
    for(auto it=vec.rbegin();it!=vec.rend();it++){ //auto keyword replaces the vector<int>::iterator syntax
        cout<<*(it)<<" ";
    }cout<<endl;
}

void listContainer(){
    list<int> l={1,2,3,4,5};
    for(int val: l){
        cout<<val<<" ";
    }cout<<endl;

    //cout<<l[2]<<endl; //gives an errror because random access is Not Possible in list
    //cout<<*(l.begin()+1)<<endl;  //Valid for dynamic array (vec or deque) but INVALID for list
    auto it=l.begin();
    advance(it,2);
    cout<<*(it)<<endl;
}    

void mapContainer(){
    //insert,emplace,count,erase,find,size,empty functions are present 
    map<string,int> m; //key-value pair where key is unique
    m["tv"]=100;
    m["laptop"]=100;
    m["headphones"]=50;
    m["tv"]=30;
    m.insert({"tablet",120});
    m.emplace("watch",50);
    for(auto p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<"count = "<<m.count("laptop")<<endl;
    m.erase("tv");
    cout<<endl;
    for(auto p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    
    //multimap
    multimap<string,int> m1;
    m1.emplace("tv",200);
    m1.emplace("tv",200);
    m1.emplace("tv",120);
    m1.emplace("tv",150);
    cout<<endl;
    for(auto p : m1){
        cout<<p.first<<" "<<p.second<<endl;
    }
    m1.erase(m1.find("tv"));
    cout<<endl;
    for(auto p : m1){
        cout<<p.first<<" "<<p.second<<endl;
    }
    m1.erase("tv");
    cout<<endl;
    for(auto p : m1){
        cout<<p.first<<" "<<p.second<<endl;
    }

}

int main(){

    //vecIterators();
    // listContainer();
    mapContainer();
    return 0;
}