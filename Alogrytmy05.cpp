#include<iostream>

using namespace std;


class Graph{
    public:
    int heads;
    vector<list<string>> adj;
    Graph(int n){
        this->heads = heads;
        adj.resize(n);
    }
    void addEdge(string a, string b){
        adj[a].push_back(b);
    }
    void sort(int start){
        int counter = 0;
        vector<bool> visited;
        visited.resize(heads, false);
        list<string> queue;
        visited[start] = true;
        queue.push_back(start);

        while(!queue.empty()){
            s = queue.front();
            counter++;
            queue.pop_front();
        
        for (auto adjecent: adj[start])
        {
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
        }
        cout<<counter;
    }
};

int main(){
    int n,m;
    string all_vil, wanted_vil, starting_vil,vil1,vil2;
    cout<<"Enter the number of villages and chosen villages: ";
    cin>>n>>m;
    Graph graph(n);
    for(int i=0;i<n;i++){
        cin>>all_vil;
    }
    for (int i = 0; i < n; i++)
    {
        cin>> vil1;
        while(vil2 != "X"){
        cin >> vil2;
        graph.addEdge(vil1, vil2);
    } 
    }
    cin>>starting_vil;
    for(int i=0;i<m;i++){
        cin>>wanted_vil;
    }
    return 0;
}