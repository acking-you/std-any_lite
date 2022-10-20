#include <iostream>
#include "simple_any.hpp"
using namespace nonstd;

struct Student : public copyable {
	Student() = default;
	Student(int id, std::string name)
		: id_(id), name_(std::move(name))
	{
	}
	int id_{};
	std::string name_;
};

void test_any()
{
	any t = "你好";
	auto test_construct = [&]() {
		info("{}", t.type().name());
		t = 345456;
		info("{}", t.type().name());
		t = Student();
		info("{}", t.type().name());
		t = any(Student());
		info("{}", t.type().name());
		t = std::move(any("hello我k$"));
	};

	auto test_cast = [&]() {
		info("{}", any_cast<const char*>(t));
		t = std::to_string(43324324);
		info("typename:{} value:{}", t.type().name(), t.cast<std::string>());
	};

	auto test_other = [&]() {
		t.emplace<Student>(323, std::string("fdfsafsda"));
		info("id:{} name:{}", t.cast<Student>().id_, t.cast<Student>().name_);
		t.reset();
		info("{}", t.type().name());
		any p = "再次测试看看";
		swap(t, p);
		info("p:{},t:{},t_value{}", p.type().name(), t.type().name(), t.cast<const char*>());
	};

	test_construct();
	test_cast();
	test_other();
}
int main()
{
	test_any();
}
