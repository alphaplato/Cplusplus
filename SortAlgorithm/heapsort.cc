#include <iostream>
using namespace std;

void sort(int* a, int n, int i){//堆调整
    int temp;
    while(2*i + 1 < n){
        if(2*i + 2 < n){
            if(a[2*i+1] > a[2*i+2]){
                if(a[i] >= a[2*i+1]){
                    break;   
                }
                temp = a[i];
                a[i] = a[2*i+1];
                a[2*i+1] = temp;
                i = 2*i + 1;
            }else{
                if(a[i] >= a[2*i+2]){
                   break; 
                }
                temp = a[i];
                a[i] = a[2*i+2];
                a[2*i+2] = temp;
                i = 2*i + 2;
            }
        }else{
            if(a[i] >= a[2*i+1]){
                break;
            }
            temp = a[i];
            a[i] = a[2*i+1];
            a[2*i+1] = temp;
            i = 2*i+1;
        }
    }
}

void heapBiuld(int* a, int n){//建堆
    int len = n/2 - 1;
    for(int i = len; i>=0; i--){
        sort(a, n, i);
    }
}

void heapDismantle(int* a, int n){
    for(int i=n-1; i>0; i--){
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapBiuld(a,i-1);
    }
}

void display(int* a, int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[] = {4,6,8,5,7};
    heapBiuld(a,5);
    heapDismantle(a,5);
    display(a,5);
}