class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        map<int,int> hash;
        for(auto val : nums1)
        {
            hash[val]++;//以元素本身为key,value表示出现次数
        }
        for(auto val : nums2) //对于每个在nums2中的元素
        {
            if(hash[val] > 0) //如果在hash中出现，则压栈并将次数减一
            {
                result.push_back(val);
                hash[val]--;
            }
        }
        return result;
    }
};