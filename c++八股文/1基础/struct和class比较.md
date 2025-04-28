c++中,struct 和class本质非常相似，都可以用来定义一个自定义数据类型。
struct在c++中已经不仅仅是C语言里的简单数据结构了，它可以像class一样很强大。

二者都支持:
成员函数和变量
构造/析构函数
继承（多重继承）
多态
模板特性

区别:
习惯用途：struct用于结构体，class用于面向对象编程
内部成员访问: struct默认为public，class内部成员的访问默认为private.
继承的时候:   struct默认为public， class默认private.
