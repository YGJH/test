#include <iostream>

using namespace std;




class stack{
private:

    int index = 0;
    int *pData;
    int size;


public:
    stack(int n)
    {
        try{
            pData = new int[n];
            size = n;
            index = 0;
        }
        catch(bad_alloc &e)
        {
            throw runtime_error("memory fail");
        }

    }
    ~stack()
    {
        delete[] pData;
    }

    void push(int data)
    {
        if(isFull())
        {
            throw runtime_error("stack is full !");
        }
        pData[index] = data;
        index++;
    }

    void pop()
    {
        if(isEmpty())
        {
            throw runtime_error("stack is empty");
        }
        index--;
    }
    int top()
    {
        if(isEmpty())
        {
            throw runtime_error("stack is empty");
        }
        return pData[index];

    }
    bool isEmpty()
    {
        return index == 0;
    }
    bool isFull()
    {
        return index == size-1;
    }

    void show()
    {
        cout<<"[Bottom]<-";
        for(int i=0;i<index;i++)
        {
            cout<<pData[i]<<"<-";

        }
        cout<<"[top]"<<endl;
    }

};




int main()
{
    stack s(3);
    s.push(1);
    s.show();
    s.push(2);
    s.show();
    s.push(3);
    s.show();
    s.push(4);
    s.show();
    cout<<s.top()<<endl;
    s.pop();
    s.show();
    s.push(5);
    s.show();
    cout<<s.top()<<endl;
    s.pop();
    s.show();
    cout<<s.top()<<endl;
    s.pop();
    s.show();
    cout<<s.top()<<endl;
    s.pop();
    s.show();

    return 0;



}
