#include <stdio.h>


// change if theres a new msg
#define MAX_MSG 3

// msg len takes into account the " sign
   #define MSG1 "Hurray!"
   #define MSG1_LEN 9
   #define MSG2 "Win!!"
   #define MSG2_LEN 7
   #define MSG3 "How do I get out of this rhombus?"
   #define MSG3_LEN 35
    
int print_ch( int times, char ch){
   for(int i=0; i< times; ++i)
      printf("%c",ch);
}

int main (void)
{
   // Hurray!
   //You Win!!
   //How do I get out of this rhombus?
   int msg=0; // choise of msg
   int n,len;
   char ch;
   
   printf("Please select message to print:\n");
   printf("Enter 1 for \"%s\":\n",MSG1);
   printf("Enter 2 for \"%s\":\n",MSG2);
   printf("Enter 3 for \"%s\":\n",MSG3);
   scanf("%d",&msg);   
   
   while( msg > MAX_MSG || msg <= 0) {
     printf("Invalid message index, please enter an index between 1 and 3:\n");
     scanf("%d",&msg);
   }
   
   if(msg==1) len = MSG1_LEN;
   if(msg==2) len = MSG2_LEN;
   if(msg==3) len = MSG3_LEN;
   // add other msgs here ..
   
   printf("Please enter your favorite character:\n");
   scanf("%c",&ch);   
   
   printf("Please enter edge length:\n");
   scanf("%d", &n);   
   
   while( n < (len + 2)/2+2)  { //little math
    printf("Invalid edge length, please enter a larger number:\n");
    scanf("%d", &n);
    }
     //upper triangle print
     for(int l=1; l < n; ++l ) {
      print_ch(n-l ,' ');
      print_ch(1,ch);
      print_ch(l*2-2-1,' ');
     if(l!=1) print_ch(1,ch);
      printf("\n");
     }
     // msg line print
     print_ch(1,ch);
     print_ch((n*2-2-1-len)/2,' ');
     if(msg==1) { printf("\"%s\"",MSG1); }
     if(msg==2) { printf("\"%s\"",MSG2); }
     if(msg==3) { printf("\"%s\"",MSG3); } 
     print_ch((n*2-2-1-len)/2,' ');
     print_ch(1,ch);
     printf("\n");
     // lower triangle print
     for(int l=n-1; l > 0; --l ) {
      print_ch(n-l ,' ');
      print_ch(1,ch);
      print_ch(l*2-2-1,' ');
     if(l!=1) print_ch(1,ch);
      printf("\n");
     }
return 0;
}
