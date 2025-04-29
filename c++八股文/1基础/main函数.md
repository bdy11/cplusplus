main()函数相关问题

1. int main() 和int main(int argc, char* argv[])的区别

前者不接收命令行参数，后者接收命令行参数
argc: argument count，参数个数至少为1
argv: argument vector，参数数组，argv[0]是程序路径

面试表达：后者支持命令行参数，是通用格式，用于传递配置，路径，开关等

2. int main() 可以没有return 0 吗？
可以
c++标准允许省略return 0， 会自动返回0，表示正常退出。

3. void main()可以用吗

不可以
标准c++要求main()必须返回int，用于向操作系统返回退出码

4. char* argv[]和char** argv有区别吗？
没有。都是指向字符指针的指针，表示一个字符串数组。

总结一句话：
“main() 是程序入口，返回值告诉操作系统程序的退出状态。标准规定它必须返回 int，省略 return 0; 是合法的，参数格式常用于处理命令行。”