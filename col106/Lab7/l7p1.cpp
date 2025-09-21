#include <iostream>
#include <vector>
#include <list>

using namespace std;

class HashTable {
    private:
    int bucketCount;
    vector<list<int>> table;

    size_t hashInt(int x) {
        return (size_t)x * 2654435761u;
    }

    public:
    HashTable(int size = 50009) {
        bucketCount = 50009;
        table.resize(bucketCount);
    }
    void insert(int key){
        size_t index =hashInt(key)%bucketCount;
        for(int k : table[index]) {
            if(k==key) return;
        }
        table[index].push_back(key);
    }
    bool find(int key) {
        size_t index = hashInt(key)%bucketCount;
        for(int k : table[index]) {
            if(k==key) return true;
        }
        return false;
    }
    void erase(int key) {
        size_t index = hashInt(key)%bucketCount;
        table[index].remove(key);
    }
};

int max(int a, int b) {
    return (a>=b ? a : b);
}

int longestChain(vector<int>& v) {
    HashTable ht;
    int ans=0;
    for(int x : v) {
        ht.insert(x);
    }
    for(int x : v) {
        if(ht.find(x-1)) continue;
        int temp=1;
        int y = x;
        while(true) {
            y = y+1;
            if(ht.find(y)) temp +=1;
            else break; 
        }
        ans = max(ans,temp);
    }
    return ans;
}

int main() {
    vector<int> v = {100,4,200,1,3,2};
    cout << longestChain(v) << endl;
    return 0;
}
