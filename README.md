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

int dec_target(int a, float b) {
  std::cout << "decorated_target" << std::endl;
  return (int)(a*b);
}

int dec_decorator(int(*pfunc)(int, float), int a, float b) {
	std::cout << "decoration_begin" << std::endl;
	auto result = pfunc(a, b) * 10;
	std::cout << "decoration_end" << std::endl;
	return result;
}

void dec_testrun() {
	Decorator<int, int, float> d(dec_target);
	d.SetDecoration(dec_decorator);
	std::cout << d(10, 5.5) << std::endl;
}

```
