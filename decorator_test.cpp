#include "decorator.h"
#include<chrono>
#include<iostream>


int test_routine(int(*test_target)(int, int), int a, int b) {
	auto start = std::chrono::high_resolution_clock::now();
	auto result = test_target(a, b);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = end - start;
	std::cout << duration.count() << "ns" << std::endl;
	return result;
}

int DECOFUNC(test_target)(int a, int b) {
	return a + b;
}


DECORATE(test_target, test_routine)