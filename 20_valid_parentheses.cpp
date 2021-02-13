// use stack

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto& i : s) {
            if (i=='(' || i=='[' || i=='{')
                st.push(i);
            else if (!st.empty() && ((i-1)==st.top() || (i-2)==st.top())) //ascii code difference between ( and ) is 1, while between [ and ], or { and } are 2
                st.pop();
            else return false;
        }
        if (st.empty())
            return true;
        else return false;
    }
};