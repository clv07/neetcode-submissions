class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // check if number of elements can form group with size groupSize
        if (hand.size() % groupSize) return false;

        // count number of occurence of hand, value -> count
        map<int, int> mp;
        for (int& h: hand) 
            mp[h]++;
        
        // break condition: gap
        while(!mp.empty()) {
            int start = mp.begin()->first; //smallest remaining as starting point
            for (int i = 0; i < groupSize; i++) {
                auto it = mp.find(start + i);
                if (it == mp.end()) return false;   // gap
                if(--(it->second) == 0) mp.erase(it); // drop the key when count hit zero
                
            }
        }

        return true;
    }
};
