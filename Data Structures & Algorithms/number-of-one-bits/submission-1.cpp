class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n) {      // stops as soon as no set bits remain
            n &= (n-1); // clear lowest set bit
            count++;
        }
        return count;

    }
};
