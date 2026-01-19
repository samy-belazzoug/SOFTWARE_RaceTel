# Research about Shared memory

##   What is a shared memory?
https://en.wikipedia.org/wiki/Shared_memory
http://www.kohala.com/start/unpv22e/unpv22e.chap12.pdf
A shared memory is a memory block that can be accessed by other programs simultaneously. It's one of the fastest form of  Inter-Processes-Communiation available.
Once the memory is mapped into the adress space of a shared memory region, no kernel involvement will occurs in passing data between processes that are storing and fetching information to and from the shared memory region (of course, the kernel will establish the memory mapping to allow processes to share memory, but it does involves in the passing of data between the processes, which is why it's fast).