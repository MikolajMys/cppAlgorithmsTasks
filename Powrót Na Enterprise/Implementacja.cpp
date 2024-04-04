#include <iostream>
#include <vector>
#include <queue>
#include <limits>

struct Patch{
    int x, time;
    Patch(){
        x = 0;
        time = 0;
    }
    Patch(int x, int time){
        this->x = x;
        this->time = time;
    }
};

struct Ship{
    std::vector<Patch> patchs;
    std::vector<int> occupied;
    bool visited;
    Ship(){
        visited = false;
    }
};

struct Compare{
    bool operator()(Patch a, Patch b){
        return a.time > b.time;
    }
};

void dijkstra(std::vector<Ship>& ships, int start, int n){
    //int n = ships.size();
    std::vector<int> distance(n, std::numeric_limits<int>::max());

    std::priority_queue<Patch, std::vector<Patch>, Compare> pq;
    pq.push(Patch(start, 0 ));
    distance[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().x;
        pq.pop();
        //std::cout << u << '\n';
        if(!ships[u].visited){

            ships[u].visited = true;

            for(Patch patch : ships[u].patchs) {
                int v = patch.x;
                int t = patch.time;

                if(distance[u] + t < distance[v]){
                    distance[v] = distance[u] + t;
                    for(int i = 0; i < (int)ships[v].occupied.size(); ++i){
                        if(ships[v].occupied[i] == distance[v]){
                            distance[v]++;
                            i = -1;
                        }
                    }
                    pq.push(Patch(v, distance[v]));
                }
            }
        }
    }
    std::cout << distance[0] << '\n';
//    std::cout << "Odleglosci od zrodla:\n";
//    for (int i = 0; i < n; ++i) {
//        std::cout << "Statek " << i << ": " << distance[i] << '\n';
//    }
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int d, n, m, s;
    std::cin >> d;
    //std::cout << "Wartosc d: " << d << std::endl;
    for(int i = 0; i < d; ++i){
        std::cin >> n >> m >> s;
        //std::cout << "Wartosc n: " << n << ", wartosc m: " << m << ", wartosc s: " << s << std::endl;
        std::vector<Ship> ships(n);
        int x, y, t, k1, k2;
        for(int j = 0; j < m; ++j){
            std::cin >> x >> y >> t;
            //std::cout << "Wartosc x: " << x << ", wartosc y: " << y << ", wartosc t: " << t << std::endl;
            ships[x].patchs.push_back(Patch(y, t));
            ships[y].patchs.push_back(Patch(x, t));
        }
        for(int k = 0; k < n; ++k){
            std::cin >> k1;
            //std::cout << "Wartosc k1: " << k1 << std::endl;
            for(int l = 0; l < k1; ++l){
                std::cin >> k2;
                //std::cout << "Wartosc k2: " << k2 << std::endl;
                ships[k].occupied.push_back(k2);
            }
        }
        dijkstra(ships, s, n);
        //printGraph(ships);
    }
    return 0;
}