class MedianFinder {
public:
    
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> higher;
    
    bool even;
    
    MedianFinder() {
        even = true;    
    }
    
    void addNum(int num) {
        if(even) {
            higher.push(num);
            lower.push(higher.top());
            higher.pop();
        }
        else {
            lower.push(num);
            higher.push(lower.top());
            lower.pop();
        }
        even = !even;
    }
    
    double findMedian() {
        if(even) {
            return (lower.top() + higher.top()) / 2.0;
        }
        else {
            return lower.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */