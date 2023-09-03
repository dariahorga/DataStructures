#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void BubbleSort( int v[],int n)
{
    int i,j;
    bool swapped;
    for(i=0;i<n-1;i++)
    {
        swapped=false;
        for (j=0;j<n-i-1;j++)
            if(v[j]>v[j+1])
            {   int aux;
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                swapped=true;
            }

        if(swapped==false)
            break;
    }
}


void InsertionSort( int v[],int n)
{
    int i,j,key;
    for(i=1;i < n; i++)
    {
        key=v[i];
        j=i-1;
        while(j>=0 && v[j]>key)
        {
            v[j+1]=v[j];
            j=j-1;
        }
        v[j+1]=key;
    }
}


void SelectionSort(int v[], int n)
{
    int i,j,m;

    for(i=0;i<n-1;i++)
    {
        m=i;
        for(j=i+1;j<n;j++)
        {
            if(v[j]<v[m])
                m=j;
        }
    if(m!=i)
      {
        int aux;
        aux=v[m];
        v[m]=v[i];
        v[i]=aux;
      }

    }
}
int main()
{
    clock_t time;
    time=clock();

    ofstream f("fisier.txt");
    int i=0;
    int n,value;
    cin>>n;
    int v[n];
    while(i<n)
    {
        value=rand();
        f<<value<<" ";
        i=i+1;
    }
    f.close();

    ifstream g("fisier.txt");
    i=0;
    int x;
    while(i<n)
    {
        g>>x;
        v[i]=x;
        i=i+1;
    }
    g.close();

    //BubbleSort(v,n);
    //InsertionSort(v,n);
    SelectionSort(v,n);

    for(i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    time=clock()-time;
    cout<<endl<< "timp " << ((float)time)/CLOCKS_PER_SEC;


    return 0;
}
