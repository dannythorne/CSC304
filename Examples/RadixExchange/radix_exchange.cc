
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void radix_exchange( int* a, int n, int bit);

void init( int* a, int n);
void display( int* a, int n);
void shuffle( int* a, int n);

int main()
{
  int* a;
  int n = 16;

  a = new int[n];

  init( a, n);

  display( a, n);

  shuffle( a, n);

  display( a, n);

  radix_exchange( a, n, 3);

  display( a, n);

  delete [] a;

  cout << "Good Bye!" << endl;

  return 0;
}

void radix_exchange( int* a, int n, int bit)
{
  if( n>1)
  {
    int i, j;
    int temp;

    i = 0;
    j = n-1;

    while( i!=j)
    {
      while( i<j && !((a[i]>>bit)&(1)) ) { i++;}
      while( j>i &&   (a[j]>>bit)&(1)  ) { j--;}

      if( i!=j)
      {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }

    // TODO: Handle i and j boundary cases.
    radix_exchange( a, i, bit-1);
    radix_exchange( a + i, n-i, bit-1);
  }
}

void init( int* a, int n)
{
  int i;
  for( i=0; i<n; i++)
  {
    a[i] = i;
  }
}

void display( int* a, int n)
{
  if( n < 32)
  {
    int i;
    for( i=0; i<n; i++)
    {
      cout << " " << a[i];
    }
    cout << endl;
  }
}

void shuffle( int* a, int n)
{
  int i, j, temp;
  for( i=n-1; i>0; i--)
  {
    j = (int)floor( i* ( rand() / ( (double)RAND_MAX + 1.0)));
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }
}


