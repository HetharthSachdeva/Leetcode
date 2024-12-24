class Solution {
public:
    map<char, string> alphas;

    vector<string> ans;
    void helper(string numbers, string a, int index){
        if(numbers=="") return;
        if(index == numbers.size()){
            ans.push_back(a);
            return;
        }
        for(int i = 0; i < alphas[numbers[index]].size(); i++){
            helper(numbers, a+alphas[numbers[index]][i], index+1);
        }
    }
    vector<string> letterCombinations(string digits) {    
        alphas['2'] = "abc";
        alphas['3'] = "def";
        alphas['4'] = "ghi";
        alphas['5'] = "jkl";
        alphas['6'] = "mno";
        alphas['7'] = "pqrs";
        alphas['8'] = "tuv";
        alphas['9'] = "wxyz";    
        
        helper(digits, "", 0);
        return ans;
    }
};