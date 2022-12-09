#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    class insertIfEmpty(int data, Node* head){
        if(head == NULL){
            Node* temp = new Node();
            temp->data = data;
            temp->next = NULL;
            head = temp;
        }
        return head;
    }
    class Node *insert(hNode *last, int new_data)
    {
    //if list is empty then add the node by calling insertIfEmpty
    if (last == NULL){
        return insertIfEmpty(new_data, last);
    }
    //if list is not empty then add the node at the end
    Node *temp = new Node;

    temp -> data = new_data;
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;
    return last;
}
    void print(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}
int move(int move, bool direction, Node *head){
    
    if(direction == 0){
        
    }
    else{
        //TODO
    }
}
int main(){
    Node *head = new Node();
    int numOfTeams, startingTeam;
    bool direction = 0;
    int* team;
    int operations, move, index;
    cout << "Enter team data:\n";
    cin >> numOfTeams >> startingTeam;
    //TODO: Create teams in node
    for (int i = 0; i < numOfTeams; i+=2)
    {
        insert(head, i);
        insert(head, i+1);
    }
    //TODO: Mix teams by one
    
    cout << "Enter direction ( 1 | 0 ):\n ";
    cin >> direction;
    cout<<"Enter number of operations:\n";
    cin >> operations;
    team = new int[numOfTeams];
    for(int i = 0; i < operations; i++){
        cin >> move;
        switch(move){
            case 0:
                index += move;
                // printInOrder();
                break;
            case 1:
                //TODO
                switch(flag){
                    case 0:
                        //TODO
                    break;
                    case 1:
                        //TODO
                    break;
                }
            break;
            case 2:
                //Direction change
                index += move;
                if(direction == 0){
                    direction = 1;
            break;
        }
    }
}