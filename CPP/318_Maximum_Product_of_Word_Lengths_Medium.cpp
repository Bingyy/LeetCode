class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxn = 0;
        int n = words.size();
        vector<int> bits(n,0);
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                bits[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(bits[i] & bits[j]) continue;
                maxn = max(maxn,(int)(words[i].size() * words[j].size()));
            }
        }
        return maxn;
    }
};