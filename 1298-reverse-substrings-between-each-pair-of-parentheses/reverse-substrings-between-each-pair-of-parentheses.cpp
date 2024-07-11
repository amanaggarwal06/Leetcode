class Solution {
public:
    string reverseParentheses(string s) {
        
        vector<char> ans;
        stack<int> st; int size = s.size();

        for(int i=0; i<size; i++){

            if(s[i] == '(') st.push(ans.size());
            else if(s[i] == ')'){

                int start = st.top();
                st.pop();
                reverse(ans.begin() + start, ans.end());
            }
            else{
                ans.push_back(s[i]);
            }
        }

        return string(ans.begin(), ans.end());
    }
};