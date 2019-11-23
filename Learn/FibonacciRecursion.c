//Fibonacci Series using Recursion 
#include<stdio.h> 

int fib(int n);

int main () 
{ 
  int n = 5;
  printf("%d", fib(n)); 
  getchar(); 
  return 0; 
}

int fib(int n) 
{ 
   if (n <= 1) {
       return n;
   }
//    printf("%d %d",n-1,n-2);
   return fib(n-1) + fib(n-2);
}