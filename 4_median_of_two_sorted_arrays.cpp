//idea: https://www.youtube.com/watch?v=LPFhl65R7ww&feature=emb_rel_pause

//Binary Search because time complexity should be O(log (m+n)).

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        if (l1 > l2)
        {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
            swap(l1, l2);
        }
        int start = 0;
        int end = l1;
        int mid = (l1 + l2 + 1) / 2;
        int partition1;
        int partition2;

        while (start <= end)
        {
            int leftmax1=INT_MIN;
            int leftmax2=INT_MIN;
            int rightmin1=INT_MAX;
            int rightmin2=INT_MAX;
            partition1 = (start + end + 1) / 2;
            partition2 = mid - partition1;
            if (partition1 > 0) leftmax1 = nums1[partition1 - 1];
            if (partition1 < l1) rightmin1 = nums1[partition1];
            if (partition2 > 0) leftmax2 = nums2[partition2 - 1];
            if (partition2 < l2) rightmin2 = nums2[partition2];
            if (leftmax1 <= rightmin2 && leftmax2 <= rightmin1)
            {
                if ((l1 + l2) % 2 == 1)
                    return max(leftmax1, leftmax2);
                else 
                    return (max(leftmax1, leftmax2) + min(rightmin1, rightmin2)) / 2.0;
            }
            else if (leftmax1 > rightmin2)
                end = partition1 - 1;
            else start = partition1 + 1;
        }
        return -1.0;
    }
};