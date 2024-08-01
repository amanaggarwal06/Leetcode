class Solution {
public:
    int countSeniors(vector<string>& details) {
        
        int ans = 0;

        for(int i=0; i<details.size(); i++){

            string s = details[i].substr(11,2);
            if(stoi(s) > 60) ans++;
        }

        return ans;
    }
};