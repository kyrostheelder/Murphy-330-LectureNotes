#include <iostream>

using namespace std;

template<typename T>
class Lnode
{
    public:
    T data;
    Lnode *lptr;
    Lnode *rptr;
};

template <typename T>
class Mlist
{
    public:
    Mlist():
    void add(T x); //adds to the end of the list
    void del(T x);
    void deletefront();
    T getfront();
    private:
    Lnode<T> *first;
    Lnode<T> *last;
    int lsize;
};

template<typename T>
Mlist<T>::Mlist()
{
    first=0;
    last=0;
    size=0;
}

template<typename T>
void Mlist<T>::add(T x)
{
    Lnode<T> *ptr = new Lnode<T>;
    ptr -> data=x;
    if (lsize==0)
    {
        ptr -> lptr=0;
        ptr -> rptr=0;
        first = ptr;
        last = ptr;
    }
    else
    {
        ptr -> lptr=last;
        ptr -> rptr=0;
        last -> rptr=ptr;
        last =ptr;
    }
    
}

template<typename T>
void Mlist<T>::deletefront()
{
    Lnode<T> *cur=first;
    first=first->rptr;
    delete cur;
    first->lptr=0;
}