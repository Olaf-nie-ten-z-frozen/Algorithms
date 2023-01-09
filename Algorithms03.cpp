#include<iostream>

using namespace std;

class QueueElement{
public:
    int value;
    QueueElement* next;

    QueueElement(int value){
        this->value = value;
        this->next = NULL;
    }
};
class Queue{
public:
    int size;
    QueueElement* first;
    QueueElement* last;
    Queue(){
        size = 0;
        first = NULL;
        last = NULL;
    }
    void push_back(int value){
        if(last == NULL){
            last = new QueueElement(value);
            first = last;
        }else {
            last->next = new QueueElement(value);
            if(last == first){
                first->next = last->next;
            }
            last = last->next;
        }
        size++;
    }
    int pop_first(){
        int value = first->value;
        QueueElement* temp = first;
        first = first->next;
        size--;
        delete temp;
        return value;
    }
};
Queue queue;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node (int data){
        this->data = data;
    }
    Node(){}
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
    static void remover(int index, Node** head, int* tab, bool direction){
        int counter = 0;
        Node* temp = *head;
        if(index == 0){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            tab[temp->data]--;
            if(tab[temp->data] == 0) {
                queue.push_back(temp->data);
            }
            if(direction) {
                *head = (*head)->next;
            }else{
                *head = (*head)->next;
            }
            delete temp;
            return;
        }
        if(direction){index++;}else{index--;}
        while(1){
            if(counter == index){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            //cout << "Removing: \n"<<temp->data << "\n";
            tab[temp->data]--;
            if(tab[temp->data] == 0) {
                queue.push_back(temp->data);
            }
            delete temp;
            return;
            }
            temp = temp->next;
            counter++;
            }
    }
    void add(int index, Node** head, int* tab, bool direction){
        int counter = 0;
        int value = queue.pop_first();
        Node* temp1 = new Node(value);
        Node* temp2 = new Node(value);
        tab[value] = 2;
        Node* temp = *head;
        while(true){
            if(counter == index){
                if(direction){
                    temp = temp->prev;
                    temp1->prev = temp->prev;
                    temp1->next = temp;
                    temp->prev->next = temp1;
                    temp->prev = temp1;
                    temp = temp->next;
                    temp2->prev = temp;
                    temp2->next = temp->next;
                    temp->next->prev = temp2;
                    temp->next = temp2;
                }else{
                    temp1->prev = temp->prev;
                    temp1->next = temp;
                    temp->prev->next = temp1;
                    temp->prev = temp1;
                    temp = temp->next;
                    temp2->prev = temp;
                    temp2->next = temp->next;
                    temp->next->prev = temp2;
                    temp->next = temp2;
                }
            }
            counter++;
            temp = temp->next;
        }
        //cout << "Adding: \n" << temp->data << "\n";
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
    static void show(int index, Node** head, int direction){
        int counter = 0;
        Node* temp = *head;
        while(counter != index){
            temp = temp->next;
            counter++;
        }
        Node* mem = temp;
        if(temp == nullptr){
            //cout << "List is empty\n";
            return;
        }
        do{
            if(direction){
                cout<<temp->data << " ";
                temp = temp->prev;
            }else {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }while(temp != mem);
        //cout << "\n";
    }
};

int main()
{
    Node *head = nullptr;
    Queue *begin = nullptr;
    int* tab;
    int numOfTeams, startingTeam;
    bool direction = false;
    int operations, move = 0, index, flag = 0,case_nr = 0;
    //cout << "Enter team data:\n";
    cin >> numOfTeams;
    //cout << "Enter starting team:\n";
    cin >> startingTeam;
    //cout<<"Enter direction: \n";
    cin >> direction;
    //cout<<"Number of operations: \n";
    cin >> operations;
    tab = new int[numOfTeams];
    index = startingTeam*2;
    for (int i = 0; i < numOfTeams; i++)
    {
        tab[i] = 2;
       head->insert(i, &head);
       if(i == 0){
           head->insert(numOfTeams - 1, &head);
       }
       else{
            head->insert(i - 1, &head);
       }
    }
    for(int i = 0; i < operations; i++){
        //cout<<"Enter Operations:\n";
        cin >> case_nr;
        cin >> move;
        if(direction){
            while((index - move) < 0) {
                index += head->size();
            }
            index = index - move;
        }else {
            index = index + move;
        }
        index %= head->size();
        switch (case_nr)
            {
            case 0:
            head->show(index, &head, direction);
            break;
            case 1:
                //Remove player
                //cout<<"Flag: \n";
                cin>>flag;
                switch(flag){
                    case 0:
                        head->remover(index, &head, tab, direction);
                        if(head->size() <= 3){
                            head->add(index, &head, tab, direction);
                        }
                        if(!direction){
                            index --;
                        }
                    break;
                    case 1:
                        if(head->size() == 0) {
                            head->remover(index, &head, tab, direction);
                            if(queue.size) {
                                head->add(index, &head, tab, direction);
                            }
                        }
                    break;
                }
                direction = !direction;
            break;
            case 2:
                //Direction change
                direction = !direction;
            break;
            }
        }
        return 0;
}