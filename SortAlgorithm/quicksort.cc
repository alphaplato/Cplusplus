#include<iostream>
using namespace std;

void quicksort(int* a, int left, int right){
    if(left >= right){
        return;
    } 
    int key = a[left];
    int first = left;
    int last = right;
    while(first < last){
        while(a[last] >= key && last > first){
            last --;
        }
        a[first] = a[last];
        while(a[first] <= key && first < last){
            first ++;
        }
        a[last] = a[first];
    }
    a[first] = key;
    quicksort(a, left, first-1);
    quicksort(a, first+1, right);
}

void display(int* a, int n){
    for(int i=0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[] = {9,3,2,4,7,5,4};
    quicksort(a,0,6);
    display(a,7);
}