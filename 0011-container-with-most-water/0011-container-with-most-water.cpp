class Solution {
public:
    int maxArea(vector<int>& height) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        int maxarea = 0;
        int i = 0, j = height.size()-1;

        while(i<j){
            int area = (j-i)*(min(height[i],height[j]));
            if(area > maxarea) maxarea = area;
            if(height[j] > height[i]) i++;
            else j--;
        }

        return maxarea;
    }
};