class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int ans = numBottles;

        while(true){

            int quo = numBottles/numExchange;
            int rem = numBottles%numExchange;
            ans += quo;
            numBottles = quo + rem;

            if(numBottles < numExchange){
                break;
            }
        }

        return ans;
    }
};