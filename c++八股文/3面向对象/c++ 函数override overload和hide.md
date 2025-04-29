1. 函数overload
实现原理：
编译器通过函数签名进行区分，不同的参数类型参数个数，生成不同的符号名(namemangling函数名修饰)，实现函数共存。
编译时实现。

class Printer {
public:
    void print(int a) { std::cout << "int\n"; }
    void print(double b) { std::cout << "double\n"; }  // ✅ 重载
};

Printer p;
p.print(5);     // 👉 输出 int
p.print(3.14);  // 👉 输出 double


2. 函数override
编译器为类生成一个虚函数表vtable,其中存储虚函数的地址
每个对象内部隐含一个vptr，指向所属类的vtable.
当调用函数时，根据对象的不同，沿着vptr查找实际函数地址并调用，实现运行时多态。
运行时实现动态绑定。
c++11起，推荐和override配合使用。

class Base {
public:
    virtual void speak() { std::cout << "Base\n"; }
};

class Derived : public Base {
public:
    void speak() override { std::cout << "Derived\n"; }  // ✅ 重写
};

Base* ptr = new Derived;
ptr->speak();  // 👉 输出 Derived（运行时多态）

3. 函数hide

override是在派生类中，重新定义基类中的函数，基类中的函数必须有virtual关键字。
如果没有virtual 关键字，那么基类中的函数就会被隐藏
静态绑定

函数隐藏示例:
class Base {
public:
    void show() { std::cout << "Base::show" << std::endl; }
};

class Derived : public Base {
public:
    void show() { std::cout << "Derived::show" << std::endl; } // ❌ 非虚函数，属于重定义（隐藏）
};

Base* ptr = new Derived;
ptr->show();  // 👉 输出 Base::show

问题：“被隐藏的是谁？”
✅ 正确答案：
被“隐藏”的是基类的同名函数 Base::show 在派生类作用域中的可见性，但调用仍然是基类版本，因为函数不是 virtual，调用发生的是静态绑定。

🎯 关键点解释：
函数隐藏（redefine/hide）：
派生类中定义了一个与基类同名的函数（不管参数是否相同），会隐藏基类中所有同名函数。
如果你使用的是对象/指针类型是 Derived，则调用的是 Derived::show。
如果你使用的是对象/指针类型是 Base，则调用的是 Base::show（静态绑定）。

为什么说基类函数被隐藏？
指的是在派生类作用域中，无法通过派生类对象直接访问到基类的 show()。
除非你显式用作用域操作符调用：Derived d; d.Base::show();