class LRUCache {
public:
    list<int> dll;
    unordered_map<int,pair<list<int>::iterator,int>> cache; // key->(list_node,value)
    int cap;
    LRUCache(int capacity){
        cap=capacity;
    }
    void makeMostRecentlyUsed(int key){
        dll.erase(cache[key].first);
        dll.push_front(key);
        cache[key].first=dll.begin();
    }
    int get(int key) {
        if(!cache.count(key)) return -1;
        makeMostRecentlyUsed(key);
        return cache[key].second;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            cache[key].second=value;
            makeMostRecentlyUsed(key);
        }else{
            dll.push_front(key);
            cache[key]={dll.begin(),value};
            cap--;
        }
        if(cap<0){
            cache.erase(dll.back());
            dll.pop_back();
            cap++;
        }
    }
};
