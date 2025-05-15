题目描述：
从Magazine里挑Letter，组成Ransome Note, Magazine里的每一个Letter只能用一次。

1. 记录Magazine里每一个字符出现的次数，适合使用unordered_map<char, int>;
2. 对于ransome note里的每一个字符，每出现一次，就从之前的map里，减去对应字符的计数。
3. 最后统计map里每个字符的计数，不为负数，则符合条件。

优化：
可以在不满足条件的时候，直接返回false,以提高效率
具体操作为：
在循环ramsome note里的字符时，即与magzin里的字符计数比较，发现不满足条件，立即返回false。


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> count;
        for(char c : magazine){
            count[c]++;
        }
        for(char c : ransomNote){
            if(count[c] <= 0){
                return false;
            }
            count[c]--;
        }

        return true;
    }
};

关于unordered_map特殊的一点：

如果 c 不在 count 中，不会发生运行时错误，程序仍然会运行，只是 count[c] 的值会是 默认值 0，因为：
在 C++ 中使用 unordered_map（或 map）时，count[c] 会隐式地插入键 c，如果它不存在，则初始化其值为 0。