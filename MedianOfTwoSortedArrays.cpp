#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2); 
        
        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m, midCount = (m + n + 1) / 2;
        
        while (left <= right) {
            int mid1 = left + (right - left) / 2;
            int mid2 = midCount - mid1;

            int leftMax1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int rightMin1 = (mid1 == m) ? INT_MAX : nums1[mid1];
            int leftMax2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int rightMin2 = (mid2 == n) ? INT_MAX : nums2[mid2];

            if (leftMax1 <= rightMin2 && leftMax2 <= rightMin1) {
                if ((m + n) % 2 == 0)
                    return (max(leftMax1, leftMax2) + min(rightMin1, rightMin2)) / 2.0;
                else
                    return max(leftMax1, leftMax2);
            }
            else if (leftMax1 > rightMin2) {
                right = mid1 - 1;
            } else {
                left = mid1 + 1; 
            }
        }
        
        return 0.0; 
    }
};
