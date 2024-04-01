class Solution {
public:
    int lengthOfLastWord(string s) {
        
        //can be done with the help of stringstream
        // stringstream ss;
        // ss << s;

        // string data;

        // int len = 0;

        // while(ss >> data){

        //     len = data.size();
            
        // }

        // return len;

        // int start = 0, last = 0, word_cnt = 0, prev_start = 0;

        // for(int i=0; i<s.length(); i++){

        //     if(s[i] == ' '){

        //         if(start && end){
        //             word_cnt++;
        //             prev_start = start;
        //         }
        //     }
        //     else{

        //         if(start == 0){
        //             start = i;
        //         }
        //         else if(start && word_cnt == 0){
        //             last = i;
        //         }
        //         else if(start && word_cnt  && start == prev_start){
        //             start = i;
        //         }
        //         else{
        //             last = i;
        //         }
        //     }
        // }

        // return last-start+1;

        // int i = s.length()-1;
        // int first = 0, last = 0;

        // while(i>=0){

        //     if(s[i] == ' '){
        //         i--;

        //         if(first && last){
        //             break;
        //         }
        //     }
        //     else{

        //         if(first == 0){
        //             first = i;
        //         }
        //         else{
        //             last = i;
        //         }
        //     }
        // }

        // return first-last+1;

        int len = 0;
        int i = s.size()-1;

        while(i>=0 && s[i] == ' '){
            i--;
        }

        while(i>=0 && s[i] != ' '){
            len++;
            i--;
        }

        return len;
    }
};