class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // use a stack to keep track index of monotonically decreasing values
        // when encounter larger values, result of top index = curr index - top index, 
        // and pop from stack till having larger top index.

        if (temperatures.empty()) return {};

        int n = temperatures.size();
        stack<int> index;
        vector<int> res(n, 0); //initialize to zero

        for (int i=0; i<n; i++) {
            while (!index.empty() && temperatures[index.top()] < temperatures[i]) {
                res[index.top()] = i - index.top();
                index.pop();
            } 

            index.push(i);

        }

        return res;
    }
};
