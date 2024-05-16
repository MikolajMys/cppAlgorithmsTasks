#include <iostream>
#include <algorithm>

using namespace std;

int compare(int a, int b){
    if(a > b) return 1;
    return 0;
}

void print(int* arr, int size){
//    cout << "Unsorted: ";
//    for (int i = 0; i < size; ++i) {
//        cout << arr[i] << " ";
//    }
//    cout << '\n';

//    sort(arr, arr + size, compare/*greater<int>()*/);

//    cout << "  Sorted: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

void funct(int* products, int size_s, int size_e, int first, int k, int& count){
    if(first == k){
        count++;
        //cout << "1.if " << first << '\n';
        return;
    }
//    if (first > k || size_s >= size_e) {
//        return;
//    }
//    if(first + products[i] == k){
//        count++;
//        cout << "2.if " << first << "+" << products[i] << "=" << first + products[i] << '\n';
//        break;
//    }

//    //cout << "cos2:" << i << '\n';
//    if(first + products[i] > k){
//        cout << "4.if " << first << "+" << products[i] << "=" << first + products[i] << '\n';
//    }
    for(int i = size_s; i < size_e; ++i){
        if(first + products[i] <= k){
            //cout << "3.if " << first << "+" << products[i] << "=" << first + products[i] << '\n';
            funct(products, i + 1, size_e, first + products[i], k, count);
            //cout << "cos:" << i << '\n';
        }
    }
}

int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t, n, k;

    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> n;
        int products[n], count = 0;
        for(int j = 0; j < n; ++j){
            cin >> products[j];
        }
        cin >> k;
        //print(arr, n);
        sort(products, products + n, compare/*greater<int>()*/);
        //print(products, n);
        for(int j = 0; j < n; ++j){
            funct(products, j + 1, n, products[j], k, count);
        }
        cout << count << '\n';
    }

    return 0;
}