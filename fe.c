#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

int main()

{
   double x,h,t,t_end,f;
   FILE *fp1;

   fp1 = fopen("fe_2.txt","w");

   x = 2;  
   t = 0.0;
   h = 0.1;
   t_end = 20.0;

   fprintf(fp1,"%13.6e %13.6e\n", t,x);

   while (t < t_end) {
//   compute f
     f = -(x/2)-6.0*t*exp(-t/2);

//   update x
     x += h*f;

//   update t
     t += h;

//   print to file

     fprintf(fp1,"%13.6e %13.6e\n", t,x);
   }
   fclose(fp1);
   return 0;
}
