class Solution {
public:
    string reverseWords(string s) {
        if (s.size() <= 1) return s;
        int l = 0;
        while (s.find(' ', l) != -1) {
            int l1 = s.find(' ', l);
            int i = 0;
            while (l + i < l1 - 1 - i) {
                char temp = s[l + i];
                s[l + i] = s[l1 - 1 - i];
                s[l1 - 1 - i] = temp;
                i ++;
            }
            l = l1 + 1;
        }
        // last word
        int i = 0;
        while (l + i < s.size() - 1 - i) {
            char temp = s[l + i];
            s[l + i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = temp;
            i ++;
        }
        return s;
    }
};