// lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*#include <iostream>
using namespace std;

int main()
{
    int* x = new int();
    *x = 5;
    cout << x << " " << *x;
    cout << endl;
    int* y = new int();
    *x = *y; //dereferențiere
    cout << y<<" " << *y;
    cout << endl;
    int* z = new int(5);
    cout << z << " " << *z;
    cout << endl;
    int* v = new int[5];
    cout << v << " " << *v;
    cout << endl;
    cout <<*( v + 1);
    cout << endl;
    cout << 2[v];
    // v[2]=*(v+2)=*(2+v)=2[v];
}
*/
//Linked list-lista inlantuita
/*
Struct Nod{
Nod* prev;
int v;
Nod* next;

};

head=new Nod();-primul element apoi parcurgem
head.v=2;

*/

//1.adaugare la final-valoare
//2.inserare-un index
//3,4,5,6.stergere de la coada, de pe o pozitie, de la cap, o valoare
//7.afisare
//8.cautare-valoare

#include <iostream>
#include <fstream>
using namespace std;

struct Nod {
    Nod* next;
    int _v;
    Nod* prev;
};

struct Nod* _head = nullptr;

void insert_back(Nod** head,int v)
{

    Nod* new_nod = new Nod();

    Nod* last =*head;

    new_nod->_v = v;
    new_nod->next = nullptr;

    //daca lista e goala, facem noul nod ca head
    if (*head == nullptr) {
        new_nod->prev = nullptr;
        *head = new_nod;
        return;
    }

    //daca nu e goala mergem pana la final
    while (last->next != nullptr)
        last = last->next;

    last->next = new_nod;
    new_nod->prev = last;

    return;

}

void insert_after(Nod* prev_nod, int v)
{
    if (prev_nod == nullptr) {
        return;
    }

    Nod* new_nod = new Nod();

    new_nod->_v = v;

    new_nod->next = prev_nod->next;

    prev_nod->next = new_nod;

    new_nod->prev = prev_nod;

    if (new_nod->next != nullptr)
        new_nod->next->prev = new_nod;
}
void deleteNod(Nod *head,Nod *del)
{
    if (head == nullptr ||  del== nullptr)
        return;

    //nodul pe care stergem e head
    if (head == del)
    {
        head->prev = nullptr;
        head->next = del->next ->next;
        return;
    }

    //intra doar daca nodul del nu e cel final
    if (del->next != nullptr)
        del->next->prev = del->prev;

    //intra doar daca nodul del nu e head
    if (del->prev != nullptr)
        del->prev->next = del->next;

    //intra daca nodul del e final
    if (del->next = nullptr)
        del->prev->next = nullptr;
    
}
void delete_nod_value(Nod* head, int v)
{
    //daca lista e nula iesim
    if (head == nullptr)
        return;

    struct Nod* current = head;

    while (current->_v != v)
    {
        current = current->next;
    }

    deleteNod(head, current);

}
void delete_nod_pos(Nod* head, int p)
{

    //daca p e mai mic decat zero iesim
    if ( p <= 0)
        return;

    struct Nod* current = head;

    //mergem pana pozitia p
    for (int i =1; current != nullptr && i <p; i++)
        current = current->next;

  //daca n e mai mare decat nr de noduri din lista iesim
    if (current == nullptr)
        return;

    //stergem nodul de la pozitia p
    deleteNod(head, current);
}

void display(struct Nod* nod) 
{
    struct Nod* current;

    while (nod != nullptr)
    {
        cout << nod->_v<< " ";
        current=nod;
        nod = nod->next;
    }
    if (nod == nullptr)
        cout << "End";
}

bool search_element(Nod* head,int value)
{
    struct Nod* current = head;


    while (current->_v != value)
    {
        current = current->next;
    }
    if (current->next == nullptr && current->_v != value)
        return false;

    return true;

}

int main()
{
    Nod* head = nullptr;
    ifstream f("TextFile1.txt");
    int n;
    f >>n;
    int x;
    for (int i=0; i < n; i++)
    {
        f >>x;
        insert_back(&head, x);
    }
    f >> x;
    insert_after(head, x);
    display(head);
    cout << endl;
    f >> x;
    delete_nod_pos(head,x);
    f >> x;
    delete_nod_value(head, x);
    delete_nod_pos(head,1);
    display(head);
    cout << endl;
    f >> x;
    bool i=search_element(head,x);
    cout << i;


    return 0;

}