#include <iostream>
#include <cstdlib>
#include <vector>

namespace OOP
{

    template <typename T>
    class Array
    {
    private:
    public:
        std::vector<T> data;
        unsigned length;

        Array(T x) : length(0) {
        }

        Array &insert(char x)
        {
            data.push_back(x);
            length++;
            return *this;
        }
        using value_type=T;
        Array &operator%(char x)
        {
            return insert(x);
        }
        unsigned operator~()
        {
            return length;
        }
        T &operator[](int x)
        {
            return data[x];
        }
    };
};

int main()
{
    typedef ::OOP::Array<int> type;
    type a(rand() % 100 + 10); // nie trzeba seedować żeby program się wykonał

    a.insert('#' - 1).insert('P') % type::value_type('O') % ('-') % ('E') % ('G') % ('Z') % ('1');

    ++a[0];
    for (unsigned i = 0; i != ~a; i++)
    {
        std::cout << static_cast<char>(a[i]) << (i + 1 != ~a ? '_' : '\n');
    }
}
// #_P_O_-_E_G_Z_1