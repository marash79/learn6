#pragma once
#include"Queue.h"
#include<iostream>

void push(Queue& q, int d)
{
	Element* e = (Element*)malloc(sizeof(Element));
	e->data = d;
	e->next = nullptr;
	if (q.head == nullptr)
	{
		q.head = e;
		q.tail = e;
	}
	else
	{
		q.tail->next = e;
		q.tail = e;
	}
}

int pull(Queue& q)
{
	if (q.head == nullptr) return 0;
	int res = q.head->data;

	if (q.head == q.tail)
		q.tail = nullptr;
	
	Element* e = q.head;
	q.head = q.head->next;
	free(e);
	return res;
}

int print(const Queue& q)
{
	if (q.head != nullptr)
	{
		//Element* curr = q.head;
		//do
		//{
		//	printf("%i - ", curr->data);
		//	curr = curr->next;
		//} while (curr->next != nullptr);
		//printf("\b\b\n");
		for (Element* curr = q.head; curr != nullptr; curr = curr->next)
			printf("%i - ", curr->data);
		printf("\b\b\n");
	}
	return 0;
}

void clearQueue(Queue& q)
{
	while (q.head != nullptr)
	{
		Element* curr = q.head;
		q.head = curr->next;
		free(curr);
	}
}

bool isEmpty(const Queue& q)
{
	return q.head;
}

void cloneQueue(Queue& q1, const Queue& q2)
{
	q1.head = q2.head;
	q1.tail = q2.tail;
}

void attachQueue(Queue& q1, const Queue& q2)
{
	if (q1.head == nullptr)
		cloneQueue(q1, q2);
	else
	{
		q1.tail->next = q2.head;
		q1.tail = q2.tail;
	}

}