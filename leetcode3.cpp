class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 基于滑动窗口机制计算最长无重复子串
        // set用于过滤
        set<char> set;
        int maxLength = 0;
        for(int i = 0; i < s.size(); i++) {
            // set.insert(s[i]);
            for(int j = i; j < s.size(); j++) {
                if(!set.count(s[j])) {
                    set.insert(s[j]);
                    // 不是所有的用例都是有相同元素出现来触发截止，所以将判断拿到这里来
                    if(maxLength < set.size()) {
                        maxLength = set.size();
                    }
                } else { 
                    break;
                }
            }
            set.clear();  
        }
        
        return maxLength;
    }
};
