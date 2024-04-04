#include <iostream>
#include <queue>


int rows[] = {-1, 0, 1, 0};
int columns[] = {0, 1, 0, -1};


struct Cell{
    int x, y, distance, monitors;
};
//struct CellCompare{
//    bool operator()(Cell, Cell){
//        return true;
//    }
//};
struct Compare{
    bool operator()(Cell c1, Cell c2){
        if(c1.distance != c2.distance){
            return c1.distance > c2.distance;
        } else{
            return c1.monitors > c2.monitors;
        }
    }
};

bool isValid(char** board, bool** visited, int row, int col, int n, int m){
    if(row < 0 || col < 0 || row >= n || col >= m){
        return false;
    }
    if(board[row][col] == '#' || visited[row][col]){
        return false;
    }
    return true;
}

void BFS(char** board, int n, int m){
    int startX = -1, startY = -1, endX = -1, endY = -1;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(board[i][j] == 'S'){
                startX = i;
                startY = j;
            } else if(board[i][j] == 'X'){
                endX = i;
                endY = j;
            }
        }
    }

    bool** visited = new bool*[n];
    for(int i = 0; i < n; ++i){
        visited[i] = new bool[m];
    }
    for(int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            visited[i][j] = false;
        }
    }

//    std::queue<Cell> queue;
    std::priority_queue<Cell, std::vector<Cell>, Compare> queue;
    queue.push({startX, startY, 0, 0});
    visited[startX][startY] = true;

    while(!queue.empty()){
        Cell current = queue.top();
        int x = current.x;
        int y = current.y;
        int dist = current.distance;
        int monitors = current.monitors;
        queue.pop();

        if(x == endX && y == endY){
            std::cout << dist << ' ' << monitors << '\n';
            return;
        }

        for(int i = 0; i < 4; ++i){
            int newX = x + rows[i];
            int newY = y + columns[i];

            if(isValid(board, visited, newX, newY, n, m)){
                int newMonitors;
                if(board[newX][newY] == 'M'){
                    newMonitors = monitors + 1;
                } else{
                    newMonitors = monitors;
                }
                queue.push({newX, newY, dist + 1, newMonitors});
                visited[newX][newY] = true;
            }
        }
    }
//    for(int i = 0; i < m; ++i){
//        delete[] visited[i];
//    }
//    delete[] visited;
//    std::cout << "Issue!" << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;

    char** board = new char*[n];
    for(int i = 0; i < n; ++i){
        board[i] = new char[m];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            std::cin >> board[i][j];
        }
    }

    BFS(board, n, m);
//    for(int i = 0; i < m; ++i){
//        delete[] board[i];
//    }
//    delete[] board;
    return 0;
}