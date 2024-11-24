#include<bits/stdc++.h>
using namespace std;

template<typename T >
class graph{
public :
map < T, list<pair < T, int >>> adj;
void addedges(T u , T v , int d , bool bidir = true){
    adj[u].push_back({v,d});
    if(bidir) adj[v].push_back({u,d});
}

void print (){
    for(auto p: adj){
    cout << p.first << " :";
    for(auto item : p.second){
        cout << "(" << item.first << " , " << item.second << ")" ;
    }
    cout << endl;
}
}

int dijkstras(T src , T des){
    set< pair < int , T >> s;
    unordered_map<T , T> parent ;
    unordered_map<T , int> distance ;
    for(auto p : adj){
        distance[p.first] = INT_MAX;
    }
    parent[src]= src;
    distance[src] =0;
    s.insert({0 , src});
    while(!s.empty()){
        auto x = *s.begin();
        s.erase(s.begin());
        int d = x.first;
        T t = x.second ;
        for(auto p: adj[t]){
            auto ch = p.first ;
            int edge_d = p.second;
            if(distance[ch] > d+ edge_d){
                auto f = s.find({distance[ch] , ch});
                if(f != s.end()){
                    s.erase(f);
                }
                s.insert({d+edge_d , ch});
                distance[ch] = d+ edge_d;
                parent[ch] =  t;
            }
        }
    }
    T des_cpy = des;
    while (des != src){
        cout << des << "  ";
        des = parent[des];
    }
    cout << des << endl;
    return distance[des_cpy];
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
    int ans = g.dijkstras('A' , 'D');
    cout << ans;
    return 0;

    
}