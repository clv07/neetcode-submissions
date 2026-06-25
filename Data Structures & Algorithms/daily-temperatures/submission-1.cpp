class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // use DP to work backward and reuse previously computed values
        // if j > i, if day j is not warmer than day i, jump ahead
        // by using the result already stored for day j.

        int n = temperatures.size();
        vector<int> res(n, 0);
        for (int i = n-2; i >=0; i--) {
            int j = i + 1;
            while (j < n && temperatures[j] <= temperatures[i]) {
                if (res[j] == 0) {
                    j = n;
                    break;
                }
                j += res[j];
            }

            if (j < n) {
                res[i] = j - i;
            }
        }

        return res;
    }
};
