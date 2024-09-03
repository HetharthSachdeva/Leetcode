class Solution {
public:
    int getLucky(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        string ans = "";
        for(char i : s){
            int l = i-'a'+1;
            ans+= to_string(l);
        }
        int no = 0;
        for(char i: ans){
            no+= i-'0';
        }
        if(k==1) return no;
        else k--;
        string a = to_string(no);
        while(k--){
            int ans = 0;
            for(char x: a){
                ans+= x - '0';
            }
            a = to_string(ans);
        } 
        return stoi(a);
    }
};