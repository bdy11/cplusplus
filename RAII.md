RAII
全称是Resource aquisition is Initialization，中文资源获取即初始化。

核心思想是，把获取的资源绑定到对象的生命周期上，即绑定到初始化和析构上。

当对象在创建时获取资源，在销毁时释放资源。
