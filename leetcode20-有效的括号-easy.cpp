class Solution {
public:
    bool isValid(string s) {
        // 使用栈
        vector<int> stack;
        //使用map存储括号对
        map<char,char> map;
        map.insert(pair<char,char>(')','('));
        map.insert(pair<char,char>(']','['));
        map.insert(pair<char,char>('}','{'));
        
        for(int i = 0; i < s.size(); i++) {
            
            if(s[i] == '(' || s[i] == '[' || s[i] == '{' ) {
                // 直接压栈
                stack.push_back(s[i]);
            }
            
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
                // 右括号则从栈中取出头部，判断是否为对应的左括号
                if(!stack.empty()) {
                    char top = stack.back();
                    if(top == map[s[i]]) {
                        stack.pop_back();
                    } else { // 如果有右括号但是栈内无元素可匹配返回false
                        return false;
                    }
                } else { // 如果有右括号但是栈内无元素
                    return false;
                }
            }
        }
        
        if(stack.empty()) {
            return true;
        }
        
        return false;
        
    }
};
