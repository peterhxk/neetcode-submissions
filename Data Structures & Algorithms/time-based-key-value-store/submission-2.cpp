class TimeMap {
public:
    unordered_map<string,map<int,string>> storage;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        storage[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        auto& m = storage[key];
        auto it = m.upper_bound(timestamp);
        if (it == m.begin()){
            return "";
        }
        auto previous = prev(it);
        return previous->second;
    }
};
