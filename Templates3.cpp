#include <iostream>
template <typename T>
class B
{
public:
    T x;
    T get()
    {
        return x;
    }
    B(T x) : x(x) {}
    explicit B(const B &ref) { x = ref.x; }
    typedef int value_type;
};

template <typename T>
class B<T*>
{
public:
    T* x;
    T get()
    {
        return *x;
    }
    B(T *x) : x(x) {}
    B(const B<T*>&&ref)=delete;
    typedef int value_type;
};


int main()
{
    typedef B<int> int_b;
    typedef B<int *> int_p_b;

    int_b a(1);
    int_b a_copy(a);
    int_p_b b(new int_p_b::value_type{2});
    //int_p_b e = b; //error
    //b=b; //error

    std::cout << "a=" << a.get() << std::endl;
    std::cout << "a_copy=" << a_copy.get() + 1 << std::endl;
    std::cout << " b=" << b.get() + 1 << std::endl;
}
/*
a=1
a_copy=2
b=3
 */