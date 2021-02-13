//sliding window

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size < 1) return size;
        vector<int> L(128,-1);  // input only contains english letters, digits, etc.
        int ans = 0;
        int start = 0;
        for (int R = 0; R < size; R++)
        {
            start = max(start, L[s[R]]+1);
            ans = max(ans, R - start + 1);
            L[s[R]] = R;
        }
        return ans;
    }
};