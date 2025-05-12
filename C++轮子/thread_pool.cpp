#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <thread>
#include <string>
#include <queue>
#include <vector>
#include <condition_variable>

using namespace std;

template <typename T>
class MutexSafe
{
private:
  T *data;
  mutex _m;

public:
  MutexSafe(T *data) : data(data) {}
  ~MutexSafe()
  {
    delete data;
  }

  void lock()
  {
    _m.lock();
  }

  void unlock()
  {
    _m.unlock();
  }

  bool try_lock()
  {
    return _m.try_lock();
  }

  mutex &get_mutex()
  {
    return _m;
  }

  T &Acquire(unique_lock<MutexSaft<T>> &lock)  // unique_lock的类型可以是一个template class
  {
    if(lock.mutex() != &_m)
    {
      throw "wrong lock object passed to MutexSafe::aquire";
    }
    return *data;
  }

  T &Acquire(unique_lock<mutex> &lock)
  {
    if(lock.mutex() != &_m)
    {
      throw "wrong lock object passed to MutexSafe::aquire";
    }
    return *data;
  }
};

template <typename MsgType>
class MsgQueue
{
private:
  std::queue<MsgType> _queue;
  mutex _m;
  condition_variable _enq_cv;
  condition_variable _deq_cv;
  int _limit;

public:
  MsgQueue(int limit = 100) : _limit(limit) {}
  ~MsgQueue() {}

  void Enqueue(MsgType &msg)
  {
    unique_lock<mutex> lock(_m);
    if (_queue.size() >= _limit)
    {
      cout << "Queue is full, waiting for dequeue" << endl;
      _enq_cv.wait(lock, [this]()
                   { return _queue.size() < _limit; });
    }
    _queue.push(msg);
    _deq_cv.notify_one();
  }

  MsgType Dequeue()
  {
    unique_lock<mutex> lock(_m);
    if(_queue.empty())
    {
      cout << "Queue is empty, waiting for enqueue" << endl;
      _deq_cv.wait(lock, [this]()
                   { return !_queue.empty(); });
    }

    MsgType msg = _queue.front();
    _queue.pop();
    _enq_cv.notify_one();
    return msg;
  }

  int Size()
  {
    unique_lock<mutex> lock(_m);
    return _queue.size();
  }
};

struct CustomerTask
{
  std::string task;
  float money;
  CustomerTask() {}
  CustomerTask(const CustomerTask &task) : task(task.task), money(task.money) {}
  void ExecutedTask()
  {
    if (money > 0)
    {
      std::cout << "task:" << task << " is executed at $" << money << std::endl;
    }
    else
    {
      std::cout << "Bank closed because the price is $" << money << std::endl;
    }
  }
};

typedef MsgQueue<CustomerTask> TaskQueueType;
typedef MutexSafe<TaskQueueType> TaskQueueSafe;

template <typename TaskQueueType>
class ThreadPool
{
private:
  int _numThreads;
  TaskQueueType &_taskQueue;
  std::vector<std::thread *> _workerThreads;
  bool _threadPoolStop = false;

public:
  ThreadPool(TaskQueueType &taskQueue, int numThreads) : _taskQueue(taskQueue), _numThreads(numThreads)
  {
    for (int i = 0; i < numThreads; i++)
    {
      std::thread *t = new std::thread(&ThreadPool::ExecuteTask, this);
      _workerThreads.push_back(t);
    }
  }

  ~ThreadPool()
  {
    for (auto threadObj : _workerThreads)
    {
      if (threadObj->joinable())
      {
        threadObj->join();
        delete threadObj;
      }
    }
  }
    void ExecuteTask()
    {
        while(1)
        {
            CustomerTask task=_taskQueue.Dequeue();
            task.ExecuteTask();
            if(task.money<0)
            {
                _threadPoolStop=true;
                _taskQueue.Enqueue(task);//tell other threads to stop
            }
            if(_threadPoolStop)
            {
                cout<< "thread finshed!"<<endl;
                return;
            }
            //the sleep function simulates that the task takes a while to finish
            std::this_thread::sleep_for(std::chrono::milliseconds(rand()%100));
        }
    }
};

void TestLeaderFollower()
{
  TaskQueueType taskQueue(5);
  ThreadPool<TaskQueueType> pool(taskQueue, 10);

  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  for (int i = 0; i < 10; i++)
  {
    CustomerTask task;
    task.money = i + 1;
    if (task.money > 5)
    {
      task.task = "deposit $";
    }
    else
    {
      task.task = "withdraw $";
    }
    taskQueue.Enqueue(task);
  }

  CustomerTask bankCloseTask;
  bankCloseTask.task = "bank close";
  bankCloseTask.money = 1;
  taskQueue.Enqueue(bankCloseTask);
}

int main()
{
  TestLeaderFollower();
  return 0;
}