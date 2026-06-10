#pragma once

template <typename T>
class FixedStack {
public:
    // 스택에 원소를 추가합니다.
    void Push(T InValue)
    {
        if (IsFull())
        {
            printf("오류: 스택이 꽉 찼습니다! (Stack Overflow)\n");
            return;
        }
        TopIndex++;
        Data[TopIndex] = InValue;
    }

    // 스택에서 원소를 제거합니다.
    T Pop()
    {
        if (IsEmpty())
        {
            printf("오류: 스택이 비어있습니다! (Stack Underflow)\n");
            return Empty;
        }
        T Result = Data[TopIndex];
        TopIndex--;
        return Result;
    }

    // 스택의 최상단 원소를 확인합니다.
    T Top()
    {
        if (IsEmpty())
        {
            printf("오류: 스택이 비어있습니다! 값을 반환할 수 없습니다.\n");
            return Empty;
        }
        return Data[TopIndex];
    }

    // 스택이 꽉 찼는지 확인합니다.
    inline bool IsFull() const { return TopIndex == (StackCapacity - 1); }

    // 스택이 비었는지 확인합니다.
    inline bool IsEmpty() const { return TopIndex == Empty; }

    // 스택의 현재 크기를 반환합니다.
    inline int GetSize() const { return TopIndex + 1; }

private:
    // 스택의 최대 용량
    static constexpr int StackCapacity = 10;
    // 스택이 비었을 때의 인덱스 값
    static constexpr int Empty = -1;

    // 데이터를 저장하는 배열
    T Data[StackCapacity];
    // 스택의 최상단을 가리키는 인덱스
    int TopIndex = Empty;
};