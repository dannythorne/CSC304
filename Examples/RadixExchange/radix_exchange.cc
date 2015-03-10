
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void radix_exchange( int* a, int n, int bit, int minbit);

void init( int* a, int n);
void display( int* a, int n);
void shuffle( int* a, int n);
bool is_sorted( int* a, int n);

int main()
{
  int* a;
  int n = 16;

  a = new int[n];

  init( a, n);

  display( a, n);

  shuffle( a, n);

  display( a, n);
  cout << ((is_sorted(a,n))?("Is sorted."):("Is not sorted.")) << endl;

  radix_exchange( a, n, /*msb*/31, /*minbit*/0);

  display( a, n);
  cout << ((is_sorted(a,n))?("Is sorted."):("Is not sorted.")) << endl;

  delete [] a;

  return 0;
}

void radix_exchange( int* a, int n, int bit, int minbit)
{
  if( n>1 && bit>=minbit)
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

    if( !((a[i]>>bit)&(1))) { i++;}

    radix_exchange( a, i, bit-1, minbit);
    radix_exchange( a + i, n-i, bit-1, minbit);
  }
}

void init( int* a, int n)
{
  int i;
  for( i=0; i<n; i++)
  {
    a[i] = rand();
  }
}

void display( int* a, int n)
{
  if( n <= 256)
  {
    int i;
    for( i=0; i<n; i++)
    {
      cout << i << " " << a[i] << endl;
    }
    //cout << endl;
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

bool is_sorted( int* a, int n)
{
  int i;
  for( i=1; i<n; i++)
  {
    if( a[i] < a[i-1])
    {
      return false;
    }
  }
  return true;
}

