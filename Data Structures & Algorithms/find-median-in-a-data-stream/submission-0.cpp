class MedianFinder {
public:
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_pq.push(num);
        if (!max_pq.empty() && !min_pq.empty() && max_pq.top()>min_pq.top()){
            int cur = max_pq.top();
            max_pq.pop();
            min_pq.push(cur);
        }
        if (max_pq.size()>min_pq.size()+1){
            int cur = max_pq.top();
            max_pq.pop();
            min_pq.push(cur);
        }
        if (min_pq.size()>max_pq.size()+1){
            int cur = min_pq.top();
            min_pq.pop();
            max_pq.push(cur);
        }
    }
    
    double findMedian() {
        if (min_pq.size()>max_pq.size()){
            return min_pq.top();
        }
        else if (max_pq.size()>min_pq.size()){
            return max_pq.top();
        }
        else{
            return ((float) min_pq.top()+max_pq.top())/2;
        }
        
    }
};
