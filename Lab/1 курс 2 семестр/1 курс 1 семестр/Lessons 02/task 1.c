//Високосный год
#include <stdio.h>

int main()
{
   int Y;
   printf("Высокосный год?\n Введите дату:");
   scanf("%d", &Y);
   if ((Y%400==0)||(Y%4==0 && Y%100!= 0))
   {    
       printf("YES\n");
   }
   else
   {    
       printf("NO\n");
   }
   return 0;
}
