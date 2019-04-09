#pragma once
#include <stddef.h>

/* override the allocator with these methods; to be called BEFORE allocating anything */
struct smpp34_memory_functions {
	void * (*malloc_fun)(size_t sz);
	void * (*realloc_fun)(void *ptr, size_t sz);
	void (*free_fun)(void *ptr);
};

void smpp34_set_memory_functions(const struct smpp34_memory_functions *mf);

void *smpp34_malloc(size_t sz);
void *smpp34_realloc(void *ptr, size_t sz);
void smpp34_free(void *ptr);
