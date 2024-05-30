#ifndef MY_MEM_MANAGER
#define MY_MEM_MANAGER 30052024

#include <stdlib.h>
#include <stdio.h>

#define PAGE_SIZE 4096

struct Chunk_struct {
    void* start;
    void* end; // points to adress AFTER the chunk
    struct Chunk_struct *next, *prev;
};
typedef struct Chunk_struct Chunk;

struct Page_struct {
    void* pointer;
    size_t size, capacity;
    Chunk* chunk_chain;
    struct Page_struct *next, *prev;
};
typedef struct Page_struct Page;

typedef void*(allocator_func_type)(size_t);
extern allocator_func_type *cool_allocator;

typedef void(deallocator_func_type)(void*);
extern deallocator_func_type *cool_deallocator;


void init_allocator(allocator_func_type alloc, deallocator_func_type dealloc);
void *memloc(size_t size);
void memfree(void *ptr);
void programm_end();


void* try_allocate(Page* page, size_t size);
Page* new_page(size_t size);
Chunk* new_chunk(void* start, void* end);
void chunkfree(Page* page, void* pointer);
void destroy_chunks(Page* page);
void destroy_pages();

#endif