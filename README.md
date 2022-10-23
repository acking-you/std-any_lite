# std-any_lite
## How to use?
This library support single_include,so you need only include `"any.hpp"`.

This is a simple example:
```cpp
#include<iostream>
#include"any.hpp"

struct Student{
	Student(int id,const char* name):id_(id),name_(name){}
	int id_;
	const char* name_;
};

int main(){
	nonstd::any t = "hello world";
	t = 324; //changed to int
	t = 3.4353; //changed to double
	t = Student{32,"bob"}; //changed to custom type
	t.emplace<Student>(32,"bob"); //the same to previous,but it can avoid copy

	auto name =t.type().name(); //get typename from std::typeinfo method
	t.has_value(); //to judge value exist
	auto v = nonstd::any_cast<Student>(t); //get value from any
	std::cout<<"typename:"<<name<<" Student name:" <<v.name_;
}
```