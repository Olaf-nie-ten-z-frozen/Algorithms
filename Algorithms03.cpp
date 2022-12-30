#include<iostream>
using namespace std;

class Node{
    public:
    int data{};
    Node* next{};
    Node* prev{};

    static void insert(int data, Node** head){
        Node* newNode = new Node();
        Node* temp = *head;
        if(*head == nullptr){
        newNode->data = data;
        newNode->next = newNode->prev = newNode;
            *head = newNode;
            return;
        }
        Node* last = (*head)->prev;
        newNode->data = data;
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }
    void printInOrder(){
        Node* temp = this;
        Node* mem = temp;
        if(temp == nullptr){
            cout << "List is empty" << endl;
            return;
        }
        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != mem);
        cout << endl;
    }
    static void remover(int index, Node** head){
        int counter = 0;
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
        }
        cout << "Removing";
    }
    static void add(int index, Node** head){
        int counter = 0;
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
        }
        cout << "Adding";
    }
    int size(){
        Node* temp = this;
        Node* mem = this;
        int counter = 0;
        do{
            counter++;
            temp = temp->next;
        }while(temp != mem);
        return counter;
    }
    static void show(int index, Node** head){
        int counter = 0;
        Node* temp = *head;
        while(counter != index){
            temp = temp->next;
            counter++;
        }
        Node* mem = temp;
        if(temp == nullptr){
            cout << "List is empty" << endl;
            return;
        }
        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != mem);
        cout << endl;
    }
};

int main()
{
    Node *head = nullptr;
    int numOfTeams, startingTeam;
    bool direction = false;
    int operations, move = 0, index, flag = 0,case_nr = 0;
    cout << "Enter team data:\n";
    cin >> numOfTeams;
    cout << "Enter starting team:\n";
    cin >> startingTeam;
    cout<<"Enter direction: ";
    cin >> direction;
    cout<<"Number of operations: ";
    cin >> operations;
    index = startingTeam;
    for (int i = 0; i < numOfTeams; i++)
    {
       head->insert(i, &head);
       if(i == 0){head->insert(numOfTeams-1, &head);}
       else{
            head->insert(i - 1, &head);
       }
    }
    for(int i = 0; i < operations; i++){
        cout<<"Enter Operations: ";
        cin >> case_nr;
        switch (case_nr)
            {
            case 0:
            cin >> move;
                if(direction){
                    index += move;
                }else abs(index -= move);
                index %= head->size();
            head->show(index, &head);
            break;
            case 1:
                //Remove player
                cin >> move;
                if(direction){
                    index += move;
                }else abs(index -= move);
                index %= head->size();
                cout<<"Flag: ";
                cin>>flag;
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
            cin >> move;
                if(direction){
                    index += move;
                }else abs(index -= move);
                index %= head->size();
                //Direction change
                direction = !direction;
            break;
            }
        }
        return 0;
}