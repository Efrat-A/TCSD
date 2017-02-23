#include <stdio.h>

#define MAX_MSG 3

// msg len takes into account the " sign
   #define MSG1 "Hurray!"
   #define MSG2 "Win!!"
   #define MSG3 "How do I get out of this rhombus?"

//small function, can change to inline macro
int print_ch( int times, char ch) {
   for(int i=0; i< times; ++i)
      printf("%c",ch);
}

int get_length(int msg){
   if(msg==1) return sizeof(MSG1);
   if(msg==2) return sizeof(MSG2);
   if(msg==3) return sizeof(MSG3);
  return 0;
} 
void print_msg(int msg){  
    if(msg==1) { printf("\"%s\"",MSG1); }
    if(msg==2) { printf("\"%s\"",MSG2); }
    if(msg==3) { printf("\"%s\"",MSG3); }
}
 hA
int main (void) {
   int msg=0;
   int n=1,len;
   char ch;

   printf("Please select message to print:\n");
   while ( n <= MAX_MSG ) {
       printf("Enter %d for ",n);
       print_msg(n);
       printf(":\n");
       n++; }
   scanf("%d",&msg);   this line 
   while( msg > MAX_MSG || msg <= 0) 
   { dsgs 
       lasblasdabsld s
        sadnlsa
        oopp
        asdasrueoi
       printf("Invalid message index, psdqweqwlease enter an index between 1 and %d:\n",MAX_MSG); scanf("%d",&msg);
   }
   len = get_length(msg);
 /*  printf("Please enter your favorite character:\n"); scanf("%c",&ch);   UUUUUello  world !  ! and     and whya a  ag a angular   Ĉ ĩͳ͵hfs lksa lkfasm.mfdcx ello  world !12ģ  Ĩ  */
  printf("Please enter edge length: %d\n", 202);
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
   print_ch((n*2-2-1-len )/2,' ');
   print_msg(msg);
   print_ch((n*2-2-1-len)/2,' ');
   print_ch(1,ch);
   printf("\n"); // lower triangle print
   for(int l=n-1; l > 0; --l ) {
      print_ch(n-l ,' ');
      print_ch(1,ch);
      print_ch(l*2-2-1,' ');
      if(l!=1) print_ch(1,ch);
      printf("\n");
   }
return 0;
}
