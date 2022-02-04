#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <conio.h>
#define N 30
#define M 21
using namespace std;
int main( )
{
    int a[N][N], s[N], t[N], c[N], n, m, cost, i, j, k, n1, n2, start, costm;
    ifstream fin("AdamPrim.txt");
    char local[N][M], *loc;
    cout<<"Algoritmul lui prim.\n";
    fin>>n >> m;
    cout<<"numarul virfurilor: " << n << ". numarul muchiilor: " << m << endl;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            a[i][j] = 999;
        a[i][i]=0;
    }
    for(k=1; k<=m; k++)
    {
        fin >> i >> j >> cost;
        a[i][j] = a[j][i] = cost;
    }
    for(k=1; k<=m; k++)
    {
        fin >> loc;
        strcpy(local[k], loc);
    }
cout << "matricia costului a traseilor\n";
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout<<"ramurile cu costul minim" << endl;
    for(i=1; i<=n; i++)
        s[i]=t[i]=c[i]=0;
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
        cout << "drumul de la" << local[t[i]] << " pina " << local[i] << " cu lungimea " << a[t[i]][i] << " km." << endl;
    cost=0;
    for(i=1; i<=n; i++)
       cost+=c[i];

    cout<<"costul minim " << cost;
    fin.close();
    getch();
}
