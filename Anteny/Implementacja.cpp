#include <iostream>
#include <cmath>

//double P(int i, int j){
//    return 30 - sqrt(pow(i - 5, 2) + pow(j - 5, 2));
//}
int findMiddle(int up, int down){
    return (up + down) / 2;
}
double findMax(int n, int m, int up, int down){
    if(n == 1 && m == 1){
        return P(0, 0);
    }

    int middle = findMiddle(up, down);
    //std::cout << middle << '\n';
    double maxWartosc = 0;
    int maxRow = 0;
    //int maxCol = middle;
    //std::cout << maxWartosc << '\n';

    for(int i = 0; i < m; ++i){
        double wartosc = P(middle, i);
        if(wartosc > maxWartosc){
            maxWartosc = wartosc;
            maxRow = i;
        }
    }
    //std::cout << "max kordy:" << maxRow << middle << '\n';
    if(down == 1){
        return maxWartosc;
    }
    double maxUp = 0, maxDown = 0;
    if(middle > 0){
        maxUp = P(middle - 1, maxRow);
        if(maxUp >= maxWartosc){
            return findMax(n, m, up, middle);
        }
    }
    if(middle + 1 < down){
        maxDown = P(middle + 1, maxRow);
        if(maxDown >= maxWartosc){
            return findMax(n, m, middle, down);
        }
    }
    return maxWartosc;
}



int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n , m, up, down;
    std::cin >> n >> m;
//    for(int i = 0; i < n; ++i){
//        for(int j = 0; j < m; ++j){
//            std::cout << P(i, j) << ' ';
//        }
//        std::cout << '\n';
//    }
//    std::cout << '\n';
    up = 0;
    down = n;
    double max = findMax(n, m, up, down);
    std::cout << (int)floor(max) << '\n';
    return 0;
}