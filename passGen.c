#include <stdio.h>

int main (void)
{
   char ch;
   int j,i=j=0;
   int ascii=0;
   int delta;
   
   printf("Welcome To the password Generator!\nPlease enter your first name ( lower-case):\n");
   scanf("%c",&ch);
   printf("Your Password: ");
   
   while (ch != '.') {
       if (ch >= 'a' && ch <= 'z')   delta = ch -'a';
       if (ch >= 'A' && ch <= 'Z')   delta= ch - 'A';
       if ( i%2==0 )  // zugi
           ch = 'A'+delta;
       else  // not zugi
           ch = 'a'+ delta ;

       printf("%c",ch);       
       
       if (i==0) ascii += (int)ch;   //first iteration

       if(ascii/1000000==0 && i!=0) {  //else, and we didnt pass 6 zeros
       // remember the answer is int (rounded)  ex:  123 / 100 = 1 , ex: 123 / 1000 = 0 
        for (j=1; j < (int)ch ; j*=10) ;  // how much should i shift left depend on new char c
        ascii=ascii*j; 
        ascii+=(int)ch;   
       }
       i++; 
       scanf("%c",&ch);
   }
  
   while (ascii > 10000000) ascii/=10;  
   printf("TheMighty");
   printf("%d\n",ascii);

return 0;
}
