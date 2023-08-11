#ifndef SETENTIERS_H_INCLUDED
#define SETENTIERS_H_INCLUDED
#include <iostream>
using namespace std;
class SetEntiers{
    int nbrelem;
    int* elements;
    int max;
public:
    SetEntiers(int);
    SetEntiers(int,int);
    SetEntiers(const SetEntiers &Z);
    ~SetEntiers();
    void afficher();
    double cardinal();
    void renverser();
    void ajouter(int);
    friend int somme(SetEntiers );
};



SetEntiers::SetEntiers(int m) {
    nbrelem=0;
    max=m;
    elements= new int [max];
}
SetEntiers::SetEntiers(int m,int a) {
    nbrelem=0;
    max=m;
    elements= new int [max];
    elements[nbrelem++]=a;
}

SetEntiers::SetEntiers(const SetEntiers &Z) {
    nbrelem=Z.nbrelem;
    elements =new int[nbrelem];
    for (int i = 0; i <nbrelem ; i++) {
        elements[i]=Z.elements[i];
    }
}
SetEntiers::~SetEntiers() {
    delete[] elements;
}
void SetEntiers::afficher() {
    for (int i = 0; i <nbrelem; i++) {
        cout<< "T["<<i<<"]= "<<elements[i]<<"\n";
    }
}
double SetEntiers::cardinal() {
    return nbrelem;
}
void SetEntiers::renverser() {
    for (int *p1=elements,*p2=elements+nbrelem-1; p1 < p2 ; p1++ ,p2--) {
        int a;
        a=*p1;
        *p1=*p2;
        *p2=a;
    }
}
void SetEntiers::ajouter(int a) {
    if(nbrelem<max){
        elements[nbrelem++]=a;
    }
}
int somme(SetEntiers e) {
    int sum = 0;
    for (int i = 0; i < e.nbrelem; i++) {
        sum += e.elements[i];
    }
    return sum;
}


#endif // SETENTIERS_H_INCLUDED
