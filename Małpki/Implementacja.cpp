#include <iostream>
#include <queue>

struct Monke{
    char letter;
    short int number;
    Monke** arms;

    Monke(){
        letter = '\0';
        number = 0;
    }

    Monke(char letter, short int number){
        this->letter = letter;
        this->number = number;
        if(number == 0){
            arms = nullptr;
        } else{
            const int n = number;
            arms = new Monke*[n];
            for(int i = 0; i < n; ++i) {
                arms[i] = nullptr;
            }
        }
    }
};

struct MonkeTree{
    Monke* root;
    std::queue<Monke*> queue;
    int i = 0;
    MonkeTree(){
        root = nullptr;
    }

    void insert(char letter, short int number) {

        if(root == nullptr) {
            root = new Monke(letter, number);
            queue.push(root);
        } else{
            Monke* firstMonke = queue.front();
            if(firstMonke->arms[i] == nullptr) {
                firstMonke->arms[i] = new Monke(letter, number);
                if(firstMonke->arms[i]->number > 0) {
                    queue.push(firstMonke->arms[i]);
                }
                if(i + 1 == firstMonke->number) {
                    queue.pop();
                    i = -1;
                }
                i++;
            }
        }
    }

    void preorder(Monke* currentMonke) {
        if(currentMonke == nullptr) {
            return;
        }

        std::cout << currentMonke->letter;
        for(int i = 0; i < currentMonke->number; ++i) {
            preorder(currentMonke->arms[i]);

        }

    }
//    ~MonkeTree() {
//        destroyTree(root);
//    }

//    void destroyTree(Monke* currentMonke) {
//        if(currentMonke == nullptr) {
//            return;
//        }

//        for(int i = 0; i < currentMonke->number; ++i) {
//            destroyTree(currentMonke->arms[i]);
//        }

//        delete[] currentMonke->arms;
//        delete currentMonke;
//    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    long int k, n;
    std::cin >> k;
    for(int i = 0; i < k; ++i) {
        char letter;
        short int number;
        MonkeTree tree;
        std::cin >> n;
        for(int j = 0; j < n; ++j) {
            std::cin >> letter >> number;
            tree.insert(letter, number);
        }
        tree.preorder(tree.root);
        std::cout << '\n';
    }

    return 0;
}