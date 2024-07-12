class Solution {

    int solve(string &copy, int cost, string ref){

        stack<char> st; int ans = 0;
        for(auto i: copy){

            if(i==ref[1] && !st.empty() && st.top() == ref[0]){
                ans += cost;
                st.pop();
            }
            else{
                st.push(i);
            }
        }

        string res = "";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        copy = res;
        return ans;
    }
public:
    int maximumGain(string s, int x, int y) {
        
        //Approach ---> kind of brute---> first get all high cost substr
        //          then traverse string to get low cost substr
        string copy = s;

        int large, small;
        string str1, str2;

        if(x>y){
            large = x; str1 = "ab";
            small = y; str2 = "ba";
        }
        else{
            large = y; str1 = "ba";
            small = x; str2 = "ab";
        }

        return solve(copy, large, str1) + solve(copy, small, str2);
    }
};