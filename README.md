# 闭门造轮子

### Singleton 01


```cpp
#include "singleton1.h"

class ExampleClass{
    ...
    ExampleClass();
    ExampleClass(int a, int b);
    ...
};

void get_singleton_a(){
    auto a = SINGLETON_INSTANCE(ExampleClass);
}

void get_singleton_b(){
    auto b = SINGLETON_INSTANCE(ExampleClass, 2019, 6);
}
```

### Decorator 01
```cpp
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

int main() {
	std::cout << test_target(100, 200) << std::endl;
	return 0;
}
```
