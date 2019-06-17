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

int dec_decoration(int(*pfunc)(int, float), int a, float b) {
    std::cout << "decoration_begin" << std::endl;
    auto result = pfunc(a, b) * 10;
    std::cout << "decoration_end" << std::endl;
    return result;
}

void dec_testrun() {
    Decorator<int, int, float> d(dec_target);
    d.SetDecoration(dec_decoration);
    std::cout << d(10, 5.5) << std::endl;
}

```


```cpp
#include "decorator.h"

typedef Decorator<int, std::string, std::string> response;

int controller_a(std::string, std::string) {
	return 200;
}

int controller_b(std::string, std::string) {
	return 404;
}

int do_response(		
	int (*controller)(std::string, std::string), 
	std::string request_method, 
	std::string request_data) {	
		
	int status = controller(request_method, request_method);
	if (status != 200) {
		std::cout << "SEND ERROR PAGE" << std::endl;
	}
	else {
		std::cout << "200 OK" << std::endl;
	}
	return status;
}
class Router {
	std::map<std::string, response*> route;
	response* empty_response;
public:
	void init() {
		route[std::string("/index")] = &((new response(controller_a))->SetDecoration(do_response));
		empty_response = &((new response(controller_b))->SetDecoration(do_response));
	}

	void do_route(std::string url, std::string method, std::string request_data) {
		auto response = route[url];
		if (!response) {
			response = empty_response;
		}
		(*response)(method, request_data);
	}
};

```
