#include <iostream>
#include <vector>
#include <algorithm>

struct X{
    int start, end;
    X(){
        start = 0;
        end = 0;
    }
    X(int start, int end){
        this->start = start;
        this->end = end;
    }
    bool operator<(const X& other){
        return end < other.end;
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    std::cin >> t;

    for(int i = 0; i < t; ++i){
        int n;
        std::cin >> n;

        std::vector<X> columns(n);

        for(int j = 0; j < n; ++j){
            int a, b;
            std::cin >> a >> b;
            columns[j] = X(a, b);
        }

        std::sort(columns.begin(), columns.end());

//        for(int j = 0; j < n; ++j){
//            std::cout << columns[j].start << columns[j].end << '\n';
//        }
        bool* visted = new bool[n]{};
//        for(int j = 0; j < n; ++j){
//            visted[j] = false;
//        }
        bool done = true;
        for(int j = 0; j < n; ++j){
           // X current = columns[n];
            //std::cout << columns[j].start << columns[j].end << '\n';
            int s = columns[j].start;
            int e = columns[j].end;
            while(true){
//                std::cout << k;
                if(!visted[s]){
                    visted[s] = true;
                    break;
                }
                if(s == e){
                    done = false;
                    break;
                }
                s++;
//                std::cout << current.start << current.end << '\n';
            }
//            if(!done){
//                break;
//            }
//            std::cout << '\n';
        }

        if(done){
            std::cout << "TAK" << '\n';
        } else {
            std::cout << "NIE" << '\n';
        }
        //delete[] visted;
    }
    return 0;
}