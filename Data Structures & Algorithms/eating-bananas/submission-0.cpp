class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r) {
            int m = l + (r-l) / 2;

            // calculate total time needed to eat bananas
            long total = 0;
            for (int &pile: piles) 
                total += (pile + m - 1) / m;
            
            if (total > h) l = m + 1;
            else {
                res = m;
                r = m - 1;
            }
        }

        return res;
    }
};
