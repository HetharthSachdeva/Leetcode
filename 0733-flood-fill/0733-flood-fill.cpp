class Solution {
public:
    void fill(vector<vector<int>>& image, int i, int j, int o, int& color){
        
        if(i>=0 && j>=0 && i<image.size() && j<image[0].size() && image[i][j]==o){ 
             
           image[i][j] = color;
        
        }
        else return;

        fill(image, i-1, j, o, color);
        fill(image, i+1, j ,o, color);
        fill(image, i, j-1, o, color);
        fill(image, i, j+1, o, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]!=color)
        fill(image, sr, sc, image[sr][sc], color);
        return image;
    }
};