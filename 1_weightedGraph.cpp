#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
public:
unordered_map<T , list<pair <T , int >>> adj;
void addedges(T u , T v , int d,  bool bidir = true){
    adj[u].push_back({v, d});
    if(bidir) adj[v].push_back({u, d});
}

void print(){
    for(auto p: adj){
        cout << p.first << " : ";
    
    for(auto item : p.second){
        cout << "(" << item.first << "," << item.second << ")"; 
    }
    cout << endl;
}
}

};
int main(){
    graph<char > g;
    g.addedges('A' , 'B' , 1);
    g.addedges('C' , 'B' , 2);
    g.addedges('C' , 'A' , 5);
    g.addedges('D' , 'A' , 8);
    g.addedges('D' , 'C' , 3);
    g.print();
    return 0;
}