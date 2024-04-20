class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        int count[256];
        for(int i=0; i<256; i++){
            count[i] = -1;
        }

        int l = 0, r = 0, maxi = 0;

        while(r<n){

            if(count[s[r]] != -1){

                if(count[s[r]] >= l){
                    l = count[s[r]] + 1;
                }
            }

            //l to r -->subarray
            maxi = max(maxi, r-l+1);
            count[s[r]] = r;
            r++;
        }

        return maxi;
    }
};