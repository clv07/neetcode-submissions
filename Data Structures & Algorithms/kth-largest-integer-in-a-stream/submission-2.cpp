class KthLargest {
public:
    priority_queue<int> pq;
    int k1;
    KthLargest(int k, vector<int>& nums) {
        for (int n: nums) {
            pq.push(-n);
            if (pq.size() > k) 
                pq.pop();
        }
        k1 = k;
    }
    
    int add(int val) {
        pq.push(-val);
        while (pq.size() > k1)
            pq.pop();
        return -pq.top();
    }
};
