class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0, n = points.size();
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b){
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]>b[1];
        });
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                bool flag = true;
                int x1 = points[i][0], x2 = points[j][0], y1 = points[i][1], y2 = points[j][1];
                if(y1 < y2) continue;
                for(int k = 0; k < n; k++){
                    if(k==i || k==j) continue;
                    if(points[k][0] <= x2 && points[k][0] >= x1 && points[k][1] >= y2 && points[k][1] <= y1){
                        flag = false;
                        break;
                    }
                }
                if(flag) ans++;
            }
        }
        for(auto i: points) cout << i[0] << ' '<< i[1] << endl;
        return ans;
    }
};