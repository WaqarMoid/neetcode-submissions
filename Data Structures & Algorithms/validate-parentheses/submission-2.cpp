class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (st.empty()) return false;

                char top = st.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    st.pop();  // brackets match
                } 
                else {
                    return false;  // mismatch (like (])
                }
            }
        }

        return st.empty();  // all brackets must be closed
    }
};

