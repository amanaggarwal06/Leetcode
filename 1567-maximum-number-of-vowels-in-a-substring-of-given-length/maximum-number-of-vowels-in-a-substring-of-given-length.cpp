class Solution {
public:
    int maxVowels(string s, int k) {
        
        //brute--> generate all subarrays of length = k and then count the num of vowels in that subarray to maximize the cnt;
        /// T.C. = O(n^2);

        int l=0, r=0, maxcnt = 0, n = s.size(), vowels = 0;

        //storing vowels
        unordered_map<char, int> mp;
        char ch[] = {'a', 'e', 'i', 'o', 'u'};

        for(int i=0; i<5; i++){
            mp[ch[i]]++;
        }

        while(r<n){

            if(mp.find(s[r]) != mp.end()){
                vowels++;
            }

            if(r-l+1 > k){

                if(mp.find(s[l]) != mp.end()){
                vowels--;
                }
                l++;
            }
            
            if(r-l+1 == k){
                maxcnt = max(maxcnt, vowels);
            }

            r++;
        }

        return maxcnt;
    }
};