class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int offset = 31; offset >= 0; offset--) {
            if (n & 1) ans |= (1u << offset);
            n >>= 1;
        }
        return ans;
    }
};
