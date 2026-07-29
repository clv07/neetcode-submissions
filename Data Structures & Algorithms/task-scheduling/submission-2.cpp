class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char t: tasks)
            freq[t - 'A']++;
        
        int maxCount = *max_element(freq, freq + 26);
        int numMax = count(freq, freq + 26, maxCount);

        int skeleton = (maxCount - 1) * (n + 1) + numMax;
        return max(skeleton, (int)tasks.size());
    }
};
