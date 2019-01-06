/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s{1}; // if use int, some case overflow
        auto it = s.begin();
        
        while(--n) {
            s.insert(*it * 2); // x 2
            s.insert(*it * 3); // x 3
            s.insert(*it * 5); // x 5 
            ++it;
        }
        return *it;
    }
};

