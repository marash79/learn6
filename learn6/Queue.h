#pragma once
struct Element
{
	int data;
	Element* next;
};

struct Queue
{
	Element* head=nullptr, *tail=nullptr;
};

void push(Queue& q, int d);

int pull(Queue& q);

int print(const Queue& q);

void clearQueue(Queue& q);
void cloneQueue(Queue& q1, const Queue& q2);
void attachQueue(Queue& q1, const Queue& q2);