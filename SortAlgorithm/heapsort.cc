#include <iostream>
using namespace std;

void sort(int* a, int n, int i){
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

void heapbiuld(int* a, int n){//大顶堆的建立
    int len = n/2 - 1;
    for(int i = len; i>=0; i--){
        sort(a, n, i);
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
    heapbiuld(a,5);
    display(a,5);
}