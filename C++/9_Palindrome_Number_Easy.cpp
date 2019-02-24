class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else {
            vector<int> res = toDigits(x);
            for(int i = 0; i < res.size(); i++) {
                if(res[i] != res[res.size()-1-i]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    vector<int> toDigits(int x) {
        vector<int> res;
        while(x != 0) {
            int digit = x % 10;
            x /= 10;
            res.push_back(digit);
        }
        return res;
    }
};
