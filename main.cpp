#include <iostream>
#include "setentiers.h"
#include "matrices.h"
using namespace std;



int main(){
    matrice a(3,3),b(3,3),mult(3,3);
    a.afficher();
    cout<<endl;
    b.afficher();
    cout<<endl;
    mult=multiplication(a,b);
    mult.afficher();
    return 0;

}
