#include<iostream>
using namespace std;

void sort(int* a, int first, int last, int mid){
    int* temp = new int[last - first + 1];
    int i = first;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= last){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }
    while(i <= mid){
        temp[k++] = a[i++];
    }
    while(j <= last){
        temp[k++] = a[j++];
    }
    for(int t=0; t < last - first + 1; t ++){
        a[first + t] = temp[t];
    }
    delete [] temp;
}

void mergesort(int* a, int first, int last){
    if(first >= last) return;
    int mid = (first + last)/2;
    mergesort(a, first, mid);
    mergesort(a, mid+1, last);
    sort(a, first, last, mid);
}

void diplay(int* a, int first, int last){
    for(; first <= last; first++){
        cout << a[first] << " ";
    }
    cout << endl;
}

int main(){
    int a[7] = {5,3,7,8,2,1,2};
    mergesort(a, 0 ,6);
    diplay(a, 0 ,6);
}