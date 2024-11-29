#include "iostream"
using namespace std;


struct Matrix{
    int row,col;
    int* data;
};

struct triple{
    int i,j;
    int e;
} ;

struct TSmatrix{
    triple data[120];
    int mu,nu,tu=0;
};

void init(Matrix* mat)
    {
        cout<<"请输入行.";
        cin>>mat->row;
        cout<<"请输入列.";
        cin>>mat->col;
        int size=mat->row*mat->col;
        mat->data = (int*)malloc(size*sizeof(int));
        cout<<"请输入"<<size<<"个元素。";
        for(int i=0;i<size;i++)
            {
                cin>>mat->data[i];
            }
    }

void print(Matrix mat)
    {
        int size=mat.row*mat.col;
        for(int i=0,j=1;i<size;i++,j++)
            {
                cout<<mat.data[i]<<" ";
                if(j==mat.col)
                    {cout<<endl;
                    j=0;}
            }
    }

void change(Matrix mat,TSmatrix* ts)
    {
        int size=mat.row*mat.col;
        int rowflag=1;
        ts->mu=mat.row;
        ts->nu=mat.col;
        for(int i=0,j1=0,temp=0;i<size;i++,j1++)
            {
                if(i==0)
                    j1=1;
                if(mat.data[i]!=0)
                    {
                        ts->data[temp].i=rowflag;
                        ts->data[temp].j=j1;
                        ts->data[temp].e=mat.data[i];
                        temp++;
                        ts->tu++;
                    }
                if(j1==mat.col)
                    {
                        rowflag++;
                        j1=0;
                    }
            }
    }

void printts(TSmatrix ts)
    {
        cout<<endl<<"行   "<<"列   "<<"值"<<endl;
        cout<<ts.mu<<"   "<<ts.nu<<"   "<<ts.tu<<endl;
        for(int i=0;i<ts.tu;i++)
            {
                cout<<ts.data[i].i<<"   "<<ts.data[i].j<<"   "<<ts.data[i].e<<endl;
            }
    }

void fast(TSmatrix m,TSmatrix *t)
    {
        t->mu=m.nu;
        t->nu=m.mu;
        t->tu=m.tu;
        if(t->tu)
        {
        int q=0; 
        int p; 
        for (int col=1;col<=m.mu; col++) { 
            for (p=0; p<m.tu; p++) { 
                if (m.data[p].j==col) { 
                    t->data[q].i=m.data[p].j;
                    t->data[q].j=m.data[p].i;
                    t->data[q].e=m.data[p].e;
                    q++;
                }
            }
        }

        }
    }

void returnts(TSmatrix *ts)
    {
        int temp=0;
        for(int i1=0;i1<ts->mu;i1++)
            {
                for(int j1=0;j1<ts->nu;j1++)
                {
                    
                    if(j1+1==ts->data[temp].j && i1+1==ts->data[temp].i)
                        {
                            cout<<ts->data[temp].e<<" ";
                            temp++;
                        }
                    else
                        {
                        cout<<"0 ";
                        }
                }
            cout<<endl;
            }
    }


int main()
{
    Matrix mat;
    init(&mat);
    print(mat);
    TSmatrix ts;
    change(mat,&ts);
    printts(ts);
    TSmatrix fastts;
    fast(ts,&fastts);
    printts(fastts);
    returnts(&fastts);

}