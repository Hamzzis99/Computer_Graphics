#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "day.h"

int count = 0; // ��Ƽ�� �μ� ���� �Լ�

int main()
{
	srand(time(NULL));

	char menu = NULL;
	int array[4][4];
	int array2[4][4];
	int nummenu = 0;

	for (int a = 0; a < 4; a++)
	{
		for (int i = 0; i < 4; i++)
		{
			array[a][i] = rand() % 3;
			array2[a][i] = rand() % 3;
		}
	}
	//ù��° ��� ����!
	printf("ù��° 2���� �迭 ���:\n");
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", array[a][i]);  // ���ڸ� �� �� ����ϰ�...
		}
		printf("\n");  // �� ���� ���� �� �� �ٲ�
	}

	printf("\n"); // ������


	//�ι�° ��� ����!
	printf("�ι�° 2���� �迭 ���:\n");
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", array2[a][i]);  // ���ڸ� �� �� ����ϰ�...
		}
		printf("\n");  // �� ���� ���� �� �� �ٲ�
	}
	printf("\n"); // ������

	while (menu != 'q') // �޴� ����. q�� ������ �ʴ��̻�.
	{
		printf("�޴��� �����ϼ���! : ");
		menu = getchar();

		if (menu >= '1' && menu <= '9') {
			nummenu = menu - '0';
			NumMultiple(array, array2, nummenu);
		}
		/*if (isdigit(menu)) {  // menu�� �������� Ȯ��
			nummenu = menu - '0';  // '0' ~ '9' ���ڿ��� ���ڷ� ��ȯ
			if (nummenu >= 1 && nummenu <= 9) {
				NumMultiple(array, array2, nummenu);  // ���� ���� �Լ� ȣ��
			}
			}*/
			else
			{
				// �޴� ���� �Լ�.
				switch (menu)
				{
				case 'm': // ����� ����
					MultiArrays(array, array2);
					break;
				case 'a': //����� ����
					AddArrays(array, array2);
					break;
				case 'd': //����� ����
					MinusArrays(array, array2);
					break;
				case 'r': //����� ����
					Determinant(array, array2);
					break;
				case 't': //����� ����
					Transposed(array, array2);
					break;
				case 'e': // Ȧ�� ¦��
					Determine(array, array2, &count);
					break;
				case 's': // ���ο� ��� ����
					NewArray(array, array2);
					break;
				default:
					printf("�ùٸ� �޴��� �����ϼ���!\n");
				}
			}
			getchar();
		}
}