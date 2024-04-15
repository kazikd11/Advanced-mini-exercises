#include <iostream>

// w całym kodzie można bezpośrednio wywoływać tylko dwie funkcje: printOn i operator <<
// wypisywanie może się odbywać tylko z wykorzystaniem __PRETTY_FUNCTION__ i "\n"
//  __PRETTY_FUNCTION__ zawiera pełną nazwę funkcji w danym miejscu

class B
{
public:
    virtual std::ostream &printOn(std::ostream &os) const = 0;
};

std::ostream &B::printOn(std::ostream &os) const
{
    std::cout << __PRETTY_FUNCTION__;
    os << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const B &ref)
{
    ref.printOn(os);
    return os;
}

class D1 : public B
{
public:
    virtual std::ostream &printOn(std::ostream &os) const
    {
        std::cout << __PRETTY_FUNCTION__;
        os << std::endl;
        return os;
    }
};

class D2 : public D1
{
};

class D3 : public D1
{
public:
    virtual std::ostream &printOn(std::ostream &os) const
    {
        std::cout << __PRETTY_FUNCTION__;
        os << std::endl;
        return os;
    }
};

class D4 : public D3
{
public:
    virtual std::ostream &printOn(std::ostream &os) const
    {
        B::printOn(os);
        D1::printOn(os);
        D3::printOn(os);
        os << __PRETTY_FUNCTION__<<std::endl;
        return os;
    }
};

int main(int argc, char *argv[])
{
    // B b; //odkomentowanie powoduje błąd kompilacji
    D1 d1;
    D2 d2;
    D3 d3;
    const D4 d4;
    std::cout << "d1: " << d1 << "d2: " << d2 << "d3: " << d3 << "d4: " << d4;
}

/* Output:
d1: virtual std::ostream& D1::printOn(std::ostream&) const
d2: virtual std::ostream& D1::printOn(std::ostream&) const
d3: virtual std::ostream& D3::printOn(std::ostream&) const
d4: virtual std::ostream& B::printOn(std::ostream&) const
virtual std::ostream& D1::printOn(std::ostream&) const
virtual std::ostream& D3::printOn(std::ostream&) const
virtual std::ostream& D4::printOn(std::ostream&) const
*/