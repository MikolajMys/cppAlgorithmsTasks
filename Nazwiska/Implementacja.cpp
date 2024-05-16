#include <iostream>


void findLastChild(int i, std::string* parents, int* nums)
{
    std::string  parentName, temp(12, ' ');

    for(int j = 0; j < 4; ++j){
        parentName = parents[nums[j] % 1500];
        //cout << parentName << '\n';
        //temp += parentName.substr(j * 3, 3);
        temp[j * 3] = parentName[j * 3];
        temp[j * 3 + 1] = parentName[j * 3 + 1];
        temp[j * 3 + 2] = parentName[j * 3 + 2];
    }
    //cout << temp << '\n';
    parents[i % 1500] = temp;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m, nums[4];
    std::string parents[1500];

    std::cin >> n >> m;

    for(int i = 0; i < m; ++i){
        std::cin >> parents[i];
    }

    for(int i = m; i < n; ++i){
        for (int j = 0; j < 4; ++j) {
            std::cin >> nums[j];
        }
        findLastChild(i, parents, nums);
    }
    std::cout << parents[(n - 1) % 1500];

    return 0;
}