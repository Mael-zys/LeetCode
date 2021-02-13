//first solution
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = s.size();
        char temp;
        int i = 0;
        while (i < l - i - 1)
        {
            temp = s[i];
            s[i] = s[l - i - 1];
            s[l - i - 1] = temp;
            i++;
        }
    }
};

//second solution, using slt
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }
};