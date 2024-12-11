#pragma once
#include "Element.h"
struct Ring
{
	Element* current = nullptr;
};


void pushNext(Ring& r, int d);
void pushPrev(Ring& r, int d);
int pull(Ring& r);
void goNext(Ring& r);
void goPrev(Ring& r);
void printR(Ring& r);