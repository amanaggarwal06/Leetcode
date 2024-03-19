class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        //base case
        if(n==0){
            return tasks.size();
        }

        unordered_map<char, int> mp;
        priority_queue<int> maxh;

        for(int i=0; i<tasks.size(); i++){
            mp[tasks[i]]++;
        }

        for(auto it:mp){
            maxh.push(it.second);
        }

        int total_time = 0;
        int cycle = n+1;

        while(!maxh.empty()){

            int cnt = 0;
            vector<int> temp;

            for(int i=0; i<cycle; i++){

                if(!maxh.empty()){
                    temp.push_back(maxh.top());
                    maxh.pop();
                    cnt++;
                }
            }

            for(int i=0; i<temp.size(); i++){
                
                int val = temp[i];
                val--;

                if(val){
                    maxh.push(val);
                }
            }

            total_time += (!maxh.empty()) ? cycle : cnt;
        }

        return total_time;
    }
};