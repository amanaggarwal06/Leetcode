class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int size = s.size();
        int cnt = 0;
        for(int i=0 ;i<size; i++){
            if(s[i] == '1') cnt++;
        }

        cnt--;
        string temp = "";

        while(size != 1){

            if(cnt != 0){
                temp.append("1");
                cnt--;
            }
            else{
                temp.append("0");
            }
            size--;
        }

        temp.append("1");
        return temp;
    }
};