class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; // widen before negating to prevent overflow
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
         double res = 1.0;
         while (N > 0) {
            if (N & 1) res *= x;    // this bit is set
            x *= x;                 // next power of two
            N >>= 1;
         }
         return res;
    }
};
