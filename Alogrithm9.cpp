//Sortiwane przez zliczanie
//Potrzeba macierzy z listami imion i liczbami
#include<iostream>

using namespace std;

class Node(){
    public:
    string name;
    int kill;
    int traps;
    Node *next;
    Node(string name, int kill, int traps){
        this->name = name;
        this->kill = kill;
        this->traps = traps;
        this->next = NULL;
    }
    void add(string name, int kill, int traps){
        Node *temp = new Node(name, kill, traps);
        Node *temp2 = this;
        if()
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
};
void counting_sort(Node head[][]){
}
int main(){
    string name;
    int n, kill, traps;
    cin>>n;
    Node mac[9][99];
    for (int i = 0; i < n; i++)
    {
        getline(cin, name);
        cin>>kill>>traps;
        mac[kill][traps].add(name, kill, traps);
    }
    counting_sort(mac);

    return 0;
}