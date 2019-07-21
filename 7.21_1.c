#include <stdio.h>

void complexAdd(double c1[], double c2[], double* r, double* i);
void complexMul(double c1[], double c2[], double* r, double* i);

void main()
{
	double complex1[2], complex2[2];
	double real_num, imag_num;

	printf("���Ҽ� �Է�1[�Ǽ� ���]: ");
	scanf("%lf %lf", &complex1[0], &complex1[1]);
	printf("���Ҽ� �Է�2[�Ǽ� ���]: ");
	scanf("%lf %lf", &complex2[0], &complex2[1]);

	complexAdd(complex1, complex2, &real_num, &imag_num);
	printf("���� ���] �Ǽ�: %f, ���: %f\n", real_num, imag_num);
	complexMul(complex1, complex2, &real_num, &imag_num);
	printf("���� ���] �Ǽ�: %f, ���: %f\n", real_num, imag_num);
}

void complexAdd(double c1[], double c2[], double* r, double* i)
{
	*r = c1[0] + c2[0];
	*i = c1[1] + c2[1];
}

void complexMul(double c1[], double c2[], double* r, double* i)
{
	*r = (c1[0] * c2[0]) - (c1[1] * c2[1]);
	*i = (c1[1] * c2[0]) + (c1[0] * c2[1]);
}