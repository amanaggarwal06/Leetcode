class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int count[26] = {0};
        int n = s.size(), l=0, r=0, maxlen=0, max_cnt = 0;

        while(r<n){

            count[s[r] - 'A']++;

            max_cnt = max(max_cnt, count[s[r] - 'A']);
            int changes = (r-l+1) - max_cnt;

            if(changes > k){

                count[s[l] - 'A']--; max_cnt = 0;

                for(int i=0; i<26; i++){
                    max_cnt = max(max_cnt, count[i]);
                }

                changes = (r-l+1) - max_cnt;
                l++;

            
            }

            if(changes <= k){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
            
        }

        return maxlen;
    }
};