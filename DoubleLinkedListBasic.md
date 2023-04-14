**_create a node_**

```cpp
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int data){
            this->data = data;
            next = NULL;
            prev = NULL;
        }
    ~Node(){
        delete next;
        delete prev;
    }
};
```

**_*create a double linked list*_**

```cpp
class DoubleLinkedList{
    public:
        Node* head;
        Node* tail;
        DoubleLinkedList(){
            head = NULL;
            tail = NULL;
        }
};
```

**_*insert a node at the beginning*_**

```cpp
void insertAtBeginning(DoubleLinkedList* list, int data){
    Node* newNode = new Node(data);
    if(list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
    }
    else{
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}
```

**_*insert a node at the end*_**

```cpp
void insertAtEnd(DoubleLinkedList* list, int data){
    Node* newNode = new Node(data);
    if(list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
    }
    else{
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
}
```

**_*insert a node after a given node*_**

```cpp
void insertAfterNode(DoubleLinkedList* list, int data, int after){
    Node* newNode = new Node(data);
    Node* temp = list->head;
    while(temp != NULL){
        if(temp->data == after){
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            if(newNode->next != NULL){
                newNode->next->prev = newNode;
            }
            else{
                list->tail = newNode;
            }
            break;
        }
        temp = temp->next;
    }
}
```

**_*insert a node before a given node*_**

```cpp
void insertBeforeNode(DoubleLinkedList* list, int data, int before){
    Node* newNode = new Node(data);
    Node* temp = list->head;
    while(temp != NULL){
        if(temp->data == before){
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev = newNode;
            if(newNode->prev != NULL){
                newNode->prev->next = newNode;
            }
            else{
                list->head = newNode;
            }
            break;
        }
        temp = temp->next;
    }
}
```

**_*delete a node*_**

```cpp
void deleteNode(DoubleLinkedList* list, int data){
    Node* temp = list->head;
    while(temp != NULL){
        if(temp->data == data){
            if(temp->prev != NULL){
                temp->prev->next = temp->next;
            }
            else{
                list->head = temp->next;
            }
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }
            else{
                list->tail = temp->prev;
            }
            delete temp;
            break;
        }
        temp = temp->next;
    }
}
```

**_*delete a node at the beginning*_**

```cpp
void deleteAtBeginning(DoubleLinkedList* list){
    if(list->head == NULL){
        return;
    }
    Node* temp = list->head;
    list->head = list->head->next;
    if(list->head != NULL){
        list->head->prev = NULL;
    }
    else{
        list->tail = NULL;
    }
    delete temp;
}
```

**_*delete a node at the end*_**

```cpp
void deleteAtEnd(DoubleLinkedList* list){
    if(list->head == NULL){
        return;
    }
    Node* temp = list->tail;
    list->tail = list->tail->prev;
    if(list->tail != NULL){
        list->tail->next = NULL;
    }
    else{
        list->head = NULL;
    }
    delete temp;
}
```

**_*delete a node at a given position*_**

```cpp
void deleteAtPosition(DoubleLinkedList* list, int pos){
    if(list->head == NULL){
        return;
    }
    Node* temp = list->head;
    int count = 0;
    while(temp != NULL){
        if(count == pos){
            if(temp->prev != NULL){
                temp->prev->next = temp->next;
            }
            else{
                list->head = temp->next;
            }
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }
            else{
                list->tail = temp->prev;
            }
            delete temp;
            break;
        }
        count++;
        temp = temp->next;
    }
}
```

**_*delete a node after a given node*_**

```cpp
void deleteAfterNode(DoubleLinkedList* list, int data){
    Node* temp = list->head;
    while(temp != NULL){
        if(temp->data == data){
            if(temp->next != NULL){
                Node* temp2 = temp->next;
                temp->next = temp2->next;
                if(temp2->next != NULL){
                    temp2->next->prev = temp;
                }
                else{
                    list->tail = temp;
                }
                delete temp2;
            }
            break;
        }
        temp = temp->next;
    }
}
```

**_*delete a node before a given node*_**

```cpp
void deleteBeforeNode(DoubleLinkedList* list, int data){
    Node* temp = list->head;
    while(temp != NULL){
        if(temp->data == data){
            if(temp->prev != NULL){
                Node* temp2 = temp->prev;
                temp->prev = temp2->prev;
                if(temp2->prev != NULL){
                    temp2->prev->next = temp;
                }
                else{
                    list->head = temp;
                }
                delete temp2;
            }
            break;
        }
        temp = temp->next;
    }
}
```

**_delete all the occurrences of a given node_**

```cpp
void deleteAllOccurences(DoubleLinkedList* list, int data){
    Node* temp = list->head;
    while(temp != NULL){
        if(temp->data == data){
            if(temp->prev != NULL){
                temp->prev->next = temp->next;
            }
            else{
                list->head = temp->next;
            }
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }
            else{
                list->tail = temp->prev;
            }
            Node* temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
        else{
            temp = temp->next;
        }
    }
}
```

**_delete at a given range_**

```cpp
void deleteAtRange(DoubleLinkedList* list, int start, int end){
    Node* temp = list->head;
    int count = 0;
    while(temp != NULL){
        if(count >= start && count <= end){
            if(temp->prev != NULL){
                temp->prev->next = temp->next;
            }
            else{
                list->head = temp->next;
            }
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }
            else{
                list->tail = temp->prev;
            }
            Node* temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
        else{
            temp = temp->next;
        }
        count++;
    }
}
```

**_Reverse a double linked list_**

```cpp
void reverse(DoubleLinkedList* list){
    Node* temp = list->head;
    while(temp != NULL){
        Node* temp2 = temp->next;
        temp->next = temp->prev;
        temp->prev = temp2;
        temp = temp2;
    }
    temp = list->head;
    list->head = list->tail;
    list->tail = temp;
}
```

**_Swap two nodes in a double linked list_**

```cpp
void swapNodes(DoubleLinkedList* list, int data1, int data2){
    Node* temp1 = list->head;
    Node* temp2 = list->head;
    while(temp1 != NULL){
        if(temp1->data == data1){
            break;
        }
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        if(temp2->data == data2){
            break;
        }
        temp2 = temp2->next;
    }
    if(temp1 == NULL || temp2 == NULL){
        return;
    }
    if(temp1->prev != NULL){
        temp1->prev->next = temp2;
    }
    else{
        list->head = temp2;
    }
    if(temp2->next != NULL){
        temp2->next->prev = temp1;
    }
    else{
        list->tail = temp1;
    }
    Node* temp3 = temp1->next;
    temp1->next = temp2->next;
    temp2->next = temp3;
    temp3 = temp1->prev;
    temp1->prev = temp2->prev;
    temp2->prev = temp3;
}
```

**Reverse a double linked list in a range**

```cpp
void reverseRange(DoubleLinkedList* list, int start, int end){
    Node* temp = list->head;
    while(temp != NULL){
        if(temp->data == start){
            break;
        }
        temp = temp->next;
    }
    Node* temp2 = temp;
    while(temp2 != NULL){
        if(temp2->data == end){
            break;
        }
        temp2 = temp2->next;
    }
    Node* temp3 = temp->prev;
    Node* temp4 = temp2->next;
    while(temp != temp2){
        Node* temp5 = temp->next;
        temp->next = temp->prev;
        temp->prev = temp5;
        temp = temp5;
    }
    temp->next = temp->prev;
    temp->prev = temp2->next;
    if(temp3 != NULL){
        temp3->next = temp2;
    }
    else{
        list->head = temp2;
    }
    if(temp4 != NULL){
        temp4->prev = temp;
    }
    else{
        list->tail = temp;
    }
}
```

**_Merge two sorted double linked lists_**

```cpp
DoubleLinkedList* merge(DoubleLinkedList* list1, DoubleLinkedList* list2){
    DoubleLinkedList* list = new DoubleLinkedList();
    Node* temp1 = list1->head;
    Node* temp2 = list2->head;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data < temp2->data){
            insertAtEnd(list, temp1->data);
            temp1 = temp1->next;
        }
        else{
            insertAtEnd(list, temp2->data);
            temp2 = temp2->next;
        }
    }
    while(temp1 != NULL){
        insertAtEnd(list, temp1->data);
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        insertAtEnd(list, temp2->data);
        temp2 = temp2->next;
    }
    return list;
}
```

**_Merge two double linked lists in a sorted way_**

```cpp
DoubleLinkedList* merge(DoubleLinkedList* list1, DoubleLinkedList* list2){
    DoubleLinkedList* list = new DoubleLinkedList();
    Node* temp1 = list1->head;
    Node* temp2 = list2->head;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data < temp2->data){
            insertAtEnd(list, temp1->data);
            temp1 = temp1->next;
        }
        else{
            insertAtEnd(list, temp2->data);
            temp2 = temp2->next;
        }
    }
    while(temp1 != NULL){
        insertAtEnd(list, temp1->data);
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        insertAtEnd(list, temp2->data);
        temp2 = temp2->next;
    }
    return list;
}
```

**_Sort a double linked list using bubble sort_**

```cpp
void bubbleSort(DoubleLinkedList* list){
    Node* temp = list->head;
    while(temp != NULL){
        Node* temp2 = temp->next;
        while(temp2 != NULL){
            if(temp->data > temp2->data){
                int temp3 = temp->data;
                temp->data = temp2->data;
                temp2->data = temp3;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}
```

**_*print the list*_**

```cpp
void printList(DoubleLinkedList* list){
    Node* temp = list->head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
```

**_*print the list in reverse*_**

```cpp
void printListReverse(DoubleLinkedList* list){
    Node* temp = list->tail;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
```
