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

        void addNode()
        {
            int nim;
            cout << "\nEnter the roll number of the student: ";
            cin >> nim;

            //step 1 allocation mememory of new node
            Node *newNode = new Node();
            //step 2 assign value to the data field
            newNode->noMhs = nim;

            //step 3 insert at begginning if list empty or nim is smallest
            if (START == NULL || nim <= START->noMhs){
                if(START != NULL && nim == START->noMhs){
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
                current = current->next;
            }

            if(current->next != NULL && nim == current->next->noMhs){
                cout << "\nduplicate roll number not allowed" << endl;
                return;
            }
            // step 9 insert between current and current->next
            newNode->next = current->next; //step 9a newnode.next = current.next
            newNode->prev = current;    //step9b newnode.prev = current

            //insert last node
            if(current->next != NULL)
                current->next->prev = newNode; // step 9c current.next.prev = newNode

            current->next = newNode;
        }

        void hapus(){
            if(START == NULL){
                cout << "\nList is empty" << endl;
                return;
            }
            cout << "\nEnter Nim yang akan di delet";
            int rollNo;
            cin >> rollNo;

            Node *current = START;
            //step 1 traverse the list to find the node
            while(current != NULL && current->noMhs != rollNo)
                current = current->next;

            if(current == NULL){
                cout << "RECORD NOT FOUND" << endl;
                return;
            }

            //step 2 if node is at the beginning
            if (current == START){
                START = current->next;  //step 2a  start = start
                if(START != NULL)
                    START->prev = NULL;
            }
            else{
            //step3 link prev node to next current
            current->prev->next = current->prev;

            //step 4 if current is not the last node
            if(current->next != NULL)
                current->next->prev = current->prev;
            }

            //step 5 delet the node
            delete current;
            cout << "Record with roll number" << rollNo << "deleted" << endl;
    }
};