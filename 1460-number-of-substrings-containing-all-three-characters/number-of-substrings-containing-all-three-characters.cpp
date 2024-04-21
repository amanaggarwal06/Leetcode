class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.size();
        int l=0, r=0, maxi = 0;
        int lastseen[3] = {-1,-1,-1};

        while(r<n){

            lastseen[s[r] - 'a'] = r;

            if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
                maxi = maxi + 1 + min(lastseen[0], min(lastseen[1], lastseen[2]));
            }

            r++;
        }

        return maxi;
    }
};