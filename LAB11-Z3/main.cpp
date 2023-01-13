#include <iostream>
#include <memory>
using namespace std;
template <class T>
class Node {
    public:
        T data;
        shared_ptr<Node> next;
        weak_ptr<Node> prev;
        ~Node () {
            cout<<"Zniszczono wezel"<<endl;
        }
};
template <class T>
void addHead (shared_ptr<Node<T>> &head, T newData)
{
    shared_ptr<Node<T>> newNode(new Node<T>());
    newNode->data = newData;
    newNode->next = head;
    newNode->prev.reset();
    if (head.get() != NULL) head->prev = newNode;
    head = newNode;
    newNode.reset();
}

template <class T>
void addTail (shared_ptr<Node<T>> &head, T newData)
{
    shared_ptr<Node<T>> newNode(new Node<T>());
    newNode->data = newData;
    newNode->next.reset();
    if (head.get() == NULL)
    {
        newNode->prev.reset();
        head = newNode;
        return;
    }
    shared_ptr<Node<T>> last = head;
    while (last->next != NULL) last = last->next;
    last->next = newNode;
    newNode->prev = last;
    newNode.reset();
    last.reset();
}

template <class T>
void delHead (shared_ptr<Node<T>> &head)
{
    if (head.get() == NULL) return;
    head = head->next;
    head->prev.reset();
}
template <class T>
void delTail (shared_ptr<Node<T>> &head)
{
    if (head.get() == NULL) return;
    if (head->next == NULL)
        {
            head.reset();
            return;
        }
    shared_ptr<Node<T>> temp(new Node<T>());
    temp = head;
    while (temp->next->next != NULL)
    {
    temp = temp->next;
    }
    temp->next = NULL;
    temp.reset();
}
template <class T>
void show (shared_ptr<Node<T>> head)
{
    while (head != NULL)
        {
            cout<<head->data<<" <> ";
            head = head->next;
        }
    cout<<endl;
}
template <class T>
bool isEmpty (shared_ptr<Node<T>> head)
{
    return head == NULL;
}

int main () {
    shared_ptr<Node<int>> head = NULL;
    cout<<isEmpty(head)<<endl;
    addHead(head, 3);
    addHead(head, 4);
    addHead(head, 5);
    addTail(head, 6);
    show(head);
    delHead(head);
    show(head);
    delTail(head);
    show(head);
    cout<<isEmpty(head)<<endl;
    cin.ignore();
    cin.get();
    return 0;
}
