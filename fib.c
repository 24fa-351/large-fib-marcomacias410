#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>



  unsigned long long int fib_iterative(int nth_term)
{

    unsigned long long int first_num = 0;
    unsigned long long int second_num = 1;
    unsigned long long int sum_of_num = 0;


   if (nth_term == 2)
      return 1;

   for (int ix = 0; ix < nth_term-2; ++ix){
      
      sum_of_num = first_num + second_num   ;
      first_num = second_num ;
      second_num = sum_of_num ;
   }
   return sum_of_num;
}

unsigned long long int fib_recursive(int nth_term)
{

   if (nth_term <= 1)
      return nth_term;
   return fib_recursive(nth_term - 1) + fib_recursive(nth_term - 2);
}



int main(int argc, char *argv[]) 
{

    char letter;
    unsigned long long int fibo_sum;
    unsigned long long int txt_file_num;
    unsigned long long int given_num = atoi(argv[1]);
    letter = argv[2][0];

   if (argc != 3) {
      printf("File: %s <int> <r|i> \n", argv[0]);
      return 1;
   }


   if (letter != 'r' && letter != 'i') {
      printf("Error. Please enter the letter r (recursive) or i (iterative)");
      return 1;
   }

   if (letter == 'r') {

      fibo_sum = fib_recursive(given_num-1);
   }
   else if (letter == 'i') {

   fibo_sum = fib_iterative(given_num);
   } 

   printf("%lld", fibo_sum);

   return 0;
}
