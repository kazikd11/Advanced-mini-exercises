#include<iostream>
#include<deque>
#include <vector>
#include <string>

template<typename T = int, template<typename U = T, typename Allocator = std::allocator<U>> class StorageType = std::deque>
class fifo{
    public:
    StorageType<> vec;
    void push(T x){
        vec.push_back(x);
    }
    std::string get(){
        T temp = vec[0];
        vec.pop_front();
        return std::to_string(temp)+"\n";
    }

    std::string size(){
        return std::to_string(vec.size())+"\n";
    }

    fifo(){
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
    using storage_type = StorageType<>;

    typename storage_type::const_iterator begin(){
        return vec.begin();
    }

    typename storage_type::const_iterator end(){
        return vec.end();
    }
};

int main(){
    fifo<> ft;
    for(int i: {0,1,2,3,4})
        ft.push(i);

    fifo<int, std::deque> f = ft;

    std::cout << f.get();
    std::cout << f.size();

    for(fifo<>::storage_type::const_iterator i = f.begin(); i != f.end(); ++i)
        std::cout << *i << ",";
}
/*
  Wynik:
  fifo<T, StorageType>::fifo() [with T = int, StorageType = std::deque]
  0
  4
  1,2,3,4,
*/