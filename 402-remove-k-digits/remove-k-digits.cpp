class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string ans;
        int length = num.length();
        
        for(int i=0; i< length; i++){
            
            char ch = num[i];
            
            while( !ans.empty() && ch < ans.back() && k>0){
                ans.pop_back();
                k--;
            }
            
            if(ans.empty() && ch != '0'){
                ans.push_back(ch);
            }
            else if( !ans.empty() ){
                ans.push_back(ch);
            }
        }
        
        while( !ans.empty() && k>0){
            ans.pop_back();
            k--;
        }
        
        if(ans.empty()){
            return "0";
        }
        
        return ans;
    }
};