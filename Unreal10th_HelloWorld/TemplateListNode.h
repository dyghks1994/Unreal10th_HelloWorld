#pragma once

template <typename T>
struct TListNode
{
	T Data;
	TListNode* Next = nullptr;

	TListNode(T InData) : Data(InData) {}
};

template <typename T>
class TLinkedList
{
public:
	TLinkedList() = default;
	~TLinkedList();

	void Add(T InData);
	void InsertAt(T InData, int InPosition);
	void Remove(int InData);
	void RemoveAt(int InPosition);
	TListNodeT* Search(int InData) const;
	void Clear();
	void PrintList() const;

};