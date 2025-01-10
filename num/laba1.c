#include <stdio.h>
long int tobin (long int);
 int main (){
  long int a;
  scanf("%ld",&a);
  if (a>524287) {
  printf("числа больше 524287 не могут быть обработаны");
  return 0;
}

long int b=tobin(a);
  printf("%ld",b);
  return 0;
}

long int tobin(long int a){
  long int c=0;
  long int b=0;
  long int n=1;
  while (a>0){
    c=a%2;  
    b=c*n+b;
    a=a/2;
    n*=10;
  }
  return b; 
}