class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int size = hand.size();
        //edge case
        if(size % groupSize != 0){
            return false;
        }

        unordered_map<int, int> mp;

        for(int i=0; i<size; i++){
            mp[hand[i]]++;
        }

        priority_queue<int, vector<int>, greater<int> > minh;

        for(auto it:mp){
            minh.push(it.first);
        }


        while(!minh.empty()){

            int prev = -1;
            vector<int> temp;

            for(int i=0; i<groupSize; i++){

                int element = minh.top();
                minh.pop();
                mp[element]--;

                if(i!=0 && element != prev+1){
                    return false;
                }
                else{
                    prev = element;
                }

                if(mp[element]){
                    temp.push_back(element);
                }

            }

            for(int i=0; i<temp.size(); i++){
                minh.push(temp[i]);
            }
        }

        return true;
        
    }
};