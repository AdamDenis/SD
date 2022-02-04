#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
int main( )
{
    int a[20][20],s[20],t[20],c[20],n,cost,i,j,k,n1,n2,start,costm;
    char local[20][20] = {"Eu", "Or.Drochia", "Nicoreni", "Baroncea", "Chetrosu", "S.Drochia", "Mindic", "Maramonovca", "Popestii_de_jos", "Dominteni", "Pelinia"};
    ifstream fin;
    fin.open("AdamPrim.txt");
    fin >> n;
    cout << "Numar de varfuri: " << n << endl;


    for(i=1; i<=n; i++)
        a[i][i] = 0;
    for(i=1; i<=n; i++)
        for(j=1; j<i; j++)
        {
            fin >> a[i][j];
            a[j][i] = a[i][j];
        }
    cout << "Matricea costurilor drumurilor" << endl;
    for(i=1; i<=n; i++)
    {
        cout << local[i] << " " ;
    }
    cout << endl;
    for(i=1; i<=n; i++)
    {

        for(j=1; j<=n; j++)
            cout <<  a[i][j] << " " ;
        cout << endl;
    }
//
    cout << "Arborele partial de cost minim: " << endl;
    for(i=1; i<=n; i++)
        s[i] = t[i] = c[i]=0;
    start=1;
    s[start]=1;
    for(k=1; k<=n-1; k++)
    {
        costm=32000;
        n1=-1;
        n2=-1;
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                if((s[i]==1) && (s[j]==0))
                    if(a[i][j]<costm)
                    {
                        costm=a[i][j];
                        n1=i;
                        n2=j;
                    }
        s[n2]=1;
        t[n2]=n1;
        c[n2]=a[n1][n2];
    }
    for(i=2; i<=n; i++)
        cout << local[t[i]] << " " << local[i]<< ". distanta " << a[t[i]][i] << " km."<< endl;
    cost=0;
    for(i=1; i<=n; i++)
        cost+=c[i];
    cout << "Distanta minima " << cost;
    getch();

}

