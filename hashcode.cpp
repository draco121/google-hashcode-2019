#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
ifstream fin;
ofstream fout;
long int bs[100000];
long int check[100000]={0};


class library
{
public:
    long int libid;
    long int nofbooks;
    long int nofdays;
    long int shiplmt;
    long int bookid[1000];
    long int libscore;
    library()
    {
        libid =0;
        nofbooks=0;
        nofdays=0;
        shiplmt=0;
        libscore =0;
    }
};


void scanner(library l)
{
    for(long int i=l.nofbooks-1; i>=0; i--)
    {

        //cout<<scoreindex[l.bookscores[i]]<<" ";
        if(check[l.bookid[i]]==1){
        fout<<l.bookid[i]<<" ";
        check[l.bookid[i]]=0;
        }
    }
    fout<<endl;
}

long int signup(library l,long int days)
{
     days -=l.nofdays;
     scanner(l);


    return days;
}

bool comparescore(library l1, library l2)
{
    return (l1.libscore > l2.libscore);
}
bool comparebook(int a,int b)
{
    return(bs[a]<bs[b]);
}

long int checkbooks(long int a[],long int n)
{
    long int count =0;
    for(int i=0;i<n;i++)
    {
        if(check[a[i]]==1)
            count++;
    }
    return count;
}

void libscore(library lib[],long int j,long int libs,long int days)
{
    long int countbooks =0;
    for(long int i=j;i<libs;i++)
    {
        countbooks = checkbooks(lib[i].bookid,lib[i].nofbooks);
        lib[i].libscore = ;
    }
    sort(lib+j,lib+libs,comparescore);

}
long int libscheduler(library lib[],long int libs,long int days)
{
    long int countlib =0;
    long int countbooks =0;
    fout<<"     \n";
    for(long int i=0; i<libs; i++)
    {  libscore(lib,i,libs,days);
        countbooks = checkbooks(lib[i].bookid,lib[i].nofbooks);
         if(countbooks!=0){
        countlib++;
        fout<<lib[i].libid<<" "<<countbooks<<endl;
        days = signup(lib[i],days);
        if(days==0)
            break;
        }
    }
  return countlib;
}

int main()
{
    long int libs,days,books;
    fin.open("e.txt");
    fout.open("out5.txt");
    library* lib = new library[100000];
    fin>>books>>libs>>days;

    for(long int i=0; i<books; i++)
    {
        fin>>bs[i];
        check[i]=1;
    }
    for(long int i=0; i<libs; i++)
    {
        lib[i].libid = i;
        fin>>lib[i].nofbooks>>lib[i].nofdays>>lib[i].shiplmt;
        //lib[i].bookid = new long int[lib[i].nofbooks];
        for(long int j=0; j<lib[i].nofbooks; j++)
        {
            fin>>lib[i].bookid[j];
        }
        sort(lib[i].bookid,lib[i].bookid+lib[i].nofbooks,comparebook);
      //  sort(lib[i].bookscores,lib[i].bookscores+lib[i].nofbooks);
         //2*(bs[lib[i].bookid[lib[i].nofbooks-1]]) ;
         lib[i].libscore = -300*lib[i].nofdays + 10*lib[i].nofbooks  ;//-lib[i].nofdays*lib[i].nofdays + lib[i].nofbooks/(lib[i].nofdays*lib[i].nofdays)  ;
    }
     fin.close();
    sort(lib,lib+libs,comparescore);

   /*long int countlib =0;
    long int countbooks =0;
     fout<<"     \n";
    for(long int i=0; i<libs; i++)
    {
        if(lib[i].nofdays<days)
        {
         countbooks = checkbooks(lib[i].bookid,lib[i].nofbooks);
         if(countbooks!=0){
                countlib++;
        fout<<lib[i].libid<<" "<<countbooks<<endl;
        days = signup(lib[i],days);
         }
        }

    }
fout.seekp(0,ios::beg);
    fout<<countlib;
    fout.close();*/
    long int countlib = libscheduler(lib,libs,days);

    fout.seekp(0,ios::beg);
    fout<<countlib;
    fout.close();
}




