#include <iostream>
using namespace std;
double Power (double a, int n)
{
    int i;
    double p= a;
    for (i=1; i<n; i++)
    {
        p *= a;
    }
    return p;
}
int main()
{
    double a = 5, b = 3, s, q, t;
    int n = 4, i;
    cout << "input 2 numbers: ";
    cin >> a >> b;
    cout << "input Power: ";
    cin >> n;
    cout <<"Proiect nr3. elaborat de Adam Denis" << endl;
    cout << "Tema: Binomul lui Newton pentru scadere \n";
    s = t = Power(a, n);
    cout << "t0 = " << t << endl;
    if (((a - b)==0) && (t == 0) )
    {
        s = 1;
        cout << "resultat (oo)\n";
    }
    else
    {
        for (i=1; i<=n; i++)
        {
            q = b*(n-i + 1)/(i*a);

            t = -t*q;
            s = s + t ;
            cout << "t" << i << " = " << t << endl;
        }
        cout << "resultat (" << a << " - " << b << ")^" << n << " = " << s ;
        cout << "\n Verify (" << a - b << ")^" << n << " = " << Power(a-b, n) ;
    }

}


