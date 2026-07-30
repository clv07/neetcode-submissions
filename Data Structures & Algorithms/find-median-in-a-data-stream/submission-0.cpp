class MedianFinder {
public:
    priority_queue<int> lo; // maxHeap
    priority_queue<int, vector<int>, greater<int>> hi; // minHeap
    MedianFinder() {}
    
    void addNum(int num) {
        // push num to smaller half first for reordering
        // and push the small half's max to larger half
       lo.push(num);
       hi.push(lo.top());
       lo.pop();

       // if larger half too big, push its min back to smaller half
       if (hi.size() > lo.size()) {
            lo.push(hi.top());
            hi.pop();
       }
    }
    
    double findMedian() {
        // odd length return max of smaller half
        if (lo.size() > hi.size()) 
            return lo.top();
        // even length return average of max of smaller half and min of larger half
        else
            return ((long long)lo.top() + hi.top()) / 2.0;

    }
};
