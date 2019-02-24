class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) 
            return string();
        if(strs.size() == 1)
            return strs[0];
        string res;
        
        // 两两比较，将第一个作为基准，注意遍历数量是在第二个for
        for(int i = 0; i < strs[0].size(); i++) {
            for(int j = 0; j < strs.size(); j++) {
                if (strs[0][i] != strs[j][i])
                    return res;
            }
            res += strs[0][i];
        }
        return res;
    }
};
