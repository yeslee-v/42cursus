#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
template <typename T, class Container = ft::vector<T> >
class stack
{
public:
	typedef typename Container::value_type value_type;
	typedef typename Container::size_type size_type;
	typedef Container container_type;

public:
	//	member function
	explicit stack(const container_type &ctnr = container_type()) : c(ctnr){};
	bool empty() const { return c.empty(); };
	size_type size() const { return c.size(); };
	value_type &top() { return c.back(); };
	const value_type &top() const { return c.back(); };
	void push(const value_type &val) { return c.push_back(val); };
	void pop() { return c.pop_back(); };

protected:
	Container c;

private:
	template <typename U, class Cont>
	friend bool operator==(const stack<U, Cont> &lhs, const stack<U, Cont> &rhs);
	
	template <typename U, class Cont>
	friend bool operator<(const stack<U, Cont> &lhs, const stack<U, Cont> &rhs);

	template <typename U, class Cont>
	friend bool operator>(const stack<U, Cont> &lhs, const stack<U, Cont> &rhs);

};

// non-member function overloads
// non-member function에서 friend를 이용해 protected, private에 접근한다 

template <typename U, class Cont>
bool operator==(const stack<U, Cont> &lhs, const stack<U, Cont> &rhs) { return lhs.c == rhs.c; };

template <typename U, class Cont>
bool operator!=(const stack<U, Cont> &lhs, const stack<U, Cont> &rhs) { return !(lhs == rhs); };

template <typename U, class Cont>
bool operator<(const stack<U, Cont> &lhs, const stack<U, Cont> &rhs) { return lhs.c < rhs.c; };

template <typename U, class Cont>
bool operator<=(const stack<U, Cont> &lhs, const stack<U, Cont> &rhs) { return !(lhs > rhs); };

template <typename U, class Cont>
bool operator>(const stack<U, Cont> &lhs, const stack<U, Cont> &rhs) { return lhs.c > rhs.c; };

template <typename U, class Cont>
bool operator>=(const stack<U, Cont> &lhs, const stack<U, Cont> &rhs) { return !(lhs < rhs); };

} // namespace ft

#endif
