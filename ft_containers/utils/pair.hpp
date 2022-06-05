#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
template <class T1, class T2>
class pair
{
public:
    // member types
    typedef T1 first_type;
    typedef T2 second_type;

    // member variables
    first_type first; // key
    second_type second; // value

    // constructor
    pair() : first(first_type()), second(second_type()) {};
    template <class U, class V>
    pair(const ft::pair<U, V> &pr) : first(pr.first), second(pr.second) {};
    pair(const first_type &a, const second_type &b): first(a), second(b) {};

    pair& operator= (const pair& pr) { this->first = pr.first; this->second = pr.second; return *this; };

    // relational operators
    template <class T1, class T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
    }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return rhs < lhs;
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(lhs < rhs);
    }
};

} // namespace ft

#endif