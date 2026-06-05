#include <iostream>
#include "LinkedList.h"

LinkedList::~LinkedList()
{
    Clear();
}

void LinkedList::Add(int InData)
{
    // InData가 들어간 노드를 만든다
    ListNode* NewNode = new ListNode(InData);

    // 맨 마지막으로 이동해서 맨 마지막 노드의 Next를 새 노드로 지정한다.
    if (Head == nullptr)
    {
        // 처음 넣을 때
        Head = NewNode;
        Tail = NewNode;
    }
    else
    {
        Tail->Next = NewNode;
        Tail = NewNode;
    }

    Size++;

    // 해드가 없는 경우. Tail과 Size에 대한 처리 필요


}

void LinkedList::InsertAt(int InData, int InPosition)
{
    // InData가 들어간 노드를 만든다
    // 포지션까지 Head에서 시작해서 Next를 계속 타고 이동한다.
    // 포지션 위치에 있는 노드의 Next 주소를 새로 만든 노드의 Next에 설정
    // 포지션 위치에 있는 노드의 Next 주소에 새로 만든 노드의 주소를 저장

    // InPosition이 Size보다 크거나 같을 때. InPosition이 0일 떄

    if (InPosition >= Size)
    {
        //printf("InsertAt ERROR\n");
        return;
    }

    else
    {
        ListNode* listNode = new ListNode(InData);
        ListNode* CurNode = Head;

        // 맨 앞에 추가하려고 할 때 Head도 새로 추가한 Node로 설정
        if (InPosition == 0)
        {
            listNode->Next = CurNode;
            Head = listNode;
        }

        else
        {
            for (int i = 0; i < InPosition; i++)
            {
                CurNode = CurNode->Next;
            }
            listNode->Next = CurNode->Next;  // 새 노드가 가리킬 Node 먼저 저장
            CurNode->Next = listNode;        // 이전 노드의 Next를 새로 추가한 Node로 저장
        
            // 맨마지막 노드면 Tail 갱신
            if (listNode->Next == nullptr)
            {
                Tail = listNode;
            }
        }

    }
}

void LinkedList::Remove(int InData)
{
    // InData를 가진 노드가 있는지 Head부터 찾는다.
    // 찾은 노드의 앞에 있는 노드의 Next를 찾은 노드의 Next에 저장된 주소로 변경한다.
    // 찾은 노드를 delete

    // 맨 앞과 뒤일 때 처리. 없는 경우에 대한 처리
    
    ListNode* CurNode = Head;

    while (CurNode != nullptr)
    {

    }

}

void LinkedList::RemoveAt(int InPosition)
{
    if (InPosition >= Size)
    {
        printf("오류 : %d 위치는 리스트의 범위를 벗어납니다.(현재 크기:%d)", InPosition, Size);
        return;
    }

    ListNode* NodeToDelete = nullptr;
    if (InPosition == 0)
    {
        // 특수처리
        NodeToDelete = Head;
        Head = Head->Next;

        if (Head == nullptr)
        {
            Tail = nullptr;
        }
        
    }

    else
    {
        // 위치 찾기
        // 찾은 노드 앞 노드의 Next를 찾은 노드의 Next로 변경
        // 찾은 노드 delete

        // 맨 앞과 뒤일 때 처리. 위치가 없는 경우는 그냥 종료
        ListNode* PrevNode = Head;
        int TargetIndex = InPosition - 1;

        for (int i = 0; i < TargetIndex; i++)   // 지울 노드의 앞쪽 노드(Prev)까지 가기 위해서
        {
            PrevNode = PrevNode->Next;  
        }
        NodeToDelete = PrevNode->Next;
        PrevNode->Next = NodeToDelete->Next;

        if (NodeToDelete == Tail)
        {
            PrevNode->Next = nullptr;   
            Tail = PrevNode;
            // Tail->next = nullptr;
        }
    }

    // 찾은 노드 delete
    delete NodeToDelete;
    NodeToDelete = nullptr;
    Size--;
    
}

ListNode* LinkedList::Search(int InData) const
{
    // InData와 같은 값을 가지는 노드 찾기

    if (Size <= 0)
    {
        return nullptr;
    }

    ListNode* CurNode = Head;

    while (CurNode != nullptr)
    {
        // 찾은 Node 리턴
        if (CurNode->Data == InData)
        {
            return CurNode;
        }
    }

    // 끝까지 찾는 Node가 없는 겨우
    return nullptr;
}

void LinkedList::Clear()
{
    // 동적할당이 된 노드를 모두 제거한다.
    
    while (Head)
    {
        RemoveAt(0);
    }

    /*
    if (Size == 0)
    {
        return;
    }

    else
    {
        ListNode* CurNode = Head;

        while (CurNode != nullptr)
        {
            Head = CurNode->Next;
            delete CurNode;
            CurNode = Head;
        }

        Head = nullptr;
        Tail = nullptr;
    }
    */
}

void LinkedList::PrintList() const
{
    // 리스트 Head부터 Tail까지 출력하는 함수
    if (Head == nullptr && Size == 0)
    {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    printf("리스트(크기:%d) : ", Size);

    ListNode* CurNode = Head;
    while (CurNode != nullptr)
    {
        printf("%d ->", CurNode->Data);
        CurNode = CurNode->Next;
    }
    printf("nullptr \n");
}
