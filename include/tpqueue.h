//@@ - 2, 17 + 2, 73 @@
// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>
template<typename T>
class TPQueue 
{
	// Сюда помещается описание структуры "Очередь с приоритетами"
private:
	struct ITEM 
	{
		T data;
		ITEM* next;
		ITEM* prev;
	};
	ITEM* head;
	ITEM* tail;
	TPQueue::ITEM* make(const T& data, ITEM* prev) {
		ITEM* item = new ITEM;
		item->data = data;
		item->next = nullptr;
		item->prev = prev;
		return item;
	}

public:
	TPQueue() :head(nullptr), tail(nullptr) {}
	~TPQueue() 
	{
		while (head)
			pop();
	}
	void push(const T& data) 
{
		if (tail && head) 
		{
			ITEM* ToQue = tail;
			while (ToQue && data.prior > (ToQue->data).prior) 
			{
				ToQue = ToQue->prev;
			}
			if (ToQue)
			{
				ITEM* temp = ToQue->next;
				ToQue->next = make(data, ToQue);
				ToQue = ToQue->next;
				ToQue->next = temp;
				if (temp)
					temp->prev = ToQue;
				else
					tail = ToQue;
			}
			else
			{
				ToQue = make(data, nullptr);
				ToQue->next = head;
				head->prev = ToQue;
				head = ToQue;
			}
		}
		else 
		{
			head = make(data, nullptr);
			tail = head;
		}
	}
	T pop()
	{
		assert(head);
		ITEM* temp = head->next;
		T data = head->data;
		if (temp)
			temp->prev = nullptr;
		delete head;
		head = temp;
		return data;
	}
};

struct SYM 
{
	char ch;
	int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
