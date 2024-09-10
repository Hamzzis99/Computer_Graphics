#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

// ��� ������ ����ϰ� ������ִ� �Լ�
void MultiArrays(int array[4][4], int array2[4][4])
{
	int sum[4][4];

	// ���� ��� (����� �� ��� ���� ���� �� �ջ�)
	for (int a = 0; a < 4; a++)
	{
		for (int i = 0; i < 4; i++)
		{
			sum[a][i] = 0; // �ʱⰪ ����
			for (int k = 0; k < 4; k++)
			{
				sum[a][i] += array[a][k] * array2[k][i];
			}
		}
	}

	// ���� �迭 ���
	printf("���� �迭 ���:\n");
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", sum[a][i]);
		}
		printf("\n");
	}
	printf("\n");
}


//������ ���� ����ϰ� ������ִ� �Լ�.
void AddArrays(int array[4][4], int array2[4][4]) //�޴� a
{
	int sum[4][4];

	//������ ���� ����ϴ� �Լ�.
	for (int a = 0; a < 4; a++)
	{
		for (int i = 0; i < 4; i++)
		{
			sum[a][i] = array[a][i] + array2[a][i];
		}
	}

	//������ ���� ����ϱ�.
	printf("���� �迭 ���:\n");
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", sum[a][i]);  // ���ڸ� �� �� ����ϰ�...
		}
		printf("\n");  // �� ���� ���� �� �� �ٲ�
	}

	printf("\n"); // ������
}

void MinusArrays(int array[4][4], int array2[4][4]) //�޴� d
{
	int sum[4][4];

	//������ ���� ����ϴ� �Լ�.
	for (int a = 0; a < 4; a++)
	{
		for (int i = 0; i < 4; i++)
		{
			sum[a][i] = array[a][i] - array2[a][i];
		}
	}

	//������ ���� ����ϱ�.
	printf("���� �迭 ���:\n");
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", sum[a][i]);  // ���ڸ� �� �� ����ϰ�...
		}
		printf("\n");  // �� ���� ���� �� �� �ٲ�
	}

	printf("\n"); // ������
}

void Determine(int array[4][4], int array2[4][4], int* count) //�޴� e �Ǻ���
{
	if (*count == 0) // Ȧ�����
	{
		printf("\n����� ¦���� ���: \n");
		printf("\n");

		printf("ù��° ����� ¦��: \n");
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				if (array[i][j] % 2 == 0)
				{
					printf("%d ", array[i][j]);
				}
				else {
					printf("X ");
				}
			}
			printf("\n");
		}
		printf("\n");
		printf("�ι�° ����� ¦��: \n");
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				if (array2[i][j] % 2 == 0)
				{
					printf("%d ", array2[i][j]);
				}
				else {
					printf("X ");
				}
			}
			printf("\n");
		}
	}

	else if (*count == 1)
	{
		printf("\n����� Ȧ���� ���: \n");
		printf("\n");

		printf("ù��° ����� Ȧ��: \n");
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (array[i][j] % 2 == 1)
				{
					printf("%d ", array[i][j]);
				}
				else {
					printf("X ");
				}
			}
			printf("\n");
		}
		printf("\n");
		printf("�ι�° ����� Ȧ��: \n");
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (array2[i][j] % 2 == 1)
				{
					printf("%d ", array2[i][j]);
				}
				else {
					printf("X ");
				}
			}
			printf("\n");
		}
	}
	else if (*count == 2) {
		printf("\n���� ��� ���:\n");
		printf("\n");

		printf("ù��° ���� ��� ���\n");
		for (int a = 0; a < 4; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				printf("%d ", array[a][i]);
			}
			printf("\n");
		}

		printf("�ι�° ���� ��� ���\n");
		for (int a = 0; a < 4; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				printf("%d ", array2[a][i]);
			}
			printf("\n");
		}
	}
	*count = (*count + 1) % 3;
}

void NewArray(int array[4][4], int array2[4][4]) // �޴� s
{
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			array[a][i] = rand() % 3;
			array2[a][i] = rand() % 3;
		}
	}

	// ù ��° 2���� �迭 ���
	printf("ù��° 2���� �迭 ���:\n");
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", array[a][i]);
		}
		printf("\n");
	}

	// �� ��° 2���� �迭 ���
	printf("\n�ι�° 2���� �迭 ���:\n");
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", array2[a][i]);
		}
		printf("\n");
	}

	printf("\n"); // ������
}

void NumMultiple(int array[4][4], int array2[4][4], int nummenu) // 1~9�� �׽�Ʈ
{
	int sum[4][4];
	int sum2[4][4];

	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			sum[a][i] = array[a][i] * nummenu;
		}
	}

	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			sum2[a][i] = array2[a][i] * nummenu;
		}
	}

	printf("\n");
	printf("ù ��° ��Ŀ� %d�� ���� ���:\n", nummenu);
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", sum[a][i]);
		}
		printf("\n"); // �� ���� ���� �� �ٹٲ�
	}

	printf("\n");
	printf("�� ��° ��Ŀ� %d�� ���� ���:\n", nummenu);
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", sum2[a][i]);
		}
		printf("\n"); // �� ���� ���� �� �ٹٲ�
	}
}

void Determinant(int array[4][4], int array2[4][4])
{
	printf("��Ľ��� ���� ���� �������� ���� �Լ�����Դϴ�...\n");
}

void Transposed(int array[4][4], int array2[4][4])
{
	printf("��ġ ����� ���� �������� ���� �Լ�����Դϴ�...\n");
}