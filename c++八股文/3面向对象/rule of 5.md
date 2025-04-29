rule of 5是一种编程准则。
以下五个特殊成员构造函数，当你需要自定义一个的时候，通常应该显式地自定义其他四个，以保证资源管理地安全性和效率。

拷贝构造函数
拷贝赋值
移动构造
移动赋值
析构函数

代码示例：
class MyResource {
private:
    int* data;

public:
    // 构造
    MyResource(int val) : data(new int(val)) {}

    // ✅ 拷贝构造函数（深拷贝）
    MyResource(const MyResource& other) : data(new int(*other.data)) {}

    // ✅ 拷贝赋值
    MyResource& operator=(const MyResource& other) {
        if (this != &other) {
            *data = *other.data;
        }
        return *this;
    }

    // ✅ 移动构造（转移资源）
    MyResource(MyResource&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // ✅ 移动赋值
    MyResource& operator=(MyResource&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    // ✅ 析构函数
    ~MyResource() { delete data; }
};

为什么5个一起？
当一个类需要手动管理资源时，比如用到了new/malloc，就必须自己定义析构函数，以及其他四个构造函数。因为编译器不会自动生成他们，必须由你自己来确保资源拷贝和释放地正确性。


“哪怕析构函数没有释放资源，只要你自己写了它，编译器就会认为你要控制对象的生命周期，从而不会再自动生成移动操作函数，这可能导致性能退化或函数缺失。因此，写析构函数时，要么配套写全 Rule of Five，要么明确 default 该生成的函数。”

如果你的类不直接管理资源（比如没有裸指针 new/delete 等），通常你只需要写构造函数，其他特殊成员函数完全可以让编译器自动生成。

这就是现代 C++ 推荐的做法，被称为 Rule of Zero。