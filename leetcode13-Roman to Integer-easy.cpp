class Solution {
public:
    int romanToInt(string s) {
        map<char, int> map;
        map.insert(pair<char,int>('I',1));
        map.insert(pair<char,int>('V',5));
        map.insert(pair<char,int>('X',10));
        map.insert(pair<char,int>('L',50));
        map.insert(pair<char,int>('C',100));
        map.insert(pair<char,int>('D',500));
        map.insert(pair<char,int>('M',1000));
        
        int ans = 0;
        for(int i = 0; i < s.size() ; i++) {
            if(map[s[i]] < map[s[i+1]]) {
                ans -= map[s[i]];
            }
            else {
                ans += map[s[i]];
            }
        }
        return ans;
    }
};
