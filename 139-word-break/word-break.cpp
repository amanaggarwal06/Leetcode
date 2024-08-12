class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        vector<int> dp(n+2, 0);
        unordered_map<string, bool> mp;

        for(int i=0; i<wordDict.size(); i++){
            mp[wordDict[i]] = true;
        }

        //ini
        dp[n+1] = 1; //empty string

        for(int i=n; i>0; i--){

            string temp = "";
            for(int j=i; j<n+1; j++){

                temp += s[j-1];
                if(mp[temp] && dp[j+1]){
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[1];
    }
};