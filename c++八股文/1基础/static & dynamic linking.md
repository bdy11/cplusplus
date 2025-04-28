static linking & dynamic linking
静态链接: 程序运行时不依赖外部库，库的代码直接编译进可执行程序
动态链接: 程序运行时依赖外部库，库文件不包含在可执行文件内，而是运行时加载。

扩展:
动态链接的实现方式

静态库(static library)，编译时就被打包进程序，生成的可执行文件包含库的代码。后缀.a(linux) .lib(windows)

动态库(Dynamic library), 程序运行时才加载库文件，不嵌入代码，只保留引用。 后缀.so(linux), .dll(windows)

