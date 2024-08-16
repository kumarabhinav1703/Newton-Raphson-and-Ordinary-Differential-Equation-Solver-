#include <stdio.h>
#include <math.h>

/* exp(x) - 2x = 0 */
/* f(x) = exp(x) - 2x */
/* => f'(x) = exp(x) - 2 */

double f(double x)
{
	return cos(x)-0.6*x;
}

double fdash(double x)
{
	return -sin(x)-0.6 ;
}

int
main(void)
{
	double x0 = 0;
	printf("Initial guess: %lf, f(x0) = %lf\n", x0, f(x0));
	for (int i = 0; i < 50 && fabs(f(x0)) > 1e-12; i++) {
		double fval = f(x0);
		double fdashval = fdash(x0);
		x0 = x0 - fval / fdashval;
		printf("%d: New x0 = %lf, f(x0) = %lf \n", i+1, x0, f(x0));
	}
	return 0;
}
