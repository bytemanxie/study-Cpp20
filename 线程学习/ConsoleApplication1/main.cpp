#include <iostream>
#include <thread>

void counter(int id, int numIerateions)
{
	for (int i{ 0 }; i < numIerateions; ++i)
	{
		std::cout << "Counter" << id << "has value" << i << std::endl;
	}
}

void test1()
{
	std::thread t1 {counter, 1, 6};
	std::thread t2 {counter, 2, 6};
	t1.join();
	t2.join();
}

class Counter
{
public:
	Counter(int id, int numIerateions)
		: m_id(id), m_numIterations(numIerateions) {};
	
	void operator()() const
	{
		for (int i{ 0 }; i < m_numIterations; ++i)
		{
			std::cout << "Counter" << m_id << "has_value" << i << std::endl;
		}
	}

private:
	int m_id;
	int m_numIterations;
};

void test2()
{
	std::thread t1{Counter{1, 20}};
	Counter c{ 2, 12 };
	std::thread t2{c};
	t1.join();
	t2.join();
}

void test3()
{
	int id{ 1 }, numIerateions{ 5 };
	std::thread t1{[id, numIerateions]() {
		for (int i{ 0 }; i < numIerateions; ++i)
		{
			std::cout << "Counter" << id << "has_value" << i << std::endl;
		}
	} };
	t1.join();
}

class Request
{
public:
	Request(int id) : m_id(id) { }
	void process()
	{
		std::cout << "Processing request " << m_id << std::endl;
	}
private:
	int m_id;
};

void test4()
{
	Request req{ 100 };
	std::thread t {&Request::process, & req};
	t.join();
}

int k;


void threadFuction(int id)
{
	thread_local int n;
	printf("thread %d n = %d k = %d\n", id, n, k);
	
	++n;
	++k;
}
void test5()
{
	std::thread t1{threadFuction, 1}; t1.join();
	std::thread t2{threadFuction, 2}; t2.join();
}

int main()
{
	//test1();//通过函数指针创建线程
	//test2();//通过函数对象创建线程
	//test3();//通过lambda表达式创建线程
	//test4();//通过成员函数创建线程
	test5();
}