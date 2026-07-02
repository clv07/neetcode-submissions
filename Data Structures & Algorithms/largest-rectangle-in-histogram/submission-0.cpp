class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack <pair<int, int>> stk; // pair: (index, height)

        for (int i = 0; i<heights.size(); i++) {
            int start = i;
            while (!stk.empty() && stk.top().second > heights[i]) {
                pair<int, int> top = stk.top();
                int index = top.first;
                int height = top.second;
                maxArea = max(maxArea, height * (i - index));
                start = index;
                stk.pop();
            }
            stk.push({start, heights[i]});
        }

        while (!stk.empty()) {
            int index = stk.top().first;
            int height = stk.top().second;
            maxArea = max(maxArea, height * (static_cast<int>(heights.size()) - index));
            stk.pop();
        }
        return maxArea;
    }
};
