#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft {
	template <typename T, class Container = ft::stack<T>>
	class stack {
		public:
			typedef typename Container::value_type	value_type;
			typedef typename Container::size_type	size_type;
			typedef			 Container				container_type;
		protected:
			Container c;
		
		public:
			//	member function
			explicit stack (const container_type& ctnr = container_type());	
			bool empty() const { return c.empty(); };
			size_type size() const { return c.size(); };
			value_type& top() { return c.back(); };
			const value_type& top() const { return c.back(); };	
			void push (const value_type& val) { return c.push_back(); };
			void pop() { return c.pop_back(); };

			// non-member function overloads
			template <class T, class Container>
				bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			template <class T, class Container>
				bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			template <class T, class Container>
				bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			template <class T, class Container>
				bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			template <class T, class Container>
				bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			template <class T, class Container>
				bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	}


}	

#endif
