#include<bits/stdc++.h>
using namespace std;
int main(){
set<pair < int , string >> s1;
s1.insert({100 , "MANGO"});
s1.insert({200 , "apple"});
s1.insert({700 , "orange"});
s1.insert({300 , "kiwi"});
s1.insert({800 , "lichi"});
s1.insert({400 , "papaya"});

  for(auto p : s1){  // print way-1
        cout << p.first << ", " << p.second << endl;
    }

while (!s1.empty()){   // print way 2
    auto x = s1.begin();
    cout << (*x).first <<"," << (*x).second << endl;
    s1.erase(x);
}

// jab update krna ho to phle dlt krna hoga then we can update 
auto add = s1.find({100 , "MANGO"});
if(add != s1.end()){
    s1.erase(add);
}
s1.insert({150 , "mango"});
 for(auto p : s1){  // print way-1
        cout << p.first << ", " << p.second << endl;
    }
cout << endl;
return 0;
}