#include<iostream>
#include<fstream>

using namespace std;

class library{
public:
//long int libid=0;
long int  days=0;
long int limit=0;
long int bookid[100000]={0};
long int books=0;
long int score=0;

};


long int getmax(long int arr[], long int n)
{
    long int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

library getMax(library arr[], long int n)
{
    library mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i].score > mx.score)
            mx = arr[i];
    return mx;
}
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(library arr[],long int n, int exp)
{
    library output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i].score/exp)%10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i].score/exp)%10 ] - 1] = arr[i];
        count[ (arr[i].score/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(library arr[], long int n)
{
    // Find the maximum number to know number of digits
    library m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m.score/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void getscore(library libs[],int n)
{
  //long int score[100000];
  for(int i=0;i<n;i++)
  {
    libs[i].score = libs[i].days + 3*libs[i].books + 2*getmax(libs[i].bookid,libs[i].books);
  }
}

int main()
{
 int bookid[1000]={0};
 int books=0;
 int libraries=0;
 int days=0;
 library lib[100];
 cin>>books>>libraries>>days;
 for(int i=0;i<books;i++)
 {
   cin>>bookid[i];
 }
 /*for(int i=0;i<libraries;i++)
 {
    cin>>lib[i].books>>lib[i].days>>lib[i].limit;
    for(int j=0;j<lib[i].books;j++)
    {
       cin>>lib[i].bookid[j];
    }
 }
 getscore(lib,libraries);
 radixsort(lib,libraries);
 for(int i=0;i<libraries;i++)
 {
     cout<<lib[i].score<<endl;
 }
*/
return 0;
}

