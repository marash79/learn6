
#include <iostream>
#include"ring.h"

void pushNext(Ring& r, int d)
{
	
	Element *e= (Element*)malloc(sizeof(Element));
	e->data = d;

	if (r.current=nullptr)
	{
		r.current = e;
		e->prev = e;
		e->next = e;
		return;
	}
	
	e->next = r.current->next;
	e->prev = r.current;
	r.current->next->prev = e;
	r.current->next = e;
}

void pushPrev(Ring& r, int d)
{
	Element* e = (Element*)malloc(sizeof(Element));
	e->data = d;

	if (r.current = nullptr)
	{
		r.current = e;
		e->prev = e;
		e->next = e;
		return;
	}

	e->next = r.current;
	e->prev = r.current->prev;
	r.current->prev->next = e;
	r.current->prev = e;
}

int pull(Ring& r)
{
	if (r.current == nullptr)
		return 0;
	Element* e = (Element*)malloc(sizeof(Element));
	e = r.current;
	int d = e->data;
	if (r.current->prev = r.current->next)
	{
		r.current = nullptr;
	}
	else
	{
		r.current->next->prev = r.current->prev;
		r.current->prev->next = r.current->next;
		r.current = r.current->next;
	}
	free(e);
	return d;
}

void goNext(Ring& r)
{
	if (r.current != nullptr)
		r.current = r.current->next;
}

void goPrev(Ring& r)
{
	if (r.current != nullptr)
		r.current = r.current->prev;
}

void printR(Ring& r)
{
	if (r.current == nullptr)
	{
		printf("empty ring");
		return;
	}
	Element* e = r.current;
	do
	{
		printf("%i", r.current->data);
		r.current = r.current->next;
	} while (e != r.current);
}

