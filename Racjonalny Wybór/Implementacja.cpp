#include <cstring>
#include <string>
#include <iostream>
#include <cmath>


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    long n;
    std::cin >> n;

    long carScore[3];
    std::string carName[3], name;
    double p;
    long d;

    for(int i = 0; i < 3; ++i) {
        std::cin.ignore();
        getline(std::cin, carName[i]);
        std::cin >> p;
        std::cin >> d;

        carScore[i] = floor((p / (3.141593 * (d * 0.0000254))));
    }
    for(int i = 0; i < 3; ++i) {
        for(int j = i + 1; j < 3; ++j) {
            if(carScore[i] > carScore[j] || (carScore[i] == carScore[j] && carName[i] > carName[j])) {
                std::swap(carScore[i], carScore[j]);
                std::swap(carName[i], carName[j]);
            }
        }
    }
    for(int i = 0; i < n-3; ++i) {
        std::cin.ignore();
        getline(std::cin, name);
        std::cin >> p;
        std::cin >> d;
        double result = floor((p / (3.141593 * (d * 0.0000254))));

        for(int j = 0; j < 3; ++j) {
            if(result < carScore[j] || (result == carScore[j] && name < carName[j])) {
                for(int k = 2; k > j; --k) {
                    carName[k] = carName[k - 1];
                    carScore[k] = carScore[k - 1];
                }
                carName[j] = name;
                carScore[j] = result;
                break;
            }
        }
    }
    for(int i = 0; i < 3; ++i){
        std::cout << carName[i] << '\n' << (long)carScore[i] << '\n';
    }
}