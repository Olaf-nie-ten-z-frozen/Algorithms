#include<iostream>

using namespace std;


class LinkedList{
    public:
        int data;
        LinkedList *next;
        LinkedList(int data){
            this->data = data;
            this->next = NULL;
        }
};

int main(){
    int n,m;
    string all_vil, wanted_vil, starting_vil,vil;
    cout<<"Enter the number of villages and chosen villages: ";
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>all_vil;
    }
    do{
    }while(vil==null);
    cin>>starting_vil;
    for(int i=0;i<m;i++){
        cin>>wanted_vil;
    }
    return 0;
}