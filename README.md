# Purpose
The title says for itself.

Programm takes malloc/free (or your custom allocator and deallocator) and optimizes memory usage by minimizing count of system calls to allocate memory.
The programm also deallocates memory for you at the end of runtime, if you forgot to do it.
* ALWAYS APPEND programm_end() AT THE END OF YOUR PROGRAMM. OTHERWISE IT WILL EAT OUT ALL OF YOUR RAM.

# Usage
* void init_allocator(allocator_func_type alloc, deallocator_func_type dealloc) - set your custom allocator and deallocator
* void *memloc(size_t size) - allocate size bytes of memory
* void *memnew(size_t size) - create a new special page with given size and allocate the whole page
* void memfree(void *ptr) - free allocated memory (in fact, it will deallocate only chunk. the REAL deallocation happens at the end of the programm with deallocation of all pages)
* void prealloc(size_t size) - preallocate page with a given size (in the beggining of the page chain)
* void prealloc_end(size_t size) - preallocate page with a given size (in the end of the page chain)
* void programm_end() - deallocates all the memory for usage and service (Page memory, Chunk memory). ALWAYS APPEND AT THE END OF YOUR PROGRAMM
* void page_info(short chunk_info) - print out the usage of memory in pages. if chunk_info = 1, prints the chunk chain info as well

You can use
* void* try_allocate(Page* page, size_t size)
* Page* new_page(size_t size) 
to specify allocation yourself. Do not forget to free page memory and page itself after.

Other functions are meant to be used only if you really now what they are doing.

# Structure
Standart structure. A brief explanation:
* Memory allocated in pages with large size
* Pages consist of chunks - little blocks of memory for usage
* Both pages and chunks are organized into linked lists

allocator_func_type = void*(alloc)(size_t)

deallocator_func_type = void(dealloc)(void*)
