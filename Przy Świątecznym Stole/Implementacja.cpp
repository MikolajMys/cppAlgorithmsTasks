#include <iostream>
#include <string>
#include <vector>


struct scran
{
    int kcal, kcalHigh, kcalLow;
    std::string name;

//    scran(){
//        this->name = "";
//        this->kcal = 0;
//        this->kcalHigh = 0;
//        this->kcalLow = 0;
//    }

//    scran(std::string name, int kcal, int kcalHigh, int kcalLow){
//        this->name = name;
//        this->kcal = kcal;
//        this->kcalHigh = kcalHigh;
//        this->kcalLow = kcalLow;
//    }
};

std::vector<scran> radixCoutnSort(int n, std::vector<scran>& input, char relay) {
    std::vector<scran> output(n);
    std::vector<int> count(n, 0);

    if(relay == 0){
        for(int i = 0; i < n; i++){
            count[input[i].kcalLow]++;
        }
        //break;
    }else{
        for(int i = 0; i < n; i++){
            count[input[i].kcalHigh]++;
        }
        //break;
    }

//    std::cout << "Count array:\n";
//    for(int i = 0; i < n; i++){
//        std::cout << count[i] << " ";
//    }
//    std::cout << '\n';

    for(int i = 0; i < n-1; i++){
        count[i + 1] += count[i];
    }

//    std::cout << "\nCount array sum:\n";
//    for(int i = 0; i < n; i++){
//        std::cout << count[i] << " ";
//    }
//    std::cout << '\n';

    for(int i = n - 1; i >= 0; i--){
        if(relay == 0){
            output[count[input[i].kcalLow] - 1] = input[i];
            count[input[i].kcalLow]--;
            //break;
        }else{
            output[count[input[i].kcalHigh] - 1] = input[i];
            count[input[i].kcalHigh]--;
            //break;
        }
    }

    return output;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, kcal;
    std::string name;
    std::cin >> n;
    std::vector<scran> scrans(n);

    for(int i = 0; i < n; ++i){
        std::cin >> name >> kcal;
        //scrans.push_back(scran(name, kcal, kcal/n, kcal%n));
        scrans[i].name = name;
        scrans[i].kcal = kcal;
        scrans[i].kcalHigh = kcal/n;
        scrans[i].kcalLow = kcal%n;
    }

    std::vector<scran> output(n);
    std::vector<int> count(n, 0);

    for(int i = 0; i < n; i++){
        count[scrans[i].kcalLow]++;
    }

    for(int i = 0; i < n-1; i++){
        count[i+1] += count[i];
    }

    for(int i = n - 1; i >= 0; i--){
        output[count[scrans[i].kcalLow] - 1]
            = scrans[i];

        count[scrans[i].kcalLow]--;
    }

    scrans = output;

    for(int i = 0; i < n; i++){
        count[i] = 0;
    }

    for(int i = 0; i < n; i++){
        count[scrans[i].kcalHigh]++;
    }

    for(int i = 0; i < n-1; i++){
        count[i+1] += count[i];
    }

    for(int i = n - 1; i >= 0; i--){
        output[count[scrans[i].kcalHigh] - 1]
            = scrans[i];

        count[scrans[i].kcalHigh]--;
    }

    for(int i = 0; i < n; ++i){
        std::cout << output[i].name << " ";
    }

    return 0;
}