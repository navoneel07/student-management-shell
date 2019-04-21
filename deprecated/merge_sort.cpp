#include <iostream>
#include <vector>
#include <string>

using namespace std;

void merge(vector<pair<string, string> > students, int l, int m, int r){
    int i,j,k;
    int l1 = m-l+1;
    int l2 = r-m;

    vector<pair<string, string> > L(l1);
    vector<pair<string, string> > R(l2);

    for(i=0; i<l1; i++){
        L[i].first = students[l+i].first;
        L[i].second = students[l+i].second;
    }

    for(j=0;j<l2;j++){
        R[j].first = students[m+1+j].first;
        R[j].second = students[m+1+j].second;
    }

    i=0, j=0, k=l;

    while(i<l1 && j<l2){
        if(L[i].second <= R[j].second){
            students[k] = L[i];
            i++;
        }
        else{
            students[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<l1){
        students[k] = L[i];
        i++;
        k++;
    }

    while(j<l2){
        students[k] = R[j];
        j++;
        k++;
    }

}

void merge_sort(vector<pair<string, string> > students, int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        merge_sort(students, l, m);
        merge_sort(students, m+1, r);
        merge(students, l,m,r);
    }
}
