#include <iostream>
#include <string>


void insertSort(std::string names[], long int times[], long int n) {
    for(int i = 1; i < n; ++i) {
        std::string name = names[i];
        long int time = times[i];
        long int j = i - 1;
        while((j >= 0 && times[j] < time)||(times[j] == time && names[j] > name)){
            times[j + 1] = times[j];
            names[j + 1] = names[j];
            --j;
        }
        times[j + 1] = time;
        names[j + 1] = name;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    std::cin >> t;

    for(int i = 0; i < t; ++i) {
        long int n, p, res = 0;
        std::cin >> n >> p;

        std::string names[n];
        long int times[n];

        for(int j = 0; j < n; ++j) {
            std::cin >> names[j] >> times[j];
        }

        insertSort(names, times, n);

        for(int j = 0; j < n; ++j){
            res += (times[j] * j) + 1;
        }

        for(int j = 0; j < p; ++j) {
            std::cout << names[j] << ' ';
        }
        std::cout << '\n' << res % 1000003 << '\n';
    }

    return 0;
}