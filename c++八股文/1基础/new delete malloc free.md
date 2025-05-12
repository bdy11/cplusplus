在 C++ 中，new/delete 和 malloc/free 有什么区别？为什么在 C++ 中通常更推荐使用 new/delete？

new/delete是面向对象的，用于构造和析构对象。
new不仅分配内存，还调用了对象的constructor。
delete不仅释放了内存，还调用了析构函数。

而malloc/free来自于C
使用Malloc/free不会调用构造/析构函数。

C++中推荐使用new/delete，因为它们支持完整的对象生命周期管理。