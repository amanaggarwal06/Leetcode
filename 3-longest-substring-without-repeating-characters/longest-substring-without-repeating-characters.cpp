class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> count;
        int left = 0, right = 0, maxi = 0;

        while(left <= right && right < s.size()){

            count[s[right]]++;

            while(left <= right && count[s[right]] > 1){
                count[s[left]]--;
                left++;
            }

            maxi = max(maxi, right-left+1);
            right++;
        }

        return maxi;
    }
};