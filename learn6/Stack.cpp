#pragma once
#include"Stack.h"
#include<iostream>


void push(Stack& q, int d)
{
	Element* e = (Element*)malloc(sizeof(Element));
	e->data = d;
	e->next = q.head;
	q.head = e;
}

int pull(Stack& q)
{
	int d = q.head->data;
	Element* e = q.head;
	q.head = q.head->next;
	free(e);
	return d;	
}

int print(const Stack& q)
{
		for (Element* curr = q.head; curr != nullptr; curr = curr->next)
			printf("%i -> ", curr->data);
		printf("\b\b\b\n");

	return 0;
}

void clear(Stack& q)
{
	while (q.head != nullptr)
	{
		Element* next = q.head->next;
		free(q.head);
		q.head = next;
	}
}

bool isEmpty(const Stack& q)
{
	return q.head;
}

void indexQ(Stack q)
{
	int idx=0;
	for (Element* e = q.head; e != nullptr; e = e->next)
	{
		e->index = idx++;
	}
	
}

void clone(Stack& q1, const Stack& q2)// Clone Q2 to Q1
{
	if (q1.head = nullptr)//if destination is empty
		attach(q1, q2);
	Element* e=q2.head; // temp element assigned the firs element of array of what to be copied
	Element* target=q1.head;// temp element assigned the firs element of array of where to be copied
	
	while (target)// fill target untill it is full
	{
		q1.tail = target;//assign target tail to current target member which is being changed
		if (e)
		{
			target->data = e->data;
			target = target->next;
			e = e->next;
		}
		else
		{
			Element* next = target;
			while (target = next)
			{
				next = target->next;
				free(target);
			}
		}
	}
	while (e)
	{
		target = (Element*)malloc(sizeof(Element));
		target->data = e->data;
		q1.tail->next = target;
		q1.tail = target;
		e = e->next;
	}
	q1.tail->next = nullptr;
	indexQ(q1);
} 

void attach(Stack& q1, const Stack& q2)//attach Q2 to Q1
{
	if (q2.head == nullptr)//if attached queue is empty exit without anythng
		return;

	Element* currS = q2.head;

	if (q1.tail = nullptr)//if destination is empty create first member
	{
		q1.head = (Element*)malloc(sizeof(Element));
		q1.head->data = q2.head->data;
		q1.tail = q1.head;
		currS = currS->next;
	}

	while (currS)//create the rest and assign source data
	{
		Element* currD = (Element*)malloc(sizeof(Element));
		currD->data = currS->data;
		q1.tail->next = currD;
		q1.tail = currD;
		currS = currS->next;
	}
	q1.tail->next = nullptr;
	indexQ(q1);
}

void insert(Stack& q, int d, int beforeIndex)//insert member before index, insert after the last if given -1
{

	if (beforeIndex < -1||beforeIndex>q.tail->index+1)//return if given index out of range
		return;
	if (beforeIndex == -1)
		beforeIndex = q.tail->index;

	Element* newe = (Element*)malloc(sizeof(Element));
	newe->data = d;

	if (beforeIndex == q.tail->index+1)//insert after last element
	{
		newe->next = nullptr;
		q.tail->next = newe;
		q.tail = newe;
		q.tail->index = beforeIndex + 1;
		return;
	}
	else
	{
		if (beforeIndex == 0)//insert before first element
		{
			newe->next = q.head;
			q.head = newe;
		}
		else//all other cases
		{
			for (Element* curr = q.head; curr != nullptr; curr = curr->next)//looking for index
			{
				if (curr->index = beforeIndex - 1)
				{
					newe->next = curr->next;
					curr->next = newe;
					break;
				}
			}
		}
		indexQ(q);
	}
}
	
void remove(Stack& q, int idx)//remove a member with given index
{
	Element* temp = q.head;
	if (idx < 0||idx>q.tail->index+1) return;//out of range return with no work done
	else if (idx == 0)//if removing first member
	{
		temp = q.head;
		q.head = q.head->next;
	}
	for (Element* curr = q.head; curr != nullptr; curr = curr->next)//lookup for all others cases
		if (curr->index = idx - 1)
		{
			temp = curr->next;
			curr = curr->next->next;
			break;
		}
	if (temp != q.tail)
		indexQ;
	free(temp);
}

int lookat(Stack& q, int idx)//return data on given index
{
	if (idx < 0 || idx>q.tail->index) return;//out of range return with no work done
	for (Element* curr = q.head; curr != nullptr; curr = curr->next)//lookup for all others cases
	{
		if (curr->data = idx) return curr->data;
	}
	return 0;
}




