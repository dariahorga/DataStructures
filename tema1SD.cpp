/*
// problema 1
#include <iostream>
using namespace std;

struct Node
{
	float value;
	Node *previous;
	Node *next;
};

struct Node* head = nullptr;

void insert_back( int value_)
{

    Node* new_node = new Node();
    Node* last = head;

    new_node->value = value_;
    new_node->next = nullptr;

    //daca lista e goala, facem noul nod ca head
    if (head == nullptr) {
        new_node->previous = nullptr;
        head = new_node;
        return;
    }

    //daca nu e goala mergem pana la final
    while (last->next != nullptr)
        last = last->next;
    last->next = new_node;
    new_node->previous = last;

}

void display(struct Node* node)
{
    struct Node* current;
    cout << "My list contains: ";
    while (node != nullptr)
    {
        cout << node->value << " ";
        current = node;
        node = node->next;
    }
}

void insert()
{
    Node* current_1 = head;
    Node* current_2 = head->next;
    while (current_1->next != nullptr)
    {
        int value_1 = current_1->value;
        int value_2 = current_2->value;
        float v = (value_1 + value_2) / 2.0;

        Node* new_node=new Node();
        current_1->next = new_node;
        new_node->value = v;
        new_node->previous = current_1;
        new_node->next = current_2;
        current_2->previous = new_node;

        current_1 = current_2;
        current_2 = current_2->next;

    }
}
int main()
{
    insert_back(1);
    insert_back(2);
    insert_back(3);
    insert_back(4);
    display(head);
    insert();
    cout << endl;
    display(head);

	return 0;
}
*/

/*
//problema2
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* previous;
    Node* next;
};

struct Node* head = nullptr;

void insert(int value_)
{
    Node* new_node = new Node();
    Node* current = head;

    new_node->value = value_;

    //daca lista e goala sau valoarea data este mai mica, facem noul nod ca head
    if (head == nullptr || head->value> value_)
    {
        new_node->previous = nullptr;
        new_node->next = head;
        if (head != nullptr)
            head->previous = new_node;
            
        head = new_node;
        return;
    }

    //daca nu e goala mergem pana la pozitia lui din lista sortata
    while (current->next != nullptr && current->next->value<value_)
        current = current->next;

    new_node->next = current->next;
    current->next = new_node;
    new_node->previous = current;

}

void display(struct Node* node)
{
    struct Node* current;
    cout << "My list contains: ";
    while (node != nullptr)
    {
        cout << node->value << " ";
        current = node;
        node = node->next;
    }
}

int main()
{

    insert(4);
    insert(2);
    insert(5);
    insert(4);
    insert(4);
    insert(1);
    display(head);

    return 0;
}

*/

/*
//problema 3
#include <iostream>
using namespace std;

struct Node
{
    float value;
    Node* previous;
    Node* next;
};

struct Node* head = nullptr;

void reverse(Node* &head)
{

    Node* current = head;
    Node* aux = nullptr;

    while (current != nullptr)
    {
        aux = current->previous;
        current->previous = current->next;
        current->next = aux;
        current = current->previous;
    }

    if (aux != nullptr)
        head = aux->previous;

}

void insert_back(int value_)
{

    Node* new_node = new Node();
    Node* last = head;

    new_node->value = value_;
    new_node->next = nullptr;

    //daca lista e goala, facem noul nod ca head
    if (head == nullptr) {
        new_node->previous = nullptr;
        head = new_node;
        return;
    }

    //daca nu e goala mergem pana la final
    while (last->next != nullptr)
        last = last->next;
    last->next = new_node;
    new_node->previous = last;


}

void display(struct Node* node)
{
    struct Node* current;
    cout << "My list contains: ";
    while (node != nullptr)
    {
        cout << node->value << " ";
        current = node;
        node = node->next;
    }

}
int main()
{
    insert_back(1);
    insert_back(2);
    insert_back(3);
    insert_back(4);
    display(head);
    reverse(head);
    cout << endl;
    display(head);

    return 0;
}
*/

//problema 5

#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* previous;
    Node* next;
};

//functie care initializeaza listele adaugand elemente la final
void insert_back(int value_, Node*& head)
{

    Node* new_node = new Node();
    Node* last = head;

    new_node->value = value_;
    new_node->next = nullptr;

    //daca lista e goala, facem noul nod ca head
    if (head == nullptr) {
        new_node->previous = nullptr;
        head = new_node;
        return;
    }

    //daca nu e goala mergem pana la final
    while (last->next != nullptr)
        last = last->next;
    last->next = new_node;
    new_node->previous = last;

}

//o functie care calculeaza lungimea fiecarei liste
int getSize(Node* node)
{
    int size = 0;
    while (node != nullptr) {
        node = node->next;
        size++;
    }
    return size;
}

// o functie recursiva care aduna valorile din fiecare lista, cu conditia ca acestea sa aiba accelasi size
Node* addLists_samesize(Node* head1, Node* head2, int& carry)
{
    if (head1 == nullptr)
        return nullptr;

    int v;
    Node* result = new Node();
    v = head1->value + head2->value + carry;
    carry = v / 10;
    v = v % 10;
    result->value = v;
    result->next = addLists_samesize(head1->next, head2->next, carry);

    return result;

}
Node* addToRemaining(Node* i, int& carry, Node*& result)
{
    if (i == nullptr)
    {
        if (carry != 0)
        {
            insert_back(carry, result);
            carry = 0;
        }
        return nullptr;
    }

    int v = i->value + carry;
    carry = v / 10;
    v %= 10;

    // Create a new node for the current value
    Node* current = new Node();
    current->value = v;
    current->next = nullptr;

    // Insert the new node at the end of the result list
    if (result == nullptr)
    {
        result = current;
    }
    else
    {
        Node* last = result;
        while (last->next != nullptr)
            last = last->next;
        last->next = current;
        current->previous = last;
    }

    // Recursively add the remaining nodes
    addToRemaining(i->next, carry, result);

    return result;
}


void addLists(Node* head1, Node* head2, Node*& result)
{
    int size1, size2;
    size1 = getSize(head1);
    size2 = getSize(head2);



    int carry = 0;
    if (size1 == size2)
        result = addLists_samesize(head1, head2, carry);
    else
    {
        int difference = abs(size1 - size2);

        //facem a doua lista mai mare decat prima
        if (size2 < size1)
        {
            Node* aux;
            aux = head1;
            head1 = head2;
            head2 = aux;

            int a;
            a = size1;
            size1 = size2;
            size2 = a;

        }
        Node* i;
        result = addLists_samesize(head1, head2, carry);
        int x = size2 - difference - 1;
        for (i = head2; x--; i = i->next);
        result = addToRemaining(i->next, carry, result);

    }
    if (carry != 0)
        insert_back(carry, result);

}

//functie care afiseaza listele
void display(Node* node)
{
    struct Node* current;
    cout << "My list contains: ";
    while (node != nullptr)
    {
        cout << node->value << " ";
        current = node;
        node = node->next;
    }

}
int main()
{
    struct Node* head1 = nullptr;
    struct Node* head2 = nullptr;
    struct Node* result = nullptr;

    insert_back(2, head1);
    insert_back(4, head1);
    insert_back(5, head1);
    display(head1);
    cout << endl;

    insert_back(4, head2);
    insert_back(3, head2);
    display(head2);
    cout << endl;

    addLists(head1, head2, result);
    display(result);


    return 0;
}
