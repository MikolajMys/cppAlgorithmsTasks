#include <iostream>
#include <string>

struct Student{
    std::string id;
    double s;
    int d;
    int m;
    Student(){
        id = "";
        s = 0.0;
        d = 0;
        m = 0;
    }
    Student(std::string id, double s, int d, int m){
        this->id = id;
        this->s = s;
        this->d = d;
        this->m = m;
    }
};


void insertSortSdm(Student student[], int n, char entry) {
    if(entry == 'd'){
        for(int i = 1; i < n; ++i) {
            Student key = student[i];
            int j = i - 1;

            while((j >= 0 && student[j].s < key.s) || (student[j].s == key.s  && student[j].d < key.d) || (student[j].s == key.s && student[j].d == key.d && student[j].m < key.m)){
                student[j + 1] = student[j];
                j = j - 1;
            }
            student[j + 1] = key;
        }
    } else{
        for(int i = 1; i < n; ++i) {
            Student key = student[i];
            int j = i - 1;

            while((j >= 0 && student[j].s < key.s) || (student[j].s == key.s  && student[j].m < key.m) || (student[j].s == key.s && student[j].m == key.m && student[j].d < key.d)){
                student[j + 1] = student[j];
                j = j - 1;
            }
            student[j + 1] = key;
        }
    }
}

//void insertSortSmd(Student student[], int n) {
//    for(int i = 1; i < n; ++i) {
//        Student key = student[i];
//        int j = i - 1;

//        while((j >= 0 && student[j].s < key.s) || (student[j].s == key.s  && student[j].m < key.m) || (student[j].s == key.s && student[j].m == key.m && student[j].d < key.d)){
//            student[j + 1] = student[j];
//            j = j - 1;
//        }
//        student[j + 1] = key;
//    }
//}

void insertSortDms(Student student[], int n, char entry) {
    if(entry == 'm'){
        for(int i = 1; i < n; ++i) {
            Student key = student[i];
            int j = i - 1;

            while((j >= 0 && student[j].d < key.d) || (student[j].d == key.d  && student[j].m < key.m) || (student[j].d == key.d && student[j].m == key.m && student[j].s < key.s)){
                student[j + 1] = student[j];
                j = j - 1;
            }
            student[j + 1] = key;
        }
    } else{
        for(int i = 1; i < n; ++i) {
            Student key = student[i];
            int j = i - 1;

            while((j >= 0 && student[j].d < key.d) || (student[j].d == key.d  && student[j].s < key.s) || (student[j].d == key.d && student[j].s == key.s && student[j].m < key.m)){
                student[j + 1] = student[j];
                j = j - 1;
            }
            student[j + 1] = key;
        }
    }
}

//void insertSortDsm(Student student[], int n) {
//    for(int i = 1; i < n; ++i) {
//        Student key = student[i];
//        int j = i - 1;

//        while((j >= 0 && student[j].d < key.d) || (student[j].d == key.d  && student[j].s < key.s) || (student[j].d == key.d && student[j].s == key.s && student[j].m < key.m)){
//            student[j + 1] = student[j];
//            j = j - 1;
//        }
//        student[j + 1] = key;
//    }
//}

void insertSortMsd(Student student[], int n, char entry) {
    if(entry == 's'){
        for(int i = 1; i < n; ++i) {
            Student key = student[i];
            int j = i - 1;

            while((j >= 0 && student[j].m < key.m) || (student[j].m == key.m  && student[j].s < key.s) || (student[j].m == key.m && student[j].s == key.s && student[j].d < key.d)){
                student[j + 1] = student[j];
                j = j - 1;
            }
            student[j + 1] = key;
        }
    } else{
        for(int i = 1; i < n; ++i) {
            Student key = student[i];
            int j = i - 1;

            while((j >= 0 && student[j].m < key.m) || (student[j].m == key.m  && student[j].d < key.d) || (student[j].m == key.m && student[j].d == key.d && student[j].s < key.s)){
                student[j + 1] = student[j];
                j = j - 1;
            }
            student[j + 1] = key;
        }
    }
}

//void insertSortMds(Student student[], int n) {
//    for(int i = 1; i < n; ++i) {
//        Student key = student[i];
//        int j = i - 1;

//        while((j >= 0 && student[j].m < key.m) || (student[j].m == key.m  && student[j].d < key.d) || (student[j].m == key.m && student[j].d == key.d && student[j].s < key.s)){
//            student[j + 1] = student[j];
//            j = j - 1;
//        }
//        student[j + 1] = key;
//    }
//}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    long int n;
    char entry[3];
    std::cin >> n;
//    std::cin.ignore();
//    getline(std::cin, entry);
    for(int i = 0; i < 3; ++i) {
        std::cin >> entry[i];
    }
    //std::cout << entry;
    Student girls[n];
    Student boys[n];

    for (int i = 0; i < n; ++i) {
        std::string id;
        double s;
        int d, m;
        std::cin >> id >> s >> d >> m;
        girls[i] = Student(id, s, d, m);

        std::cin >> id >> s >> d >> m;
        boys[i] = Student(id, s, d, m);
    }

    if(entry[0] == 's'){
        insertSortSdm(girls, n, entry[1]);
        insertSortSdm(boys, n, entry[1]);
    }
//    else if(entry == "s m d"){
//        insertSortSmd(girls, n);
//        insertSortSmd(boys, n);
//    }
    else if(entry[0] == 'd'){
        insertSortDms(girls, n, entry[1]);
        insertSortDms(boys, n, entry[1]);
    }
//    else if(entry == "d s m"){
//        insertSortDsm(girls, n);
//        insertSortDsm(boys, n);
//    }
    else if(entry[0] == 'm'){
//        std::cout << entry[0] << entry[1] << entry[2] << '\n';
        insertSortMsd(girls, n, entry[1]);
        insertSortMsd(boys, n, entry[1]);
    }
//    else if(entry == "m d s"){
//        insertSortMds(girls, n);
//        insertSortMds(boys, n);
//    }
    for (int i = 0; i < n; ++i) {
        std::cout << girls[i].id << ' ' <<boys[i].id << ' ';
    }

    return 0;
}