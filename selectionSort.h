#ifndef SELECTION_H
#define SELECTION_H

#include "header.h"
#include <vector>

using namespace std;

template <class T>
void selectionSort(vector<float> &v, vector<T> &v1, vector<T> &v2, vector<T> &v3, vector<T> &v4){
    int pos;
    for(int i = v.size()-1; i > 0; i--){
        pos = 0;
        for(int j = 1; j <= i; j++){
            if(v[j] > v[pos]){
                pos = j;
            }
        }

        if (pos != i){
            swap(v, i, pos);
            swap(v1, i, pos);
            swap(v2, i, pos);
            swap(v3, i, pos);
            swap(v4, i, pos);
        }
    }
}

#endif