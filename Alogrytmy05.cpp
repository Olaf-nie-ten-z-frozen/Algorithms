#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<algorithm>


class Graph{
    bool* visited; //visited list
    std::map <std::string, int > graph; //graph
       
    public:
        Graph(int num){
            visited = new bool[num];
            for(int i = 0; i < num; i++){
                visited[i] = false;
            }
        }
        void addVertex(int num, std::string top){
            graph[top] = num;
            std::cout<<"Dodano wierzchołek: "<<top<<" | "<<num <<"\n";
        }
        void addEdge(std::string vil1, std::string vil2){
            if(vil1 == vil2){
                std::cout<<"Nie można dodać krawędzi do samego siebie\n";
            }
            else if(graph.find(vil1) != graph.end() && graph.find(vil2) != graph.end()){
                std::cout<<"Dodano krawędź: "<<vil1<<" | "<<vil2<<"\n";
                neighbours[vil1].push_back(vil2);
                neighbours[vil2].push_back(vil1);
            }
            else{
                std::cout<<"Nie ma takiego wierzchołka\n";
            }
            
        }
        void BFS(std::string start, std::vector<std::string> wanted_vil, int n){
            std::list<std::string> queue;
            int dist[n];
            for (int i = 0; i < n; i++){
                dist[i] = 0;
            }
            
            int counter = 0;
            visited[graph[start]] = true;
            queue.push_back(start);

            while(!queue.empty()){
                start = queue.front();
                queue.pop_front();
                for (int i = 0; i < neighbours[start].size(); i++)
                {
                    if(!visited[graph[neighbours[start][i]]]){ //if not visited
                        visited[graph[neighbours[start][i]]] = true; //mark as visited
                        if (find(wanted_vil.begin(), wanted_vil.end(), neighbours[start][i]) != wanted_vil.end())//find if index is in wanted_vil
                        {   
                            int temp = find(wanted_vil.begin(), wanted_vil.end(), neighbours[start][i]) - wanted_vil.begin(); // find index of start in wanted_vil
                            wanted_vil.erase(wanted_vil.begin()+temp); // remove from vector 
                            if(wanted_vil.size() == 0){ //if all wanted villages are visited
                                std::cout<<"Znaleziono wszystkie wioski\n";
                                std::cout << counter;
                            }
                        }
                        queue.push_back(neighbours[start][i]);
                        dist[graph[neighbours[start][i]]] = dist[graph[start]] + 1;
                    } 
                }

            }
            for (int i = 0; i < n; i++)
            {
                std::cout<<dist[i]<<" ";
            }
            
        }
};

int main(){
    int n,m;
    std::string all_vil, starting_vil,vil1,vil2;
    std::cout<<"Enter the number of villages and chosen villages: ";
    std::cin >> n >> m;
    Graph graph(n);
    std::vector <std::string> wanted_vil;
    for(int i=0;i<n;i++){
        std::cin>>all_vil;
        graph.addVertex(i, all_vil);
    }
    std::cout<<"Enter the number of roads: ";
    for (int i = 0; i < n; i++)
    {
        vil2 = "";
        std::cin>> vil1;
        while(vil2 != "X"){
        std::cin >> vil2;
        if(vil2 != "X"){
            graph.addEdge(vil1, vil2);
        }
        }
    }
    //cout<<"Enter the starting village: ";
    std::cin>>starting_vil;
    for (int i = 0; i < m; i++)
    {
        std::cin>>all_vil;
        wanted_vil.push_back(all_vil);
    }
    graph.BFS(starting_vil, wanted_vil, n);
    return 0;
}
