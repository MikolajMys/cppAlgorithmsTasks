#include <iostream>
#include <string>

struct Actor {
    std::string name;
    long int popularity;
    Actor* next;

    Actor(std::string n, long int a){
        name = n;
        popularity = a;
        next = nullptr;
    }
};

class ActorList {
private:
    Actor* head;
    Actor* tail;
public:
    ActorList(){
        head = nullptr;
        tail = nullptr;
    }
    void addActor(std::string name, long int popularity){
        Actor* current = head;
        while(current){
            if(current->name == name && current->popularity == popularity){
                std::cout << "NIE" << '\n';
                return;
            }
            current = current->next;
        }

        Actor* newActor = new Actor(name, popularity);
        if(!head){
            head = newActor;
            tail = newActor;
            std::cout << "TAK" << '\n';
        } else{
            tail->next = newActor;
            tail = newActor;
            std::cout << "TAK" << '\n';
        }
    }
    void findActor(long int popularity){
        Actor* current = head;
        Actor* closest = nullptr;

        while(current){
            if(current->popularity <= popularity){
                if((!closest || current->popularity > closest->popularity) || (current->popularity == closest->popularity && current->name < closest->name)){
                    closest = current;
                }
            }
            current = current->next;
        }

        if(closest){
            deleteClosest(closest);
        } else{
            std::cout << "NIE" << '\n';
        }
    }

    void deleteClosest(Actor* closest) {
        Actor* current = head;
        Actor* previous = nullptr;
        std::cout << closest->name << '\n';
        if(closest == head){
            head = closest->next;
            if(closest == tail) {
                head = nullptr;
                tail = nullptr;
            }
            delete closest;
        } else{
            while(current){
                if(current->next == closest){
                    previous = current;
                    break;
                }
                current = current->next;
            }
            if(closest == tail){
                tail = previous;
            }
            previous->next = closest->next;
            delete closest;
        }
    }

//    void displayActors(){
//        Actor* current = head;
//        while (current){
//            std::cout << current->name << ' ' << current->popularity << std::endl;
//            current = current->next;
//        }
//    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    ActorList actorList;

    long int n, op;
    std::cin >> n;

    for(int i = 0; i < n; ++i) {
        std::cin >> op;
        if(op == 1){
            std::string name;
            long int popularity;
            //std::cin.ignore();
            getline(std::cin, name);
            getline(std::cin, name);
            std::cin >> popularity;

            actorList.addActor(name, popularity);
        }
        if(op == 2){
            long int popularity;
            std::cin >> popularity;

            actorList.findActor(popularity);
        }
    }

    //actorList.displayActors();

    return 0;
}