LRU算法在缓存满时，淘汰最近最少使用的数据，保持缓存中都是最近使用过的数据。

常见实现方式有两种
✅ 方法一：哈希表 + 双向链表（最常用）
思路：

使用 哈希表（unordered_map） 进行 O(1) 级别的查找；

使用 双向链表（list） 维护访问顺序，头部是最新访问的，尾部是最久未访问的。

操作时间复杂度：

插入：O(1)

访问（get/put）：O(1)

删除：O(1)

结构图：

哈希表： key -> 链表节点指针

双向链表：
[head] <-> [最近访问的数据] <-> ... <-> [最久未访问的数据] <-> [tail]
核心操作：

每次访问 key，把对应节点移动到链表头部；

新增时：
如果缓存满了，移除链表尾部节点，同时从哈希表中删除；

然后把新节点插入链表头部，并加入哈希表；
class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cacheList;  // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) return -1;
        // 移动到头部
        auto it = cacheMap[key];
        cacheList.splice(cacheList.begin(), cacheList, it);
        return it->second;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // 更新并移动到头部
            auto it = cacheMap[key];
            it->second = value;
            cacheList.splice(cacheList.begin(), cacheList, it);
        } else {
            if (cacheList.size() == capacity) {
                // 删除尾部元素
                auto last = cacheList.back();
                cacheMap.erase(last.first);
                cacheList.pop_back();
            }
            cacheList.emplace_front(key, value);
            cacheMap[key] = cacheList.begin();
        }
    }
};



方法二：使用 std::list + std::map 变种（较少用）
有些实现可能用 std::map 替代 unordered_map，但效率会降低为 O(logN)，不如第一种方式高效。

三、适用场景
操作系统中的页面置换算法；

浏览器、数据库、内存缓存系统（如 Redis 缓存淘汰）；

实现最近打开文件列表等。