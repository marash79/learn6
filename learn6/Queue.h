#pragma once
struct Element
{
	int index=-1;
	int data;
	Element* next;
};

struct Queue
{
	Element* head=nullptr, *tail=nullptr;
	int maxindex;
};

void push(Queue& q, int d);//insert data to queue

int pull(Queue& q);//release data from queue

int print(const Queue& q);//print all queue members on screen

void clear(Queue& q);//clean the queue
void clone(Queue& q1, const Queue& q2);//copy one queue to another
void attach(Queue& q1, const Queue& q2);//attach one queue to another
void insert(Queue& q, int d, int beforeIndex);
void remove(Queue& q, int idx);
int size(Queue& q);
int lookat(Queue& q, int d);
