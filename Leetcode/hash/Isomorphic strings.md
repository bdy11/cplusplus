题目描述：
两个字符串，在字符顺序不变的情况下，两个字符串能通过替换字符，互换

Example 1:
Input: s = "egg", t = "add"
Output: true
Explanation:
The strings s and t can be made identical by:
Mapping 'e' to 'a'.
Mapping 'g' to 'd'.

Example 2:
Input: s = "foo", t = "bar"
Output: false
Explanation:
The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"
Output: true

解题思路：
1. 首先判断两个字符串长度是否相等，不相等则返回false
2. 用map相互映射两个字符串，遍历每个字符，对每个字符建立映射，每个新遍历到的字符，在map中建立映射，下次再遇到相同字符，查看映射对应的字符，与另外的字符串中对应位置的字符做比较，如果不相同，则返回false

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        unordered_map<char, char> m1, m2;
        for(int i = 0; i < s.size(); i++){
            if(m1.find(s[i]) == m1.end()){
                m1[s[i]] = t[i];
            }else{
                if(m1[s[i]] != t[i]){
                    return false;
                }
            }

            if(m2.find(t[i]) == m2.end()){
                m2[t[i]] = s[i];
            }else{
                if(m2[t[i]] != s[i]){
                    return false;
                }
            }
        }

        return true;
    }
};