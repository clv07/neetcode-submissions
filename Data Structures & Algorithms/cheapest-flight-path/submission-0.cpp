// data structure: 
// - min heap ordered by price, carry stop count in each state: the first time dst comes off the heap is the cheapest valid price.
// - an array bestStops[node] to track min stop count so far reached in that node, if this node already popped with fewer or equal stops, the current state is worse on both price and stops, so skip it.

// algorithm:
// 1. pop(price, node, stops) heap
// 2. if node == dst, return price
// 2. if stops > k or stops >= bestStops[node]: skip
// 3. bestStops[node] = stops
// 4. push neighbors with (price + w, nbr, stops + 1)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n); // adj[u] = {(v, price)}

        for (auto &f: flights) 
            adj[f[0]].push_back({f[1], f[2]});

        vector<int> bestStops(n, INT_MAX);
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> minHeap;
        minHeap.push({0, src, 0});

        while(!minHeap.empty()) {
            auto [price, node, stops] = minHeap.top(); 
            minHeap.pop();
            if (node == dst) return price;
            if (stops > k || stops >= bestStops[node]) continue;
            bestStops[node] = stops;
            for (auto& [nei, p]: adj[node])
                minHeap.push({price + p, nei, stops+1});
        }
        return -1;
        
    }
};
