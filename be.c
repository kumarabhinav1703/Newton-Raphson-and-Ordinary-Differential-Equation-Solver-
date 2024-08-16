#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void trz(
   double t_old,
   double x_old,
   double h,
   double *x_new
) {
   double tolr,x,f,delx,t_new,dfdx;
   int i_NR,N;
   bool flag_done;

   N = 10;
   flag_done = false;
   x = x_old;
   t_new = t_old + h;
   tolr = 1.0e-10;

   for (i_NR=0; i_NR < N; i_NR++) {
//   compute f

     f = (((x - x_old)/h) + ( (x/2)+6.0*t_new*exp(-t_new/2)));


   //  printf("%2d %13.6e\n",i_NR,f);
//   if f is small, quit

     if (fabs(f) < tolr) {
       *x_new = x;
       flag_done = true;
       break;
     }

//   compute dfdx

     dfdx = (1.0/h) + 0.5;
     if (fabs(dfdx) < 1.0e-20) {
       printf("dfdx too small. Halting...\n");
       exit(0);
     }

//   compute delx
     delx = -f/dfdx;

//   update x

     x += delx;
   }
   if (!flag_done) {
     printf("NR did not converge. Halting...\n");
     exit(0);
   }
   return;
}

int main()

{
   double x,h,t,x_new,t_end,f;
   FILE *fp1;

   fp1 = fopen("be_2.txt","w");

   x = 2;
   t = 0.0;
   h = 0.1;
   t_end = 20;

   fprintf(fp1,"%13.6e %13.6e\n", t,x);

   while (t < t_end) {
     trz(t,x,h,&x_new);

//   update t
     t += h;

//   print to file

     fprintf(fp1,"%13.6e %13.6e\n", t,x_new);

     x = x_new;
   }
   fclose(fp1);
   return 0;
}
