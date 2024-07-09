class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        double ans = 0.00;
        int curr_time = customers[0][0], size = customers.size();

        for(int i=0; i<size; i++){

            int arrival_time = customers[i][0];
            if(curr_time < arrival_time){
                curr_time = arrival_time;
            }

            //add the food prep time in curr_time
            curr_time += customers[i][1];

            //add the waiting time of each person
            ans += (curr_time - arrival_time);
        }

        ans = ans/(double)(size);
        return ans;
    }
};