class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int n = tickets.size();
        //edge case
        if(tickets[k] == 0){
            if(k == 0) return 0;
            return k;
        }

        // int time[n] = {0}; --> not defined as variable size array may not be possible for compiler to make it/
        // vector<int> time(n,0);
        int time = 0;

        while(tickets[k] != 0){

            for(int i=0; i<n; i++){

                if(tickets[i] != 0){
                    time++;
                    tickets[i]--;
                }

                if(i == k && tickets[k] == 0) return time;
            }
        }

        return time;
    }
};