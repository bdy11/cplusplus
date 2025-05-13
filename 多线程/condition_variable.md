什么是condition variable?
条件变量用来控制线程同步，让线程满足特定条件时才继续执行。通常和互斥锁搭配使用。

使用条件变量的重要函数
cv.wait(lock)             当前线程挂起，直到notify_one()或notify_all()被调用
cv.wait(lock, predicate)  和wait()类似，但是只有当predicate为真时，才会返回，防止虚假唤醒
cv.notify_one()           唤醒一个等待的线程
cv.notify_all()           唤醒所有等待的线程

关于predicate
任何可以返回 bool 的函数、函数对象或可调用对象都可以作为 predicate