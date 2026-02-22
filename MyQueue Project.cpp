#include <iostream>
using namespace std;


template <class T>

class clsDblLinkedList
{
protected:
      int _Size = 0;
public:

    class Node
    {

    public:
        T value;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;

    void InsertAtBeginning(T value)
    {

        /*
            1-Create a new node with the desired value.
            2-Set the next pointer of the new node to the current head of the list.
            3-Set the previous pointer of the current head to the new node.
            4-Set the new node as the new head of the list.
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        _Size++;

    }

    // Print the linked list
    void PrintList()
    {
        Node* Current = head;

        while (Current != NULL) {
            cout << Current->value << " ";
            Current = Current->next;
        }
        cout << "\n";
       

    }

    Node* Find(T Value)
    {
        Node* Current = head;
        while (Current != NULL) {

            if (Current->value == Value)
                return Current;

            Current = Current->next;
        }

        return NULL;

    }

    void InsertAfter(Node* current, T value) 
    {


        /*  1 - Create a new node with the desired value.
             2-Set the next pointer of the new node to the next node of the current node.
             3-Set the previous pointer of the new node to the current node.
             4-Set the next pointer of the current node to the new node.
             5-Set the previous pointer of the next node to the new node(if it exists).
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        _Size++;

    }

    void InsertAtEnd(T value) 
    {

        /*
            1-Create a new node with the desired value.
            2-Traverse the list to find the last node.
            3-Set the next pointer of the last node to the new node.
            4-Set the previous pointer of the new node to the last node.
        */


        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
        _Size++;

    }

    void DeleteNode(Node*& NodeToDelete) 
    {

        /*
            1-Set the next pointer of the previous node to the next pointer of the current node.
            2-Set the previous pointer of the next node to the previous pointer of the current node.
            3-Delete the current node.
        */
        if (head == NULL || NodeToDelete == NULL) {
            return;
        }
        if (head == NodeToDelete) {
            head = NodeToDelete->next;
        }
        if (NodeToDelete->next != NULL) {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != NULL) {
            NodeToDelete->prev->next = NodeToDelete->next;
        }
        delete NodeToDelete;
        _Size--;
    
    }

    void DeleteFirstNode()
    {

        /*
            1-Store a reference to the head node in a temporary variable.
            2-Update the head pointer to point to the next node in the list.
            3-Set the previous pointer of the new head to NULL.
            4-Delete the temporary reference to the old head node.
        */

        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        _Size--;
    }

    void DeleteLastNode() 
    {

        /*
            1-Traverse the list to find the last node.
            2-Set the next pointer of the second-to-last node to NULL.
            3-Delete the last node.
        */

        if (head == NULL) {
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        // we need to find the node before last node.
        while (current->next->next != NULL)
        {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = NULL;
        delete temp;
        _Size--;
    }
    
    int Size()
    { 
        return _Size;
    }
    
    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);
    }

    void Clear()
    {
        while(_Size > 0)
        {
            DeleteFirstNode();
        }   
    }
    
    void Reverse()
    {
        Node* Current = head;
        Node* Temp = nullptr;

        while (Current != nullptr)
        {
            Temp = Current->prev;
            Current->prev = Current->next;
            Current->next = Temp;
            Current = Current->prev;
        }
        
        if (Temp != nullptr)
        {
            head = Temp->prev;
        }
        
    }
    
    Node* GetNode(T Index)
    {
        if (Index > _Size-1 || Index < 0)
            return NULL;
        
        T Counter = 0;
        Node* Current = head;
       
        while (Current != NULL && Current->next != NULL)
        {
            if (Counter == Index)
            {
                break;
            }
            
            Counter++;
            Current = Current->next;
        }
        
        return Current;
    }
    
    T GetItem(int Index)
    {
       Node* ItemNode = GetNode(Index);

        if (ItemNode == NULL)
           return NULL;
   
        else
           return ItemNode->value;   
    }
    
    bool UpdateItem(int Index, T value)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode != NULL)
        {           
            ItemNode->value = value;
            return true;
        }
        
        else
            return false;
        
         
    }
    
    bool InsertAfter(int Index, T value)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode != NULL)
        {
           InsertAfter(ItemNode, value);
           return true;
        }
        
        else 
           return false;
    }
    
};

template <class T>

class clsMyQueue 
{

protected:

clsDblLinkedList <T> _MyList;

public:

int Size()
{
    return _MyList.Size();
}

void Print()
{
    _MyList.PrintList();
}

void push(T Item)
{
    _MyList.InsertAtEnd(Item);
}

T front()
{
    return _MyList.GetItem(0);
}

T back()
{
    return _MyList.GetItem(_MyList.Size()-1);
}

void pop()
{
    _MyList.DeleteFirstNode(); 
}

void IsEmpty()
{
   _MyList.IsEmpty();
}

T GetItem(int Index)
{
   return _MyList.GetItem(Index);
}

void Reverse()
{
   _MyList.Reverse();
}

void UpdateItem(int Index, T value)
{
    _MyList.UpdateItem(Index, value);
}

void InsertAfter(int Index, T value)
{
   _MyList.InsertAfter(Index, value);
}

void InsertAtFront(T value)
{
    _MyList.InsertAtBeginning(value);
}

void InsertAtback(T value)
{
    _MyList.InsertAtEnd(value);
}

void Clear()
{
    _MyList.Clear();
}

};


int main()
{
    clsMyQueue <int> MyQueue;
 
    MyQueue.push(10);
    MyQueue.push(20);
    MyQueue.push(30);
    MyQueue.push(40);
    MyQueue.push(50);

    cout << "\nQueue:\n";
    MyQueue.Print();

    cout << "\nQueue Size: " << MyQueue.Size();
    cout << "\nQueue Front: " << MyQueue.front();
    cout << "\nQueue Back: " << MyQueue.back();

    MyQueue.pop();

    cout << "\n\nQueue after pop() : \n";    
    MyQueue.Print();

    cout << "\n\nItem(2): " << MyQueue.GetItem(2);

    MyQueue.Reverse();
    cout << "\n\nQueue after reverse() : \n";    
    MyQueue.Print();

    MyQueue.UpdateItem(2,600);
    cout << "\n\nQueue after Updating Item(2) to 600 : \n";    
    MyQueue.Print();

    MyQueue.InsertAfter(2,800);
    cout << "\n\nQueue after Inserting 800 after Item(2) : \n";    
    MyQueue.Print();

    MyQueue.InsertAtFront(1000);
    cout << "\n\nQueue after Inserting 1000 at front : \n";    
    MyQueue.Print();

    MyQueue.InsertAtback(2000);
    cout << "\n\nQueue after Inserting 2000 at back : \n";    
    MyQueue.Print();
    
    MyQueue.Clear();
    cout << "\n\nQueue after Clear() : \n";    
    MyQueue.Print();

    return 0;
}
