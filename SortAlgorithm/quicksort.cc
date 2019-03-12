#include<iostream>
using namespace std;

void quickSort(int* a, int left, int right){
    if(left >= right){
        return;
    } 
    int key = a[left];
    /*首位left，right不能直接使用，因为（分半）递归
    时需要使用原始的首位位置。
    */
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
    quickSort(a, left, first-1);
    quickSort(a, first+1, right);
}

void display(int* a, int n){
    for(int i=0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[] = {9,3,2,4,7,5,4};
    quickSort(a,0,6);
    display(a,7);
}