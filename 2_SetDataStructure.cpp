#include<bits/stdc++.h>
using namespace std;
int main(){
    set < int > s;
    s.insert(2);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(7);

// print way -1
    for(auto p : s){
        cout << p << " ";
    }
cout << endl;
    // print way - 2
    while(!s.empty()){
        auto x = s.begin();
        cout << *x << " ";
        s.erase(x);
    }
    
    return 0;
}