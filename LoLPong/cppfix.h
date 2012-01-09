/*
  cppfix.h to use new and delete operators on the arduino platform.
  Thanks to TFrankuz (http://www.avrfreaks.net/index.php?name=PNphpBB2&file=viewtopic&p=410870) and prawnhead (http://arduinoetcetera.blogspot.com/2010/04/implementing-new-and-delete-c.html)
*/

#ifndef cppfix
#define cppfix

#include <stdlib.h>

__extension__ typedef int __guard __attribute__((mode (__DI__)));

void * operator new(size_t size);
void operator delete(void * ptr);

int __cxa_guard_acquire(__guard *g) {return !*(char *)(g);};
void __cxa_guard_release (__guard *g) {*(char *)g = 1;};
void __cxa_guard_abort (__guard *) {};

void * operator new(size_t size)
{
 return malloc(size);
}

void operator delete(void * ptr)
{
 free(ptr);
}

#endif
