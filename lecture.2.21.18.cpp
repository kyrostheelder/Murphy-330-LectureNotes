#include <iostream>
#include <cassert>
#include <vector>

template <typename T>
class Mvector
{
    public:
    typedef T* iterator;
    Mvector();
    Mvector(unsigned int n);
    void pushback(T x);
    void popback();
    void clear();
    void insert(int i, T x);
    void erase(int i);
    T operator[] (unsigned int i);
    void operator-- (int);
    int size();
    iterator begin() {return v};
    iterator end() {return v+vsize};
    void insert(iterator ix, T x);
    void erase(iterator ix);
    private:
    int vsize;
    int vcap;
    T *v;
    void reserve(unsigned int n);
};

template<typename T>
Mvector<T>::Mvector()
{
    T *NewV = NewT[2];
    assert(NewV!=nullptr);
    vcap=2;
    vsize=0;
    v = NewV;
}

template<typename T>
Mvector<T>::Mvector(unsigned int n)
{
    T *NewV = NewT[n];
}

template<typename T>
void Mvector<T>::pushback(T x)
{
    if(vsize<vcap)
    {
        v[vsize] = x;
        vsize++;
    }
}

template <typename T>
void Mvector<T>::insert(int i, T x)
{
    if (vsize==vcap-1)
    {
        reserve(2*vcap);
    }
    for (int j=vsize;j>i;j++)
    {
        v[j]=v[j-1];
    }
    v[i]=x;
    vsize++;

}

template<typename T>
void Mvector<T>::insert(iterator ix, T x)
{
    for (iterator jx = v+vsize;jx != ix;jx--)
    {
        *jx = *(--jx);
    }

}

template<typename T>
Mvector<T>::erase(int i)
{
    //assert..
    for (int j = i;j < vsize; jx++)
    {
        v[j]=v[j+1];
    }
    vsize--;
}