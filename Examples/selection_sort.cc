#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

void init( int* a, int n);
void display( int* a, int n);
void shuffle( int* a, int n);
double selection_sort( int* a, int n);

int main( int argc, char** argv)
{
  cout << "Hello!" << endl;

  int* a;
  int n = 4e4;
  double t;

  if( argc > 1)
  {
    if( atoi(argv[1]))
    {
      n = atoi(argv[1]);
    }
  }

  a = new int[n];

  init( a, n);

  display( a, n);

  shuffle( a, n);

  display( a, n);

  t = selection_sort( a, n);
  cout << "elapsed time: " << t << " seconds" << endl;

  display( a, n);

  delete [] a;

  cout << "Good Bye!" << endl;

  return 0;
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

double selection_sort( int* a, int n)
{
  clock_t t;
  t = clock();

  int i, j, jmin, temp;
  int amin;

  for( i=0; i<n-1; i++)
  {
    jmin = i+1;
    amin = a[jmin];
    for( j=i+1; j<n; j++)
    {
      if( a[j] < amin)
      {
        amin = a[j];
        jmin = j;
      }
    }

    if( a[jmin] < a[i])
    {
      temp = a[i];
      a[i] = a[jmin];
      a[jmin] = temp;
    }
  }

  return ( clock() - t) / (double)CLOCKS_PER_SEC;
}

