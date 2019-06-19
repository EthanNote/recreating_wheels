#pragma once

template<typename T, typename ... Args>
class Decorator {
protected:
	T(*target)(Args ...) = nullptr;
	T(*decoration)(T(*)(Args ...), Args ...) = nullptr;
public:
	Decorator(T(*target)(Args ...)) {
		this->Decorate(target);
	}

	Decorator(T(*target)(Args ...), T(*decoration)(T(*)(Args ...), Args ...)) {
		this->Decorate(target);
		this->SetDecoration(decoration);
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

#define DECOFUNC(func_name) __decofunc__##func_name
#define DECORATE(func_name, decorator) auto func_name = Decorator(DECOFUNC(func_name), decorator);
