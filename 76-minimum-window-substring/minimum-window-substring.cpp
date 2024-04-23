class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        //brute---> generating all subarrays and then calculating min length of subarray

        //edge case
        if(n<m) return "";
        
        int hmap[256] = {0};

        for(int i=0 ;i<t.size(); i++){
            hmap[t[i]]++;
        }

        int l=0, r=0, minlen = 1e9, start_indx = -1, cnt=0;
        

        while(r<n){

            if(hmap[s[r]] > 0) {cnt++;}
            hmap[s[r]]--;

            while(cnt == m){

                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    start_indx = l;
                }
                hmap[s[l]]++;
                if(hmap[s[l]] > 0){
                    cnt--;
                }

                l++;
            }

            r++;
        }

        if(start_indx == -1) return "";
        return s.substr(start_indx, minlen);


    }
};