// lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;

struct node {

	int value;
	struct node* left, * right;
};

struct node* newNode(int new_value)
{
    struct node* current=new node();
    current->value = new_value;
    current->left = current->right = nullptr;
    return current;
}

struct node* insert(struct node* node, int new_value)
{
    if (node == nullptr)
        return newNode(new_value);
    if (new_value < node->value)
        node->left = insert(node->left, new_value);
    else if (new_value > node->value)
        node->right = insert(node->right, new_value);
    return node;
}

void display_SRD(struct node* root) {
    if (root == nullptr) {
        return;
    }
    display_SRD(root->left);
    cout << root->value << " ";
    display_SRD(root->right);
}

void display_RDS(struct node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->value << " ";
    display_RDS(root->left);
    display_RDS(root->right);
}
void display_SDR(struct node* root) {
    if (root == nullptr) {
        return;
    }
    display_SDR(root->left);
    display_SDR(root->right);
    cout << root->value << " ";
}
struct node* minNode(struct node* node)
{
    struct node* current = node;
    while (current && current->left != nullptr)
        current = current->left;

    return current;
}
struct node* deleteNode(struct node* root, int value_)
{
    if (root == nullptr)
        return root;

    if (value_ < root->value)
        root->left = deleteNode(root->left, value_);
    else if (value_ > root->value)
        root->right = deleteNode(root->right, value_);
    else {
        if (root->left == nullptr and root->right == nullptr)
            return nullptr;
        else if (root->left == nullptr) {
            struct node* current = root->right;
            delete(root);
            return current;
        }
        else if (root->right == nullptr) {
            struct node* current = root->left;
            delete(root);
            return current;
        }
        struct node* current = minNode(root->right);
        root->value = current->value;
        root->right = deleteNode(root->right, current->value);
        delete(current);
    }
    return root;
}

bool find(struct node* root, int value_)
{
    if (root == nullptr)
        return false;
    if (root->value == value_)
        return true;
    if (root->value < value_)
        return find(root->right, value_);
    return find(root->left, value_);
}


int maxNode(struct node* node)
{
    struct node* current = node;
    while (current && current->right != nullptr)
        current=current->right;

    return current->value;
}
int main()
{
    struct node* root = nullptr;
    root = insert(root, 8);
    insert(root, 6);
    insert(root, 10);
    insert(root, 9);
    insert(root, 15);
    insert(root, 12);
    insert(root, 3);
    insert(root, 4);
    insert(root, 2);
    display_SRD(root);
    cout << endl;
    display_RDS(root);
    cout << endl;
    display_SDR(root);
    cout << endl;
    root = deleteNode(root, 10);
    display_SRD(root);
    cout << endl;
    cout << "Maximum node of the tree: ";
    cout << maxNode(root);
    cout << endl;
    cout << "Minimum node of the tree: ";
    cout << minNode(root)->value;
    cout << endl;
    cout << find(root,9);
}


