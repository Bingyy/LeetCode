#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // 以空间换速度 - 两次哈希表
        // 让数值作为键，索引作为值
        map<int,int> map;
        vector<int> res;
        
        for(int i = 0; i < nums.size(); i++) {
            map.insert(pair<int,int>(nums[i], i));
            // printf("Map: %d", map[i]);
        }

        for(int i = 0; i < nums.size(); i++) {
            int rest = target - nums[i];
            // map.count(key) ==> 1: contains, 0: not contains
            if(map.count(rest) && map[rest] != i) {
                res.push_back(i);
                res.push_back(map[rest]);
                return res;
            }
        }   
        return res;
    }
};

void trimLeftTrailingSpaces(string &input) {
    // C++11匿名函数
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }
    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        getline(cin, line);
        int target = stringToInteger(line);    
        vector<int> ret = Solution().twoSum(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
