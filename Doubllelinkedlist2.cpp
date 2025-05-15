#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList{
    private:
    Node *START;

    public:
        DoubleLinkedList(){
            START = NULL;
        }
        void addNode(){
            int nim;
            cout << "\nEnter the roll number of the student: ";
            cin >> nim;

            //step 1 allocation mememory of new node
            Node *newNode = new Node();
            //step 2 assign value to the data field
            newNode->noMhs = nim;

            //step 3 insert at begginning if list empty or nim is smallest
            if (START == NULL || nim <= START->noMhs){
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }

            //step 4 newNode.next = START
            newNode->next = START;

            //step5 start.prev = newNode(if start exists)
            if(START != NULL)
            START->prev = newNode;

            //step 6 newNode.prev = NULL
            newNode->prev = NULL;

            //step 7 start = newNode
            START = newNode;
            return;
        }

        //insert in between node
        //step 8 locate posisi for insertion
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim){
            
        }
};