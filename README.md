# Purpose
The title says for itself.

Programm takes malloc/free (or your custom allocator and deallocator) and optimizes memory usage by minimizing count of system calls to allocate memory.
The programm also deallocates memory for you at the end of runtime, if you forgot to do it.
* ALWAYS APPEND programm_end() AT THE END OF YOUR PROGRAMM. OTHERWISE IT WILL EAT OUT ALL OF YOUR RAM.

# Usage
* void init_allocator(allocator_func_type alloc, deallocator_func_type dealloc) - set your custom allocator and deallocator
* void *memloc(size_t size) - allocate size bytes of memory
* void memfree(void *ptr) - free allocated memory (in fact, it will deallocate only chunk. the REAL deallocation happens at the end of the programm with deallocation of all pages)
* void programm_end() - deallocates all the memory for usage and service (Page memory, Chunk memory). ALWAYS APPEND AT THE END OF YOUR PROGRAMM

Other functions are meant to be used only if you really now what you are doing.

# Structure
Standart structure. A brief explanation:
* Memory allocated in pages with large size
* Pages consist of chunks - little blocks of memory for usage
* Both pages and chunks are organized into linked lists

allocator_func_type = void*(alloc)(size_t)

deallocator_func_type = void(dealloc)(void*)
