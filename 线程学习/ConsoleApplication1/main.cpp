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

int main()
{
	test1();//通过函数指针创建线程
}