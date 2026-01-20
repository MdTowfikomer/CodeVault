#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<string>
using namespace std;

int main(){
    // hash map
    map<string,int> mp;


    // insertion

    //1
    mp["apple"] = 5;// inserts if missing, else update
    mp["apple"] = 10;
    //2- insert() => only insert don't overwrite
    mp.insert({"ball",3});
    //3- emplace() => only insert and but more efficient way to write
    auto insert2 = mp.emplace("cat", 5);
    //4
    pair<string, int> pair1 = make_pair("dog", 10);
    mp.insert(pair1);
    //5
    pair<string, int> pair2("elephat", 20);
    mp.insert(pair2);

    // search
    cout << mp["elephat"]  << endl;
    cout << mp.at("ball") << endl;
    
    // unknown value
    cout << mp["cow"] << endl; // creates a new key with cow and initializes it with '0'
    cout << mp.at("cow") << endl; // prints value of cow which is '0'

    //size
    cout << mp.size() << endl;

    // to check exsit
    cout << mp.count("elephate") << endl;
     
    cout << endl;

    // iterator
    map<string,int> :: iterator it = mp.begin();

    while(it != mp.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }

    // using loop
    // for(auto i: mp){
    //     cout << i.first << " " << i.second << endl;
    // }
    // cout << endl;

    return 0;
}