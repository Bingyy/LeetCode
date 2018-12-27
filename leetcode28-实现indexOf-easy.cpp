class Solution {
public:
    // 这个我参考了别人的代码，自己写的只能跑52个样例通过，非AC代码
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        if(needle == haystack) return 0;
        if(needle.size() > haystack.size()) return -1;
        
        int j = 0; // 跟踪在needle中的下标
        int i = 0;
        for(i = 0; i < haystack.size(); i++) {
            
            if(j == needle.size()) {
                return i - needle.size();
            }
            
            if(needle[j] == haystack[i]) {
                j++;
 
            }
            else {
                i -= j;
                j = 0;
            }     
        }
        if(j == needle.size()) {
            return i - needle.size();
        }
          
        return -1;
    }
};
