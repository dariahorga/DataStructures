//implementation of a stack using linked lists
#include <iostream>
#include <string>
#include "stack.h"
#include "queue.h"
using namespace std;


int main()
{
    stack* s = nullptr;
    s-> push(s, 11);
    s->push(s, 12);
    s->push(s, 13);
    s->show(s);
    cout << endl;
    cout<< s->pop(s) << " was removed from the stack";
    cout << endl;
    cout << "The peek is: " << s->peek(s);
    cout << endl;
    while (s->empty(s)==false)
    {
        s->show(s);
        cout<< endl;
        cout << s->pop(s) << " was removed from the stack";
        cout << endl;
    }

    cout << endl << endl;
    queue* q = nullptr;
    q->enqueue(q, 11);
    q->enqueue(q, 12);
    q->enqueue(q, 13);
    q->show(q);
    cout << endl;
    cout << q->dequeue(q) << " was removed from the queue";
    cout << endl;
    cout << "The peek is: " << q->peek(q);
    cout << endl;
    while (q->empty(q) == false)
    {
        q->show(q);
        cout << endl;
        cout << q->dequeue(q) << " was removed from the queue";
        cout << endl;
    }
   
    cout << endl << endl;

    stack* p=nullptr;
    string x = "(((()()())))()))";
    for (int i = 0; i <= x.size(); i++)
    {
        if (x[i]=='(')
            p->push(p, 1);
        if (x[i] == ')' && p->empty(p) == false)
            p->pop(p);  
        if(p->empty(p)==true)

    }
    if (p->empty(p) == true)
        cout << "The queue is empty, so the parantesis are not correctly closed";
}

