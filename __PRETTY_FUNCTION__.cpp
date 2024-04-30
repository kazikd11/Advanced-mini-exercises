#include <iostream>

using namespace std;

class A{  
    public:
        int x,y;
        A(int _x,int _y):x(_x),y(_y){
            cout<<__PRETTY_FUNCTION__<<" _a="<<x<<",_b="<<y<<endl;
        }
        explicit A(int _x){
            A s(_x,0);
            cout<<__PRETTY_FUNCTION__<<" _a="<<s.x<<",_b="<<s.y<<endl;
        }
        A(){
            A s(0,0);
            cout<<__PRETTY_FUNCTION__<<" _a="<<s.x<<",_b="<<s.y<<endl;
        }

        A(A&& ref){
           cout<<__PRETTY_FUNCTION__<<" _a="<<ref.x<<",_b="<<ref.y<<endl; 
        }

};



int main()
{
    cout << "a->"; A a;
    cout << "b->"; A b(1);
    cout << "c->"; A c(1,2);

    cout << "d->"; A d = std::move(c);

    //A e = c;
    //A f = 1;
}
/*
a-> A::A(int,int): _a=0,_b=0
A::A(): _a=0,_b=0
b-> A::A(int,int): _a=1,_b=0
A::A(int): _a=1,_b=0
c-> A::A(int,int): _a=1,_b=2
d-> A::[...]: _a=1,_b=2
*/