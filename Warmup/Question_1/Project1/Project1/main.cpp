#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "day.h"

int count = 0; // 멀티플 인수 전달 함수

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
	//첫번째 행렬 생성!
	printf("첫번째 2차원 배열 출력:\n");
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", array[a][i]);  // 숫자를 네 개 출력하고...
		}
		printf("\n");  // 한 행이 끝날 때 줄 바꿈
	}

	printf("\n"); // 마무리


	//두번째 행렬 생성!
	printf("두번째 2차원 배열 출력:\n");
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", array2[a][i]);  // 숫자를 네 개 출력하고...
		}
		printf("\n");  // 한 행이 끝날 때 줄 바꿈
	}
	printf("\n"); // 마무리

	while (menu != 'q') // 메뉴 선택. q가 나오지 않는이상.
	{
		printf("메뉴를 선택하세요! : ");
		menu = getchar();

		if (menu >= '1' && menu <= '9') {
			nummenu = menu - '0';
			NumMultiple(array, array2, nummenu);
		}
		/*if (isdigit(menu)) {  // menu가 숫자인지 확인
			nummenu = menu - '0';  // '0' ~ '9' 문자에서 숫자로 변환
			if (nummenu >= 1 && nummenu <= 9) {
				NumMultiple(array, array2, nummenu);  // 숫자 곱셈 함수 호출
			}
			}*/
			else
			{
				// 메뉴 구성 함수.
				switch (menu)
				{
				case 'm': // 행렬의 곱셈
					MultiArrays(array, array2);
					break;
				case 'a': //행렬의 덧셈
					AddArrays(array, array2);
					break;
				case 'd': //행렬의 덧셈
					MinusArrays(array, array2);
					break;
				case 'r': //행렬의 덧셈
					Determinant(array, array2);
					break;
				case 't': //행렬의 덧셈
					Transposed(array, array2);
					break;
				case 'e': // 홀수 짝수
					Determine(array, array2, &count);
					break;
				case 's': // 새로운 행렬 생성
					NewArray(array, array2);
					break;
				default:
					printf("올바른 메뉴를 선택하세요!\n");
				}
			}
			getchar();
		}
}