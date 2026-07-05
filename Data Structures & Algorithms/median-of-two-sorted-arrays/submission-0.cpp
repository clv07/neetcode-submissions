class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1); // search smaller

        int m = nums1.size(), n = nums2.size();
        int total = m + n, half = (total + 1)/2;
        int l = 0, r = m; // search in the smaller array

        while (l <= r) {
            int i = l + (r-l)/2;
            int j = half - i;

            int left1 = (i == 0)? INT_MIN : nums1[i-1];
            int right1 = (i == m)? INT_MAX : nums1[i];
            int left2 = (j == 0)? INT_MIN : nums2[j-1];
            int right2 = (j == n)? INT_MAX : nums2[j];

            if (left1 <= right2 && left2 <= right1) { // correct partition
                if (total % 2) return max(left1, left2); // odd length
                return (max(left1, left2) + min(right1, right2)) / 2.0; // even length
            }
            else if (left1 > right2) r = i - 1;
            else l = i + 1;
        }

        return 0.0;
    }
};
