class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> f;
        int n = answers.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            f[answers[i]]++;
        }

        for(auto i: f){
            if(i.first+1 >= i.second) ans+=i.first+1;
            else{
                ans+= (ceil(i.second/(float)(i.first+1)))*(i.first+1);
            }
        }

        return ans;

    }
};