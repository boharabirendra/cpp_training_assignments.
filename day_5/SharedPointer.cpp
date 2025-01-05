#include <iostream>

template <typename _Tp>
class SharedPointer
{
public:
    SharedPointer(_Tp *ptr = nullptr) : res(ptr), counter(new int(1))
    {
        std::cout << "Constructor was called " << std::endl;
    }

    SharedPointer(const SharedPointer<_Tp> &ptr)
    {
        res = ptr.res;
        counter = ptr.counter;
        incrementCounter();
    }

private:
    _Tp *res;
    int *counter;

    void incrementCounter()
    {
        if (counter)
        {
            (*counter)++;
        }
    }

    void decrementCounter()
    {
        if (counter)
        {
            (*counter)--;
            if ((*counter) == 0)
            {
                delete res;
                delete counter;
                res = nullptr;
                counter = nullptr;
            }
        }
    }
};

int main()
{
    SharedPointer<int> sharePtr(new int(100));
    SharedPointer<int> dd;
    SharedPointer<int> sharePtr_1 = sharePtr;
    SharedPointer<int> sharePtr_2 = sharePtr;
    return 0;
}