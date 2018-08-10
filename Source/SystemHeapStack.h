#pragma once
#pragma warning(disable : 4544)
#include <stack>
#include <functional>
#include <optional>

template <class Data>
class SystemHeapStack {
public:
	using RecursiveFunction = std::function<std::optional<Data>(Data&)>;
	template <
		class Func,
		class = std::enable_if_t<std::is_constructible_v<RecursiveFunction, Func> >
	>
		SystemHeapStack(Func && recursiveFunction);

	template <
		class Data2, 
		class = std::enable_if_t<std::is_constructible_v<Data, Data2> >
	>
	void call(Data2 && data);

private:
	std::stack<Data> stack;
	RecursiveFunction func;
};

template<class Data>
template<
	class Func,
	class = std::enable_if_t<std::is_constructible_v<typename SystemHeapStack::RecursiveFunction, Func> >
>
inline SystemHeapStack<Data>::SystemHeapStack(Func && recursiveFunction)
	: func(std::forward<Func>(recursiveFunction))
{}

template<class Data>
template <
	class Data2,
	class = std::enable_if_t<std::is_constructible_v<Data, Data2> >
>
inline void SystemHeapStack<Data>::call(Data2 && data) {
	stack.push(std::forward<Data2>(data));

	while (!stack.empty()) {
		auto recursiveCall = func(stack.top());
		if (recursiveCall.has_value())
			stack.push(std::move(recursiveCall.value()));
		else
			stack.pop();
	}
}
