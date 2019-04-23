#include <iostream>

struct IntLtnode {
    IntLtnode(){
        pnext = nullptr;
    }
    int node;
    IntLtnode* pnext;
};

void Init(int* a, int size, IntLtnode* &head) { //链表的初始化
    if (size == 0) {
        std::cout << "No data initlize!" << std::endl;
        return;
    }
    head = new(IntLtnode);
    head->node = a[0];
    IntLtnode* pos = head; 
    for (int i=1; i<size; i++) {
        IntLtnode* temp = new(IntLtnode);
        temp -> node = a[i];
        pos->pnext = temp;
        pos = pos->pnext;
    }   
}

void display(IntLtnode* head){ //链表的输出
    if (head == nullptr) {
        std::cout << "No data!" << std::endl;
        return;
    }
    IntLtnode *plt;
    plt = head;
    while(plt){
        std::cout << plt->node << " ";
        plt = plt->pnext;
    }
    std::cout << std::endl;
}

void reverse(IntLtnode* &head) { //链表的颠倒逆向
    if (head == nullptr) {
        std::cout << "No data!" << std::endl;
    }
    IntLtnode* preptr = nullptr;
    IntLtnode* midptr = head;
    IntLtnode* nextptr;
    while (midptr) {
        nextptr = midptr->pnext;
        midptr->pnext = preptr;
        preptr = midptr;
        midptr = nextptr;
    }
    head = preptr;
}

int main(){
    int a[] = {1,2,3,4,5};
    IntLtnode* intlt;
    Init(a, 5, intlt);
    std::cout << "initlize the list:";
    display(intlt);

    reverse(intlt);
    std::cout << "reverse the list:";
    display(intlt);
}
