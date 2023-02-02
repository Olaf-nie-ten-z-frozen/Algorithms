#include <iostream>

class Node{
public:
    int name;
    int priority;
    Node(int name, int priority){
        this->name = name;
        this->priority = priority;
    }
    Node(){
        name = NULL;
        priority = NULL;
    }
};
void swap(int &a, int &b){
    int c = 0;
    a = c;
    a = b;
    b = c;
}
void swap(Node &node1, Node &node2){
    Node temp =  node1;
    node1 = node2;
    node2 = temp;
}
class HeapMax{
public:
    int size = 0;
    int parent(int i){
        return i/2;
    }
    int left_child(int i){
        return i*2;
    }
    int right_child(int i){
        return i*2+1;
    }
    void heapIt(Node *tab, int i, int size) {
        int l = i;
        if (left_child(i) < size && tab[left_child(i)].priority > tab[l].priority) {
            l = left_child(i);
        }
        if (right_child(i) < size && tab[right_child(i)].priority > tab[l].priority) {
            l = right_child(i);
        }
        if (l != i) {
            swap(tab[i], tab[l]);
            heapIt(tab, l, size);
        }
    }

    int pop(Node *tab, int &size) {
        if(size < 1){
            return NULL;
        }
        int v = tab[size - 1].name;
        std::cout<<v<<"\n";
        tab[0] = tab[size - 1];
        size--;
        int i = 0;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        while (left < size) {
            int minIndex = i;
            if (tab[left].priority < tab[minIndex].priority)
                minIndex = left;
            if (right < size && tab[right].priority < tab[minIndex].priority)
                minIndex = right;
            if (minIndex == i)
                break;
            swap(tab[i], tab[minIndex]);
            i = minIndex;
            left = 2 * i + 1;
            right = 2 * i + 2;
        }
        return v;
    }
    void pop(Node* tab, int &size, int val){
        if(size < 1){
            return;
        }
        int i; //potrzeba inicjalizacji aby można było przechować wartośc indexu poza pętlą
        for(i = 0; i < size; i++){
            if(tab[i].name == val){
                break;//znalezlismy nasz index
            }
        }
        swap(tab[i], tab[size - 1]);
        size--;
        heapIt(tab, i, size);//ponownie musimy posortować dane drzewo
    }
};
class HeapMin{
public:
    int parent(int i){
        return i/2;
    }
    int left_child(int i){
        return i*2;
    }
    int right_child(int i){
        return i*2+1;
    }
    void heapIt(Node *tab, int i, int size) {
        int l = i;
        if (left_child(i) < size && tab[left_child(i)].priority < tab[l].priority) {
            l = left_child(i);
        }
        if (right_child(i) < size && tab[right_child(i)].priority < tab[l].priority) {
            l = right_child(i);
        }
        if (l != i) {
            std::swap(tab[i], tab[l]);
            heapIt(tab, l, size);
        }
    }
    int pop(Node *tab, int &size) {
        if(size < 1){
            return NULL;
        }
        int v = tab[size - 1].name;
        std::cout<<v<<"\n";
        tab[0] = tab[size - 1];
        size--;
        int i = 0;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        while (left < size) {
            int minIndex = i;
            if (tab[left].priority < tab[minIndex].priority)
                minIndex = left;
            if (right < size && tab[right].priority < tab[minIndex].priority)
                minIndex = right;
            if (minIndex == i)
                break;
            swap(tab[i], tab[minIndex]);
            i = minIndex;
            left = 2 * i + 1;
            right = 2 * i + 2;
        }
        return v;
    }
    void pop(Node* tab, int &size, int val){
        if(size < 1){
            return;
        }
        int i; //potrzeba inicjalizacji aby można było przechować wartośc indexu poza pętlą
        for(i = 0; i < size; i++){
            if(tab[i].name == val){
                break;//znalezlismy nasz index
            }
        }
        swap(tab[i], tab[size - 1]);
        size--;
        heapIt(tab, i, size);//ponownie musimy posortować dane drzewo
    }
};
int main(){
    int n,m;
    int option;
    int name, priority;
    int counter = 1;
    int size = 0;
    int value = 0;
    std::cin>>n;
    Node* tabMax = new Node[counter];
    Node* tabMin = new Node[counter];
    for (int i = 0; i < n; i++)
    {
        HeapMin heapMin;
        HeapMax heapMax;
        std::cin>>m;
        for(int j = 0; j < m; j++){
            std::cin >> option;
            switch (option){
                case 0:
                    size++;
                    std::cin>>name>>priority;
                    if(size == counter){
                        counter*=2;
                        Node* temp1 = new Node[counter];
                        Node* temp2 = new Node[counter];
                        temp1 = tabMin;
                        temp2 = tabMax;
                        delete[] tabMax;
                        delete[] tabMin;
                        tabMin = temp1;
                        tabMax = temp2;
                    }
                    tabMax[i] = Node(name, priority);
                    tabMin[i] = Node(name,priority);
                    heapMin.heapIt(tabMin, i, size);
                    heapMax.heapIt(tabMax, i, size);
                    break;
                case 1:
                    value = heapMax.pop(tabMax, size); //biggest priority delete
                    heapMin.pop(tabMin, size, value);
                    break;
                case 2:
                    value = heapMin.pop(tabMin, size); //smallest priority delete
                    heapMax.pop(tabMax, size, value);
                default:
                    std::cout<<"No data...\n";
                    return 0;
            }
        }
    }
    return 0;
}
