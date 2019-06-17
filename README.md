# 闭门造轮子

## Singleton 01

```
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
