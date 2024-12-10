#pragma once
struct Element
{
	int index=-1;
	int data;
	Element* next;
};

struct Stack
{
	Element* head = nullptr;
};

void push(Stack& q, int d);//insert data to queue

int pull(Stack& q);//release data from queue

int print(const Stack& q);//print all queue members on screen

bool isEmpty(Stack& q);//looks if queue is empty
void clear(Stack& q);//clean the queue
void clone(Stack& q1, const Stack& q2);//copy one queue to another
void attach(Stack& q1, const Stack& q2);//attach one queue to another
void insert(Stack& q, int d, int beforeIndex=-1);//insert member before index, insert after the last if given -1
void remove(Stack& q, int idx);//remove a member with given index
int lookat(Stack& q, int d);//return data on given index
