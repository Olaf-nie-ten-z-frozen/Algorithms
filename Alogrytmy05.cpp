#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<algorithm>


class Graph{
    bool* visited; //visited list
    bool* is_wanted;
    std::map <std::string, int > graph; //graph
    std::vector<int>* neighbours;
    public:
        explicit Graph(int num){
            visited = new bool[num];
            is_wanted = new bool[num];

            for(int i = 0; i < num; i++) {
                visited[i] = false;
                is_wanted[i] = false;
            }
            neighbours = new std::vector<int>[num];//delete that
        }
        void addVertex(int num, std::string top){
            graph[top] = num;
            //std::cout<<"Dodano wierzchołek: "<<top<<" | "<<num <<"\n";
        }
        void addEdge(std::string vil1, std::string vil2){
                neighbours[graph[vil1]].push_back(graph[vil2]);
                neighbours[graph[vil2]].push_back(graph[vil1]);
        }
        void BFS(std::string start, int n){
            std::list<int> queue;
            int cur;
            int* dist = new int [n];

            int max_dist = 0;
            for (int i = 0; i < n; i++) {
                dist[i] = 0;
            }
            visited[graph[start]] = true;

            cur = graph[start];
            queue.push_back(cur);
            while(!queue.empty()){
                cur = queue.front();
                queue.pop_front();
                for (int i = 0; i < neighbours[cur].size(); i++) {
                    if (!visited[neighbours[cur][i]]) { //if not visited
                        visited[neighbours[cur][i]] = true; //mark as visited
                        queue.push_back(neighbours[cur][i]);
                        dist[neighbours[cur][i]] = dist[cur] + 1;
                        if(is_wanted[neighbours[cur][i]]) {
                            max_dist = std::max(dist[neighbours[cur][i]], max_dist);
                        }
                    }
                }
            }
        std::cout<<max_dist;
        }
    void is_wanted_vil(std::string vil){
            is_wanted[graph[vil]] = true;
        }
};

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int n,m;
    std::string all_vil, starting_vil,vil1,vil2;
    //std::cout<<"Enter the number of villages and chosen villages: ";
    std::cin >> n >> m;
    std::string* tab = new std::string [n];
    Graph graph(n);
    std::vector <std::string> wanted_vil;
    for(int i=0;i<n;i++){
        std::cin>>tab[i];
        graph.addVertex(i, tab[i]);
    }
    //std::cout<<"Enter the number of roads: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> vil1;
        while(vil1 != "X"){
        if(vil1 != "X"){
            graph.addEdge(vil1, tab[i]);
        }
        std::cin >> vil1;
        }
    }
    //std::cout<<"Enter the starting village: ";
    std::cin>>starting_vil;
    for (int i = 0; i < m; i++)
    {
        std::cin>>all_vil;
        graph.is_wanted_vil(all_vil);
    }
    graph.BFS(starting_vil, n);
    return 0;
}
