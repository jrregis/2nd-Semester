#include<stdio.h>
#include<curses.h>
void CalcEsfera(float r, float *area, float *volume)
{
	*area = (4*(r*r));
	*volume = ((4*(r*r*r))/3);
	printf("Raio = %.2f \n Area = %.2f \n Volume = %.2f", r, *area, *volume);
}
int main()
{
	float r, area, volume;
	printf("Digite o raio\n");
	scanf("%f", &r);
	CalcEsfera(r, &area, &volume);
}