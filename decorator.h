#pragma once


#include<functional>


template<typename T, typename ... Args>
class Decorator : public std::function<T(Args ... args)> {
protected:
	T(*target)(Args ...) = nullptr;
	T(*decoration)(T(*)(Args ...), Args ...) = nullptr;
public:
	Decorator(T(*target)(Args ...)) {
		this->Decorate(target);
	}

	Decorator& Decorate(T(*target)(Args ...)) {
		this->target = target;
		return *this;
	}

	Decorator& SetDecoration(T(*decoration)(T(*)(Args ...), Args ...)) {
		this->decoration = decoration;
		return *this;
	}

	T operator ()(Args ... args) {

		return decoration(target, args ...);
	}

};

#include<string>
#include<iostream>
namespace test {

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

}