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

bool isap(vector<int>& v) {
    int n = v.size();
    int idx;
    HashTable ht;
    for(int i=0;i<n;i++) {
        ht.insert(v[i],i);
    }
    for(int i=0;i<n;i++) {
        if(ht.find(2*v[i],idx) && idx!=i) return true;
    }
    return false;
}

int main() {
    vector<int> v = {10,2,5,20};
    cout << isap(v) << endl;
    return 0;
}
