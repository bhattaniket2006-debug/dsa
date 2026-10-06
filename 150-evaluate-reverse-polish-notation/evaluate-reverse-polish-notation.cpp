class Solution {
public:
    bool isoperand(string s) {
        if(s == "+" || s == "-" || s == "*" || s == "/") {
            return 1;
        }
        else {
            return 0;
        }
    }

    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;

        for(int i = 0; i < n; i++) {

            if(isoperand(tokens[i]) == 0) {
                st.push(stoi(tokens[i]));
            }
            else {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                char c = tokens[i][0];

                if(c == '+') {
                    int result = b + a;
                    st.push(result);
                }
                else if(c == '-') {
                    int result = b - a;
                    st.push(result);
                }
                else if(c == '*') {
                    int result = b * a;
                    st.push(result);
                }
                else {
                    int result = b / a;
                    st.push(result);
                }
            }
        }

        return st.top();
    }
};