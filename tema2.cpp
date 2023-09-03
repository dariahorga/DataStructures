/*
//1-arbori binari
#include <iostream>
using namespace std;

//arbore binar
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

//functie care creeaza un nou nod in arbore
Node* newNode(int v)
{
    Node* current = new Node;
    current->value = v;
    current->left = current->right = nullptr;
    return current;
}

void print(Node* root, int level, int K)
{
    if (root == nullptr) {
        return;
    }
    //functie recursiva care trece prin partea stanga a arborelui
    print(root->left, level + 1, K);
    //functie recursiva care trece prin partea dreapta a arborelui
    print(root->right, level + 1, K);

    if (K == level) {
        cout << root->value << " ";
    }
}
int main()
{
    Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(6);
    root->left->left = newNode(11);
    int K = 2;

    print(root, 1, K);
    return 0;
}
*/
/*
//2-liste&cozi
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;
};

class Deque {
private:
    Node* stanga; 
    Node* dreapta; 

public:
    Deque() : stanga(nullptr), dreapta(nullptr) {}

    bool isEmpty() {
        return (stanga == nullptr && dreapta == nullptr);
    }

    void insertFront(int val) {
        Node* newNode = new Node;
        newNode->value = val;
        newNode->prev = nullptr;
        newNode->next = stanga;

        if (isEmpty()) {
            stanga = dreapta = newNode;
        }
        else {
            stanga->prev = newNode;
            stanga = newNode;
        }
    }

    void insertRear(int val) {
        Node* newNode = new Node;
        newNode->value = val;
        newNode->prev = dreapta;
        newNode->next = nullptr;

        if (isEmpty()) {
            stanga = dreapta = newNode;
        }
        else {
            dreapta->next = newNode;
            dreapta = newNode;
        }
    }

    int deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the front." << endl;
            return -1;
        }

        Node* temp = stanga;
        int val = temp->value;

        if (stanga == dreapta) {
            stanga = dreapta = nullptr;
        }
        else {
            stanga = stanga->next;
            stanga->prev = nullptr;
        }

        delete temp;
        return val;
    }

    int deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the rear." << endl;
            return -1;
        }

        Node* temp = dreapta;
        int val = temp->value;

        if (stanga == dreapta) {
            stanga = dreapta = nullptr;
        }
        else {
            dreapta = dreapta->prev;
            dreapta->next = nullptr;
        }

        delete temp;
        return val;
    }
};

int main() {
    Deque deque;

    deque.insertFront(10);
    deque.insertRear(20);
    deque.insertFront(5);

    cout << deque.deleteFront() << endl; 
    cout << deque.deleteRear() << endl; 

    deque.insertRear(15);
    deque.insertFront(2);

    cout << deque.deleteFront() << endl; 
    cout << deque.deleteRear() << endl;

    return 0;
}
*/
/*
//3- priority queue

#include <iostream>
#include <vector>
using namespace std;

struct Element {
    int value;
    int priority;
};

class PriorityQueue {
private:
    vector<Element> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return 2 * i + 1;
    }

    int rightChild(int i) {
        return 2 * i + 2;
    }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)].priority > heap[i].priority) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int minIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left].priority < heap[minIndex].priority) {
            minIndex = left;
        }

        if (right < heap.size() && heap[right].priority < heap[minIndex].priority) {
            minIndex = right;
        }

        if (minIndex != i) {
            swap(heap[i], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }

public:
    PriorityQueue() {}

    bool isEmpty() {
        return heap.empty();
    }

    void enqueue(int value, int priority) {
        Element elem;
        elem.value = value;
        elem.priority = priority;
        heap.push_back(elem);
        heapifyUp(heap.size() - 1);
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Priority queue is empty." << endl;
            return -1;
        }

        int minValue = heap[0].value;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return minValue;
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue(10, 5);
    pq.enqueue(20, 2);
    pq.enqueue(30, 8);
    pq.enqueue(40, 3);

    cout << pq.dequeue() << endl; 
    cout << pq.dequeue() << endl; 
    cout << pq.dequeue() << endl;
    cout << pq.dequeue() << endl; 

    return 0;
}
*/
//5- cozi
#include <iostream>
using namespace std;

class queue
{
    int value;
    queue* next;

public:
    void enqueue(queue*& top, int newvalue)
    {
        queue* newNode = new queue();
        newNode->value = newvalue;
        newNode->next = nullptr;

        if (top == nullptr)
            top = newNode;
        else
        {
            queue* temp = top;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    int dequeue(queue*& top)
    {
        if (top == nullptr)
            return -1;
        queue* temp = top;
        int value = temp->value;
        top = top->next;
        delete temp;
        return value;
    }

    int peek(queue* top)
    {
        if (top == nullptr)
            return -1;
        return top->value;
    }

    bool empty(queue* top)
    {
        return top == nullptr;
    }

    void show(queue* top)
    {
        queue* temp = top;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void labelComponents(int** image, int m)
{
    queue* q = nullptr;

    int** labels = new int* [m];
    for (int i = 0; i < m; i++)
    {
        labels[i] = new int[m];
        for (int j = 0; j < m; j++)
            labels[i][j] = 0; 
    }

    int currentLabel = 1; 
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
         
            if (image[i][j] == 1 && labels[i][j] == 0)
            {
                q->enqueue(q, i * m + j);

                labels[i][j] = currentLabel;

                while (!q->empty(q))
                {
                    int front = q->dequeue(q);
                    int x = front / m;
                    int y = front % m;

                    if (x > 0 && image[x - 1][y] == 1 && labels[x - 1][y] == 0)
                    {
                        q->enqueue(q, (x - 1) * m + y);
                        labels[x - 1][y] = currentLabel;
                    }
                    if (y < m - 1 && image[x][y + 1] == 1 && labels[x][y + 1] == 0)
                    {
                        q->enqueue(q, x * m + y + 1);
                        labels[x][y + 1] = currentLabel;
                    }
                    if (x < m - 1 && image[x + 1][y] == 1 && labels[x + 1][y] == 0)
                    {
                        q->enqueue(q, (x + 1) * m + y);
                        labels[x + 1][y] = currentLabel;
                    }
                    if (y > 0 && image[x][y - 1] == 1 && labels[x][y - 1] == 0)
                    {
                        q->enqueue(q, x * m + y - 1);
                        labels[x][y - 1] = currentLabel;
                    }
                }
                currentLabel++;
            }
        }
    }

    cout << "Labeled Components:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
            cout << labels[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < m; i++)
        delete[] labels[i];
    delete[] labels;
}

int main()
{
    int m = 5;
    int** image = new int* [m];
    for (int i = 0; i < m; i++)
        image[i] = new int[m];

    image[0][0] = 1;
    image[0][1] = 0;
    image[0][2] = 1;
    image[0][3] = 0;
    image[0][4] = 1;
    image[1][0] = 1;
    image[1][1] = 1;
    image[1][2] = 0;
    image[1][3] = 1;
    image[1][4] = 0;
    image[2][0] = 0;
    image[2][1] = 0;
    image[2][2] = 0;
    image[2][3] = 1;
    image[2][4] = 0;
    image[3][0] = 1;
    image[3][1] = 0;
    image[3][2] = 1;
    image[3][3] = 0;
    image[3][4] = 1;
    image[4][0] = 1;
    image[4][1] = 1;
    image[4][2] = 1;
    image[4][3] = 1;
    image[4][4] = 0;

    labelComponents(image, m);
    for (int i = 0; i < m; i++)
        delete[] image[i];
    delete[] image;

    return 0;
}

   


                  




