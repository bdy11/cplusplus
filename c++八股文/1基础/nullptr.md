nullptr可以调用成员函数吗？
答：可以，但有前提条件，只要该函数不访问任何成员变量或成员函数

成员函数其实是个特殊的隐藏函数，它的底层签名类似于
void MyCLass::func()

编译器看到的是
void func(MyClass* this);

当你写
MyClass* p = nullptr;
p->func();

等效于
func(nullptr);   // 传入this指针为nullptr,只要func()没有用到this->成员变量，就不会访问空指针，不会崩溃


