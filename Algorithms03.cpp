#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node* head;
    
    void insert(int data, Node** head){
        Node* newNode = new Node();
        Node* temp = *head;
        newNode->data = data;
        newNode->next = *head;
        if(*head == NULL){
            *head = newNode;
            newNode->prev = NULL;
            return;
        }
        else{
        while(temp->next != NULL){
            temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    }
    void printInOrder(Node** head){
        Node* temp = *head;
        if(temp == NULL){
            cout << "List is empty" << endl;
            return;
        }
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void remover(int index, Node** head){
        /*int counter = 0;
        Node* temp = *head;
        for (int i = 0; i < index; i++)
        {
            if(counter == index){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                return;
            }
            counter++;
            temp = temp->next;
        }*/
        cout << "Removing";
    }
    void add(int index, Node** head){
        /*int counter = 0;
        Node* temp = *head;
        for (int i = 0; i < index; i++)
        {
            if(counter == index){
                temp->next = temp;
                temp->next->prev = temp->next;
                temp->prev = *head;
            }
            counter++;
            temp = temp->next;
        }*/
        cout << "Adding";
    }
    int size(){
        Node* temp = this;
        int counter = 0;
        while(temp != NULL){
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    void show(int index, Node** head){
        int counter = 0;
        Node* temp = *head;
        for (int i = 0; i < index; i++)
        {
            if(counter == index){
                cout << temp->data << endl;
                return;
            }
            counter++;
            temp = temp->next;
        }
    }
};

int main()
{
    Node *head = NULL;
    int numOfTeams, startingTeam;
    bool direction = 0;
    int operations, move = 0, index, flag = 0;
    cout << "Enter team data:\n";
    cin >> numOfTeams;
    cout << "Enter starting team:\n";
    cin >> startingTeam;
    index = startingTeam;
    for (int i = 0; i < numOfTeams; i++)
    {
       head->insert(i, &head);
       if(i == 0){head->insert(numOfTeams-1, &head);}
       else{
            head->insert(i - 1, &head);
       }
    }
    head->printInOrder(&head);
    cout << "Enter direction ( 1 | 0 ):\n ";
    cin >> direction;
    cout<<"Enter number of operations:\n";
    cin >> operations;
    for(int i = 0; i < operations; i++){
        cin >> move;
        if(direction == 1){
            index += move;
            }else{
            abs(index -= move);
        }
        index %= head->size();
        switch (move)
            {
            case 0:
            head->show(index, &head);
            break;
            case 1:
                //Remove player
                switch(flag){
                    case 0:
                        index %= head->size();
                        head->remover(index, &head);
                    break;
                    case 1:
                        index %= head->size();
                        head->remover(index, &head);
                        head->add(index, &head);
                    break;
                }
            break;
            case 2:
                //Direction change
                direction = !direction;
            break;
            }
        }
        return 0;
}