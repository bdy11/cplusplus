push_back 和emplace_back 区别主要是构造方式和性能。
Push_back需要一个已经构造好的对象，而emplace_back可以直接传构造参数。
push_back调用的是拷贝构造函数或移动构造函数，而emplace_back则是在容器内直接构造。
push_back比emplace_back要慢，因为多了一次额外的拷贝/移动。


假设我们有一个类:
class Person {
public:
    Person(std::string name, int age) {
        std::cout << "Constructed: " << name << ", " << age << "\n";
    }
};

使用push_back:
std::vector<Person> people;
people.push_back(Person("Alice", 30)); // 构造一个临时Person对象，然后移动/拷贝进去

使用emplace_back:
people.emplace_back("Bob", 25); // 直接在vector内部构造

总结:
如果已经有一个对象，使用puah_back();
如果想就地构造对象，使用emplace_back();
