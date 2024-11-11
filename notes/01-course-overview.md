# Introduction to Computer Systems

<!--toc:start-->

- [Introduction to Computer Systems](#introduction-to-computer-systems)
  - [Course Theme](#course-theme)
  - [Great Realities](#great-realities)
    - [1: Ints are not integers, floats are not reals](#1-ints-are-not-integers-floats-are-not-reals)
    - [2: You've got to know assembly](#2-youve-got-to-know-assembly)
    - [3: Memory Matters](#3-memory-matters)
    - [4: There's more to performance than asymptotic complexity](#4-theres-more-to-performance-than-asymptotic-complexity)
    - [5: Computers do more than execute programs](#5-computers-do-more-than-execute-programs)
  - [Key abstractions](#key-abstractions)
  <!--toc:end-->

## Course Theme

**Abstraction is good, but don't forget reality**

- Most times, programmers work in the abstract
  - Abstract data types
  - Asymptotic analysis
- These abstractions have limits
  - In the presence of bugs, especially
  - Need to understand details of underlying implementations
- This course should prepare you for later systems classes
  - Compilers
  - Operating Systems
  - Networks
  - Computer Architecture
  - Embedded Systems
  - Storage Systems

## Great Realities

### 1: Ints are not integers, floats are not reals

Conceptually, squaring a positive real number is always at least 0.
With computers, however, this might not always be the case.

- As it turns out, 50000 squared gives -1794967296 for a computer.
- Case of integer overflow
- With floats, roundoff problems >> digits that aren't significant often end up dropped

The core of the problem: _Finite representations of infinite sets_

99% of the time, you're going to be fine.

- Edge cases can be catastrophic, like if you're writing a trading engine...
- Integer operations satisfy "ring" properties
  - Commutativity, associativity, distributivity
- Floating point operations satisfy "ordering" properties
  - Monotonicity, values of signs

Need to understand which abstractions apply in which contexts.
Important issues for compiler writers and serious application programmers.

### 2: You've got to know assembly

Chances are, you'll never write programs in assembly

- Compilers are better than you at that

But, understanding assembly is key to machine-level execution model

- Understand behavior of programs in presence of bugs
  - In these settings, high-level language models break down.
- Tuning program performance
  - Understanding optimizations done / not done by the compiler
  - Understanding sources of program inefficiency
- Implementing system software
  - Compiler has machine code as target
  - Operating systems must manage process state
- Creating / fighting malware
  - x86 assembly is the language of choice!

### 3: Memory Matters

Random Access Memory is a nonphysical abstraction, but memory unit is physical

- Memory is not unbounded
  - Needs to be allocated and managed
  - Many applications are memory dominated
- Memory referencing bugs
  - Spooky action at a distance
- Using your computer's memory hierarchy well matters
  - Knowing about cache lines, virtual memory pages, etc

Memory matters for correctness at the lower level

- You can't understand unintuitive bugs or data corruption bugs if you don't understand memory layout
- C and cpp don't do bounds checking, pointer liveness checks, or prevent mismatched alloc / frees

### 4: There's more to performance than asymptotic complexity

Constant factors matter too.
Must optimize at multiple levels, which can drive large perf gains.

- Algorithm
- Data structure
- Procedure / function
- Loop

To optimize the system, you must understand how programs get compiled and executed, how to measure perf and identify bottlenecks, without destroying code modularity and generality.

An example:

- If you need to write a nested loop, you can cook up an example which shows you that iterating on the inner loop first gives you ~20x worse performance.
- The reason is because of memory is organized on a computer and how code wants to access memory in each case.

### 5: Computers do more than execute programs

- I/O operations
- Moving data around in memory to prepare for function calls
- Network interactions

## Key abstractions

- Virtual machines / runtimes abstract over the operating system
  - They present the illusion of a uniform system API
  - In reality, code is running on all sorts of different architectures
- Processes abstract over executing programs
  - They present the illusion, to the program running, that it is the only one doing so on the machine
  - In reality, it is sharing memory and cpu cores with a host of other programs, being scheduled on and off by the OS kernel, in particular the scheduler
- Virtual memory pages abstract over main memory + disk i/o
  - They present the illusion to the program using the page, and also that it can have arbitrarily large addressable memory space (often larger than physical memory actually available on the machine running the program, through page swaps that call out to disk i/o)
  - In reality, physical memory is used by all sorts of competing programs and the mapping of processes + virtual memory addresses to physical memory addresses is managed by the OS kernel.
- Files abstract over i/o devices
  - Files provide a data model of a sequence of bytes, which disk files, networks, keyboards/mice, etc all have in common
  - In reality, the "backend" of the file might be a segment of disk memory, or a router microcontroller, or a mouse microcontroller, etc. But the operating system handles the interaction between the device backing the file via drivers.
