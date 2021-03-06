# Finding bugs in OpenCL compilers

This project is part of a practical task about finding bugs in OpenCL compilers, which uses the tools: [CLSmith](https://github.com/ChrisLidbury/CLSmith) and [clreduce](https://github.com/mpflanzer/clreduce) for this purpose. These tools are responsible for random kernel generation and execution, and program reduction. Furthermore, additional scripts written in shell script were created in order to help the execution and evaluation of the benchmarks.

Presentation: https://gitpitch.com/hussamaa/imp-cl-compilers-practical-task

## The scripts include:

* `generate-clsmith-kernels.sh` a script for multiple OpenCL kernel generation using CLSmith;
* `run-clsmith-kernels.sh` a script for running all CLSMith kernels inside a folder;
* `evaluate-results.sh` a script for evaluating all log files generated.

## Experimental Evaluation:

For this practical task, 500 kernels were generated using CLSmith (with flags: ...) and then compiled and executed with and without optimizations (a total of 1000 different test cases). These experiments were conducted on an otherwise idle Intel Core i7-3517U CPU @ 1.90GHz processor, with 8GB of RAM, running Ubuntu 17.10 x86-64. In addition, an Intel SDK v1.2 was used in order to run OpenCL kernels on CPU. Moreover, the benchmarks that took more than 60 seconds were considered **timeout**.

The results were into two categories; (i) with optimization and (iI) without optimizations:

### i) with optimizations:

* total of kernels: **500**;
* **56** timeouts (**11**%);
* **283** executions without problems (**57**%) (it doesn't mean that the result is correct);
* **161** failures (**32**%);
  * compiler crash: **44** *(27%)*;
  * out of resource (OpenCL error code -5): **98** *(61%)*;
  * other errors (OpenCL error codes -11 and -46): **19** *(12%)*.

### ii) without optimizations:

* total of kernels: **500**;
* **55** timeouts (**11**%);
* **296** executions without problems (**59**%);
* **149** failures (**30**%);
  * compiler crash: **6** *(4%)*;
  * out of resource (OpenCL error code -5): **124** *(83%)*;
  * other errors (OpenCL error codes -11 and -46): **19** *(13%)*.

### Note:

* **11**% of the benchmarks were timeout;
* The non-optimized set of benchmarks shown **4%** more executions without problems;
* **6%** of the optimized kernels that executed without problems produced different results if compared to their non-optimized version;
* In general, the optimized benchmarks shown **7**% more failures;
  * The optimized benchmarks shown **86**% more failures related to **compiler crash**;
  * The non-optimized benchmarks shown **20%** more failures related to **out of resources**.
