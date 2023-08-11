#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED
class matrice{
    int i,j;
    double **M;
public :
    matrice();
    matrice(int,int);
    ~matrice();
    matrice(matrice &);
    double getelem(int ,int );
    void setelem(int ,int ,double );
    void afficher();
    void multiplication(matrice ,matrice &);
    friend matrice multiplication(matrice ,matrice );
};
matrice::matrice(matrice &e){
    i=e.i;
    j=e.j;
    for(int i=0;i<this->i;i++)
    for(int j=0;j<this->j;j++){
        M[i][j]=e.M[i][j];
    }
}
matrice::matrice(int n,int m){
    i=n;j=m;
    M=new double *[n];
    for(int i=0;i<n;i++){
        M[i]=new double[m];
    }
    for(int i=0;i<this->i;i++)
        for(int j=0;j<this->j;j++)
            M[i][j]=1;
}
using namespace std;
matrice::~matrice(){
    for(int k=0;k<j;k++)
        delete[] M[k];
    delete[] *M;
}
double matrice::getelem(int i,int j ){
    return M[i][j];
}
void matrice::setelem(int a ,int b ,double v ){
    M[a][b]=v;
}
void matrice::afficher( ){
    for(int i=0;i<this->i;i++){
        for(int j=0;j<this->j;j++)
            cout<<" "<<M[i][j];
        cout<<endl;
    }
}
void matrice::multiplication(matrice a ,matrice &b){
    if(j==a.i){
        for(int i=0;i<this->i;i++){
            for(int j=0;j<a.j;j++){
                b.M[i][j]=0;
                for(int k=0;k<this->j;k++)
                    b.M[i][j]+=M[i][k] * a.M[k][j];
            }
        }
    }
}
matrice multiplication(matrice a,matrice b){
    if(a.j==b.i){
        matrice tmp(a.j,b.i);
        for(int i=0;i<b.i;i++){
            for(int j=0;j<a.j;j++){
                tmp.M[i][j]=0;
                for(int k=0;k<b.j;k++)
                    tmp.M[i][j]+=a.M[i][k] * b.M[k][j];
            }
        }
        return tmp;
    }

}




#endif // MATRICES_H_INCLUDED
