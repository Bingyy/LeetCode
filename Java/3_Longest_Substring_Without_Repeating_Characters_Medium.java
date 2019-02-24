/**
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
    public int lengthOfLongestSubstring(String s) {
        // 双指针问题
        if (s == null || s.length() == 0) {
            return 0;
        }
        
        HashMap<Character, Integer> map = new HashMap<>();
        int res = 0;
            
        for (int i = 0, j = 0; i < s.length(); i++) {
            if (map.containsKey(s.charAt(i))) {
                // j是不重复的起点
                j = Math.max(j, map.get(s.charAt(i)) + 1); // 重复元素靠前的位置，i > j
            }
            map.put(s.charAt(i), i);
            res = Math.max(res, i - j + 1);
        }
        return res;
    }
  
    // 基于HashSet的做法
    public int lengthOfLongestSubstring_version_2(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        HashSet<Character> set = new HashSet<>();
        int res = 0;
        
        for (int i = 0, j = 0; i < s.length();) {
            if (set.contains(s.charAt(i))) {
                set.remove(s.charAt(j++));
            } else {
                // 手动处理i++
                set.add(s.charAt(i++)); 
                res = Math.max(res, set.size());
            }
        }
        return res;
    }
}
