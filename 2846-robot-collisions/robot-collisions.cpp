class robot{

public:
    int pos, health, indx;
    char dir;

    robot(int _pos, int _health, char _dir, int _indx){
        this->pos = _pos;
        this->health = _health;
        this->dir = _dir;
        this->indx = _indx;
    }
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        

        //similar to asteroid collisions
        vector<robot> st;
        int size = positions.size();

        vector<robot> v;

        for(int i=0; i<size; i++){

            robot r1(positions[i], healths[i], directions[i], i);
            v.push_back(r1);
        }

        sort(v.begin(), v.end(), [](const robot& it1, const robot& it2){
            return it1.pos < it2.pos;
        });

        for(int i=0; i<size; i++){

            if(v[i].dir == 'R'){
                st.push_back(v[i]);
            }
            else{
                //collision can occur

                // while(!st.empty() && st.top().dir == 'L'){

                //     auto it = st.top();
                //     if(v[i].second.first == health[i]){
                //         st.pop();
                //         break;
                //     }
                //     else if(v[i].second.first < health[i]){
                //         st.pop();
                //         health[i]--;
                //     }
                //     else{
                //         v[i].second.first--;
                //         break;
                //     }
                // }
                bool flag = false;

                while (!st.empty() && st.back().health <= v[i].health && st.back().dir == 'R') {
                        if (st.back().health == v[i].health) {
                            st.pop_back();
                            flag = true;
                            break;
                        }
                        v[i].health--;
                        st.pop_back();
                }

                if (!flag && !st.empty() && st.back().dir == 'R' && st.back().health > v[i].health) {
                        st.back().health--;
                        flag = true;
                }

                    
                if (!flag) {
                    st.push_back(v[i]);
                }
            }

            
        }

        sort(st.begin(), st.end(), [](const robot& it1, const robot& it2){
            return it1.indx < it2.indx;
        });

        vector<int> ans;
        for(int i=0; i<st.size(); i++){
            ans.push_back(st[i].health);
        }

        return ans;

    }
};