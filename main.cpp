#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <chrono>

std::mutex mtxObj;

void Rectangle(char ch)
{
	std::lock_guard<std::mutex> lock(mtxObj);

	for (size_t i = 0; i < 6; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			std::cout << ch;
		}
		std::cout << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	std::cout << std::endl;
}

int main()
{
	std::thread th1(Rectangle, '8');
	std::thread th2(Rectangle, '*');

	for (int i = 0; i < 10; i++)
	{
		std::cout << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}

	th1.join();
	th2.join();
}