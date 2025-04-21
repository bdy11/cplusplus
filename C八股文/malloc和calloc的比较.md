malloc和calloc都是c/c++中动态分配内存的标准函数
都定义在<stdlib.h>中

函数原型
void *malloc(size_t size);              // 总字节数
void *calloc(size_t num, size_t size);  // 元素个数*每个元素的字节数

二者主要区别在于:
malloc不会初始化，内存内容为不确定的垃圾值
calloc会自动初始化全为0

calloc速度会稍慢，因为会对内存进行清零
使用malloc需要注意自己对内存进行初始化


malloc代码示例:

int *arr = (int*)malloc(5* sizeof(int));
if(arr == NULL){
  // 分配失败
}
//此时arr中的值是不确定的，可能是随机垃圾值


calloc代码示例:

int *arr = (int*)calloc(5, sizeof(int));
if(arr == NULL){
  //分配失败
}
//此时arr中的值全部为0