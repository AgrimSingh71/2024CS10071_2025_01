#include <iostream>
#include <vector>
#include <list>

using namespace std;

class HashTable {
    private:
    int bucketCount;
    vector<list<pair<int,int>>> table;

    size_t hashInt(int x) {
        return (size_t)x * 2654435761u;
    }

    public:
    HashTable(int size = 50009) {
        bucketCount = 50009;
        table.resize(bucketCount);
    }
    void insert(int key, int value){
        size_t index =hashInt(key)%bucketCount;
        for( auto& k : table[index]) {
            if(k.first == key) {
                k.second = value;
                return;
            }
        }
        table[index].push_back({key,value});
    }
    bool find(int key, int& outvalue) {
        size_t index = hashInt(key)%bucketCount;
        for(auto& k : table[index]) {
            if(k.first==key) {
                outvalue = k.second;
                return true;
            }
        }
        return false;
    }
    void erase(int key) {
        size_t index = hashInt(key)%bucketCount;
        for(auto it = table[index].begin(); it!=table[index].end(); ++it) {
            if(it->first == key) {
                table[index].erase(it);
                return;
            }
        }
    }
};

int max(int a, int b) {
    return (a>=b ? a : b);
}

int min(int a, int b) {
    return (a<=b ? a : b);
}

int longestShelf(vector<int>& v) {
    
    int n = v.size();
    HashTable ht;
    ht.insert(v[0],0);
    int ans = 1;
    int temp = 1;
    int idx;
    for(int i=1;i<n;i++) {
        
        if(ht.find(v[i],idx)) {
            ans = max(ans,temp);
            temp = i - idx;
            ht.insert(v[i],i);
        }
        else {
            ht.insert(v[i],i);
            temp +=1;
        }
    }
    ans = max(ans,temp);
    return ans;
}

int main() {
    vector<int> v = {10,20,30,40,20,50};
    cout << longestShelf(v) << endl;
    return 0;
}
