class KthLargest {
public:
    priority_queue<int> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        for (int n: nums) {
            pq.push(-n);
            if (pq.size() > k) 
                pq.pop();
        }
        this->k = k;
    }
    
    int add(int val) {
        pq.push(-val);
        if (pq.size() > k)
            pq.pop();
        return -pq.top();
    }
};
