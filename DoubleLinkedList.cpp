#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
        if (prev != NULL)
        {
            delete prev;
        }
    }
};

class DoubleLinkedList
{
    Node *head;
    Node *tail;

public:
    DoubleLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    DoubleLinkedList(int size)
    {
        head = NULL;
        tail = NULL;
        for (int i = 0; i < size; i++)
        {
            push_back(0);
        }
    }
    DoubleLinkedList(int size, int data)
    {
        head = NULL;
        tail = NULL;
        for (int i = 0; i < size; i++)
        {
            push_back(data);
        }
    }

    void push_front(int data)
    {
        // create new node
        Node *new_node = new Node(data);
        // if list is empty
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        // new node will be point to the head;
        new_node->next = head;
        // previous of head will be point to new node
        head->prev = new_node;
        // new node will be head
        head = new_node;
    }

    void push_back(int data)
    {
        // create new node
        Node *new_node = new Node(data);
        // if list is empty
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        // tail next will be point to new node
        tail->next = new_node;
        // previous of new node will be point to tail
        new_node->prev = tail;
        // new node will be tail
        tail = new_node;
    }

    void insert(int data, int index)
    {
        int c = 0;
        Node *temp = head;
        // create new node
        Node *new_node = new Node(data);
        // move forward till index
        if (index == 0)
        {
            push_front(data);
            return;
        }
        while (c != index - 1)
        {
            if (temp->next == NULL)
            {
                cout << "Index " << index << " is out of bound" << endl;
                return;
            }
            temp = temp->next;
            c++;
        }
        if (temp->next == NULL)
        {
            push_back(data);
            return;
        }

        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next = new_node;
        new_node->next->prev = new_node;
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }

    void erase(int index)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (index == 0)
        {
            pop_front();
            return;
        }
        int c = 0;
        Node *temp = head;
        while (c != index)
        {
            if (temp->next == NULL)
            {
                cout << "Index " << index << " is out of bound" << endl;
                return;
            }
            temp = temp->next;
            c++;
        }
        if (temp->next == NULL)
        {
            pop_back();
            return;
        }
        // 1->2->3->4->5
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    }

    void reverse()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *t = temp->next;
            temp->next = temp->prev;
            temp->prev = t;
            temp = t;
        }
        temp = head;
        head = tail;
        tail = temp;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void Swap(int index1, int index2)
    {
        if (head == NULL)
            return;
        if (index1 == index2)
            return;
        Node *temp1 = head;
        Node *temp2 = head;
        int c = 0;
        while (c != index1)
        {
            if (temp1->next == NULL)
            {
                cout << "Index " << index1 << " is out of bound" << endl;
                return;
            }
            temp1 = temp1->next;
            c++;
        }
        c = 0;
        while (c != index2)
        {
            if (temp2->next == NULL)
            {
                cout << "Index " << index2 << " is out of bound" << endl;
                return;
            }
            temp2 = temp2->next;
            c++;
        }
        int t = temp1->data;
        temp1->data = temp2->data;
        temp2->data = t;
    }

    void Sort()
    {
        Node *temp = head;
        for (int i = 0; temp != NULL; i++, temp = temp->next)
        {
            Node *temp2 = temp->next;
            for (int j = i + 1; temp2 != NULL; j++, temp2 = temp2->next)
                if (temp->data > temp2->data)
                    Swap(i, j);
        }
    }
    void Sort(int data)
    {
        if (data)
        {
            Node *temp = head;
            for (int i = 0; temp != NULL; i++, temp = temp->next)
            {
                Node *temp2 = temp->next;
                for (int j = i + 1; temp2 != NULL; j++, temp2 = temp2->next)
                    if (temp->data < temp2->data)
                        Swap(i, j);
            }
        }
        else
        {
            Node *temp = head;
            for (int i = 0; temp != NULL; i++, temp = temp->next)
            {
                Node *temp2 = temp->next;
                for (int j = i + 1; temp2 != NULL; j++, temp2 = temp2->next)
                    if (temp->data > temp2->data)
                        Swap(i, j);
            }
        }
    }

    void priority_insert(int data, bool way = 1)
    {
        // way == 1 for ascending order
        // way == 0 for descending order
        Node *new_node = new Node(data);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        if (way)
        {
            if (head->data > data)
            {
                push_front(data);
                return;
            }
        }
        else
        {
            if (head->data < data)
            {
                push_front(data);
                return;
            }
        }
        Node *temp = head;
        if (way)
        {
            while (temp->next != NULL && temp->next->data < data)
                temp = temp->next;
        }
        else
        {
            while (temp->next != NULL && temp->next->data > data)
                temp = temp->next;
        }
        if (temp->next == NULL)
        {
            push_back(data);
            return;
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next = new_node;
        new_node->next->prev = new_node;
    }

    int sum()
    {
        int sum = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            sum += temp->data;
            temp = temp->next;
        }
        return sum;
    }

    int mx()
    {
        if (head == NULL)
        {
            return -1;
        }
        int mx = head->data;
        Node *temp = head;
        while (temp != NULL)
        {
            mx = max(mx, temp->data);
            temp = temp->next;
        }
        return mx;
    }

    int mn()
    {
        if (head == NULL)
        {
            return -1;
        }
        int mn = head->data;
        Node *temp = head;
        while (temp != NULL)
        {
            mn = min(mn, temp->data);
            temp = temp->next;
        }
        return mn;
    }

    void clear()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            Node *t = temp->next;
            delete temp;
            temp = t;
        }
        head = NULL;
        tail = NULL;
    }

    bool empty()
    {
        return head == NULL;
    }

    bool find(int data)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int indexOf(int data)
    {
        Node *temp = head;
        int c = 0;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                return c;
            }
            temp = temp->next;
            c++;
        }
        return -1;
    }

    int lastIndexOf(int data)
    {
        Node *temp = head;
        int c = 0;
        int index = -1;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                index = c;
            }
            temp = temp->next;
            c++;
        }
        return index;
    }

    int Count(int c)
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            if (temp->data == c)
            {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }

    void remove(int data)
    {
        if (indexOf(data) == -1)
            return;
        erase(indexOf(data));
        remove(data);
    }

    void remove_duplicate()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            remove_duplicate(temp->data);
            temp = temp->next;
        }
        return;
    }
    void remove_duplicate(int data)
    {
        if (Count(data) == 1 || Count(data) == 0)
            return;
        erase(lastIndexOf(data));
        remove_duplicate(data);
    }
    bool isSorted()
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->data > temp->next->data)
            {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }

    int size()
    {
        Node *temp = head;
        int c = 0;
        while (temp != NULL)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }

    ~DoubleLinkedList()
    {
        if (head != NULL)
        {
            delete head;
        }
        if (tail != NULL)
        {
            delete tail;
        }
    }
};
int main()
{
    DoubleLinkedList d;
    d.insert(10, 0);
    d.push_front(10);
    d.insert(20, 2);
    d.push_back(30);

    d.print();

    d.insert(100, 3);
    d.insert(200, 5);
    d.pop_front();
    d.pop_back();
    d.print();
    d.erase(2);
    d.print();
    d.reverse();
    d.print();

    d.Swap(0, 1);
    d.print();

    d.Sort();
    d.print();

    d.priority_insert(5);
    d.priority_insert(15);
    d.priority_insert(25);
    d.print();

    d.priority_insert(5, 0);
    d.priority_insert(15, 0);
    d.priority_insert(25, 0);
    d.print();
    d.remove(5);
    d.print();

    d.remove_duplicate();
    d.print();
    d.remove_duplicate(15);
    d.print();
    d.Sort();
    d.print();
    d.Sort(1);
    d.print();
    cout << d.sum() << endl;
    cout << d.mx() << endl;
    cout << d.mn() << endl;

    d.clear();
    d.print();
    return 0;
}