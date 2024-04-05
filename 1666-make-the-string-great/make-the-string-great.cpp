class Solution {
public:
    string makeGood(string s) {
        
        int len = s.size();
        //edge case
        if(len == 0 ) return "";
        else if(len == 1) return s;

        stack<char> st;
        string ans = "";

        for(int i=0; i<len; i++){

            if(st.empty()){
                st.push(s[i]);
            }
            else{

                char ch = st.top();
                st.pop();

                if(ch >= 'a' && ch <= 'z' && s[i] >= 'A' && s[i] <= 'Z' && (ch - 'a' == s[i] - 'A')){
                    continue;
                }
                else if(ch >= 'A' && ch <= 'Z' && s[i] >= 'a' && s[i] <= 'z' && (ch - 'A' == s[i] - 'a')){
                    continue;
                }
                else{
                    st.push(ch);
                    st.push(s[i]);
                }
            }
        }

        if(st.empty()) return "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;


    }
};