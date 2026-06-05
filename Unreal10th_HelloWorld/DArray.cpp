#include <iostream>
#include "DArray.h"

void DArray::Reserve(const int InCapacity)
{
	if (InCapacity <= Capacity)
	{
		printf("Reserve ERROR! 현재 Capacity(%d) > InCapacity(%d)로 추가 할당하지 않음.\n", static_cast<int>(Capacity), static_cast<int>(InCapacity));
		return;
	}

	int* NewData = new int[InCapacity];
	for (int i = 0; i < Size; i++)
	{
		*(NewData + i) = *(Data + i);
	}

	delete[] Data;	// 기존 데이터 삭제
	Data = NewData;	// 새로 할당한 값 가리키기

	Capacity = InCapacity;
}

void DArray::PushBack(const int InData)
{
	// 푸쉬 전에 캐퍼가 모자르면 캐퍼 확보
	if (Capacity <= Size)
	{
		ReAllocate();
	}

	*(Data + Size) = InData;
	Size++;
}

int DArray::PopBack()
{
	if (Size <= 0)
	{
		printf("PopBack ERROR !!   DArray Size = 0 \n");
		return 0;
	}

	int Pop = *(Data + (Size - 1));
	Size--;

	return Pop;
}

void DArray::Print() const
{
	printf("Data : ");
	for (int i = 0; i < Size; i++)
	{
		printf("%d ", *(Data + i));
	}
	printf("\n");
}

void DArray::ReAllocate()
{
	if (Size <= 0 && Capacity <= 0) // 비어있을 때 예외처리
	{ 
		Data = new int(1);	// 1개 생성
		Capacity = 1;

		return;
	}	

	const int Multiplier = 2;	// 2배만큼 재할당
	int* NewData = new int[Size * Multiplier];

	for (int i = 0; i < Size; i++)
	{
		*(NewData + i) = *(Data + i);
	}

	delete[] Data;	// 기존 데이터 삭제
	Data = NewData;	// 새로 할당한 값 가리키기

	Capacity *= Multiplier;
}
