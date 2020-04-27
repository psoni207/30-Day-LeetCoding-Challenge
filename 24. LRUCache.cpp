class LRUCache {
    private:
    list<int> cache;
    unordered_map<int,int> umap;
    int capacity;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(umap.find(key) != umap.end() ){
            cache.remove(key);
            cache.push_back(key);
            return umap[key];
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        
        if(umap.find(key) != umap.end() ){
            umap.erase(key);
            cache.remove(key);
        }
        
        if(cache.size() == capacity){
            int temp = cache.front();
            cache.pop_front();
            umap.erase(temp);
        }
        
        umap[key] = value;
        cache.push_back(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */