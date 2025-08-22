class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        int n = hand.size();
        map<int, int> f;
        for(auto i: hand) f[i]++;
        for(auto i =f.begin(); i != f.end(); i++){
            if(i->second==0) continue;
            else{
                for(int j = 1; j < gs; j++){
                    if(f[i->first+j]<i->second) return false;
                    else f[i->first+j] -= i->second;
                }
                i->second = 0;
            }
        }
        return true;
    }
};