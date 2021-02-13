//use set

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if (nums1.size() <= nums2.size()) {
            set<int> s(nums1.begin(),nums1.end());
            for (int i = 0; i < nums2.size(); i++) {
                if (s.count(nums2[i])) {
                    ans.push_back(nums2[i]);
                    s.erase(nums2[i]);
                }
            }
        }
        else {
            set<int> s(nums2.begin(),nums2.end());
            for (int i = 0; i < nums1.size(); i++) {
                if (s.count(nums1[i])) {
                    ans.push_back(nums1[i]);
                    s.erase(nums1[i]);
                }
            }
        }
        return ans;
    }
};