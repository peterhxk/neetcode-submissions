class LFUCache {
    // key to list iterator
    // int capacity 
    // get increments the frequency, pops and insert at beginning of the +1
    // int freq for keeping track of lowest freq
    // put--> originally 1, increments if repeated key
    int capacity;
    int count;
    int freq;
    unordered_map<int, pair<int,list<pair<int,int>>::iterator>> m;
    unordered_map<int, list<pair<int,int>>> cache;
public:
    LFUCache(int capacity): capacity(capacity) {
        freq = 0;
        count = 0;
    }
    
    int get(int key) {
        if (!m.contains(key)){
            return -1;
        }
        auto info = m[key];
        int f = get<0>(info);
        auto it = get<1>(info);
        auto& l = cache[f];
        auto node = *it;
        int value = get<1>(node);
        l.erase(it);
        if (f == freq && l.empty()){
            freq++;
        }
        f++;
        auto& l2 = cache[f];
        l2.insert(l2.begin(), {key,value});
        m[key] = {f,l2.begin()};
        return value;
    }
    
    void put(int key, int value) {
        if (!m.contains(key)){
            if (count == capacity){
                auto& to_remove_l = cache[freq];
                auto node = to_remove_l.back();
                to_remove_l.pop_back();
                m.erase(get<0>(node));
                count--;
            }
            count++;
            freq=1;
            auto& l = cache[1];
            l.insert(l.begin(),{key,value});
            m[key] = {1,l.begin()};
        } else {
            auto info = m[key];
            int f = get<0>(info);
            auto it = get<1>(info);
            auto& l = cache[f];
            l.erase(it);
            if (f==freq && l.empty()){
                freq++;
            }
            f++;
            auto& l2 = cache[f];
            l2.insert(l2.begin(), {key,value});
            m[key] = {f, l2.begin()};
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as su
 ch:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */