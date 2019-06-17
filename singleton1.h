#pragma once
#include<functional>


template<class T>
T* SingletonInstance(std::function<T*()> init_func = [] {return new T(); }) {
	static T* _instance = nullptr;
	if (!_instance) {
		if (init_func) {
			_instance = init_func();
		}
	}
	return _instance;
}

#define SINGLETON_INSTANCE(cls, ...) SingletonInstance<cls>([]{return new cls(__VA_ARGS__); });


