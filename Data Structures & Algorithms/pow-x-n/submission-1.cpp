class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1/x;
            N = -N;
        }
        
        return helper(x, N);
    }

    double helper(double x, long long n) {
        if (n == 0) return 1.0;
        double half = helper(x, n / 2);
        return (n % 2)? half * half * x : half * half;
    }
};
