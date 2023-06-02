class MyHashSet {
    vector<vector<int>> bucket;
    int buckets;
public:
    MyHashSet() {
        buckets = 15000;
        bucket = vector<vector<int>>(buckets,vector<int>{});
    }
    
    void add(int key) {
        int i = key % buckets;
        bool flag = find(bucket[i].begin(),bucket[i].end(),key) == bucket[i].end();
        if(flag)
        {
            bucket[i].push_back(key);
        }
    }
    
    void remove(int key) {
        int i = key % buckets;
        auto it = find(bucket[i].begin(),bucket[i].end(),key);

        if(it != bucket[i].end())
        {
            bucket[i].erase(it);
        }
    }
    
    bool contains(int key) {
        int i = key % buckets;
        bool flag = find(bucket[i].begin(),bucket[i].end(),key) == bucket[i].end();

        if(flag)
        {
            return false;
        }

        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */