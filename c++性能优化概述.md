c++ 程序的性能优化可以从Memory optimization和compute optimization等角度入手。

内存优化包括，
1. 减少内存使用
比如:
使用合适的数据结构


2. 提高内存访问效率
比如:
避免频繁申请/释放内存，减少new/delete的使用，改用对象池和内存池。
减少堆分配，使用栈分配，使用std::array替代std::vector
使用顺序访问的数组替代跳跃访问的链表

3. 降低内存碎片化heap fragmentation
比如:

4. 避免内存泄露memory leak和悬挂指针dangling pointer。
比如:
使用c++推荐的智能指针 std::unique_ptr / std::shared_ptr

算力优化包括
1. 提升算法效率，更快更低复杂度的实现

2. 利用并行计算资源，如多线程，SMID，GPU
使用现代并发库
减少锁竞争

3. 减少无效与重复计算
比如:
避免不必要的拷贝，使用std::move进行移动语义，使用const T& 或T&&避免值传参
使用emplace而不是Insert/push_back. emplace直接在容器内构造。
用reserve减少内存重分配。

4. 利用编译期计算constexpr
将运行期的计算量转移到编译器。


