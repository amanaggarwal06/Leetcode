class Solution {
public:
    bool isValid(string s) {
        
        unordered_map<char, char> mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';

        stack<char> st;
        st.push(s[0]);

        for(int i=1; i<s.size(); i++){

            if( !st.empty() && mp[st.top()] == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        return st.size() ? false : true;

    }
};