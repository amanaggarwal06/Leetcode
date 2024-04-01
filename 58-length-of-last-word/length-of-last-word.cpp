class Solution {
public:
    int lengthOfLastWord(string s) {
        
        //can be done with the help of stringstream
        stringstream ss;
        ss << s;

        string data;

        int len = 0;

        while(ss >> data){

            len = data.size();
            
        }

        return len;
    }
};