class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        //edge case
        if(beginWord == endWord){
            return 1;
        }
        
        set<string>st(wordList.begin(), wordList.end());
        

        queue<pair<string, int>>q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty()){

            string word = q.front().first;
            int len = q.front().second;
            q.pop();

            if(word == endWord){
                return len;
            }

            for(int i=0; i<word.size(); i++){

                char original = word[i];
                for(char ch = 'a' ; ch<= 'z'; ch++){
                    word[i] = ch;

                    if(st.find(word) != st.end()){
                        q.push({word, len+1});
                        st.erase(word);
                    }

                    word[i] = original;
                }
            }
        }

        return 0;
    }
};