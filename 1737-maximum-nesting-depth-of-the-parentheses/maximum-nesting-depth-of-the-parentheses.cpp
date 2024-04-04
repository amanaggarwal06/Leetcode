class Solution {
public:
    int maxDepth(string s) {
        
        int len = s.size();
        //edge case
        if(len == 0) return 0;
        else if(len==1 && ( s[0] != '(' || s[0] != ')' )){
            return 0;
        }
        // else if(len==1){
        //     return 1;
        // }

        int cnt = 0, maxi = INT_MIN;

        for(int i=0; i<len; i++){

            if(s[i] == ')') cnt--;
            else if(s[i] == '(') cnt++;

            if(cnt < 0) cnt = 0;
            maxi = max(maxi, cnt);
        }

        if(cnt != 0) return 0;

        return maxi;
    }
};