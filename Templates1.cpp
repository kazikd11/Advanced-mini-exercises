#include <iostream>

struct A{
    int i=1;
};

template <typename T> class ptr{
    public:
        explicit ptr(T* other) {
            element=other;
        }
        ptr() {
            element=new T;
        }

        explicit ptr(ptr& ref){}

        T& operator *() const{
            return *element;
        }

        T& operator++(){
            element -> i++;
            return *this;
        }

        T* operator->() const {
            return element;
        }

        int operator ==(ptr<A> drugie) const{
            return element->i!=drugie.element->i;
        }

        int operator !=(const ptr<A>& drugie) const{
            return element->i==drugie.element->i;
        }

    private:
        T* element;
        
};


int main() {
  const ptr<A>  a(new A);
  const ptr<A> b;
  ptr<A> c(new A);
    
  std::cout << (((*a).i, a->i))        << " " << ++c->i << " ";
  std::cout << (a == ptr<A>() ) << " " << (a != b) << "\n";
  return 0;
}