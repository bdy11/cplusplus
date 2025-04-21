1. 为什么需要singelton模式
解决全局对象的控制问题，确保一个类在整个程序运行过程中只有一个实例，并提供一个全局访问点。

2. 如何保证线程安全
c++ 11起，局部静态变量，会被编译器自动加锁，只会被初始化一次，

class Singleton {
private:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton& getInstance() {
        static Singleton instance;  // C++11 线程安全
        return instance;
    }

    void doSomething() {
        // ...
    }
};

c++ 11以下，要自己加锁
class Singleton {
private:
    static Singleton* instance;
    static std::mutex mtx;
    Singleton() {}
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lock(mtx);
            if (instance == nullptr) { // double-checked locking
                instance = new Singleton();
            }
        }
        return instance;
    }
};

3. 具体操作上，构造函数要私有，并且要明确告诉编译器，禁止拷贝构造和拷贝赋值操作，移动构造和移动赋值操作。

