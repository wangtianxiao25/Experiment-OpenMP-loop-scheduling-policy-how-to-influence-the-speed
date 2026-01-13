# OpenMP Parallel Programming Examples / OpenMP 并行编程示例

## 📖 Introduction / 简介
This repository contains several C programs demonstrating different **OpenMP scheduling strategies** and **parallel trapezoidal integration**.  
本仓库包含多个 C 程序，展示了不同的 **OpenMP 调度策略** 以及 **并行梯形积分**。

The goal is to compare performance and behavior of various scheduling methods (`static`, `dynamic`, `guided`, `runtime`) and to illustrate how OpenMP can accelerate numerical computations.  
目标是比较不同调度方法（`static`、`dynamic`、`guided`、`runtime`）的性能与行为，并展示 OpenMP 如何加速数值计算。

---

## 📂 Files Overview / 文件概览

| Filename | Description (English) | 文件说明（中文） |
|----------|------------------------|------------------|
| `static_omp_sin_sum.c` | Uses **static scheduling** with default chunk size. | 使用 **静态调度**，默认块大小。 |
| `static_1_omp_sin_sum.c` | Static scheduling with chunk size = 1. | 静态调度，块大小设为 1。 |
| `dynamic_omp_sin_sum.c` | Dynamic scheduling with default chunk size. | 动态调度，默认块大小。 |
| `dynamic_n_div_thread_omp_sin_sum.c` | Dynamic scheduling with chunk size = `n / threads`. | 动态调度，块大小设为 `n / 线程数`。 |
| `guided_omp_sin_sum.c` | Guided scheduling (chunk size decreases over time). | 引导式调度（块大小随时间递减）。 |
| `serial_trap3.c` | Serial trapezoidal rule integration of `sin(x)` over `[0, π]`. | 串行梯形积分，计算区间 `[0, π]` 上的 `sin(x)`。 |
| `omp_trap3.c` | Parallel trapezoidal rule integration with **runtime scheduling**. | 并行梯形积分，使用 **runtime 调度**。 |

---

## 🚀 Usage / 使用方法

### Compile / 编译
```bash
gcc -fopenmp filename.c -o program_name -lm
```

### Run / 运行
```bash
./program_name <number_of_threads> <number_of_intervals>
```

- `<number_of_intervals>`: Number of trapezoids (e.g., `1000000`).  
  `<number_of_intervals>`：梯形数量（例如，`1000000`）。
- `<number_of_threads>`: Number of OpenMP threads to use (e.g., `4`).  
  `<number_of_threads>`：使用的 OpenMP 线程数（例如，`4`）。

### Example / 示例
```bash
gcc -fopenmp static_omp_sin_sum.c -o static_omp_sin_sum -lm
./static_omp_sin_sum 4 10000
```

---

# OpenMP Scheduling Performance Comparison / OpenMP 调度性能对比

## 📖 Introduction / 简介
This project compares the execution time of different **OpenMP scheduling strategies** (`static`, `static,1`, `dynamic`, `dynamic with chunk size = n/thread_count`, `guided`) when computing a sine summation task.  
本项目对比了不同 **OpenMP 调度策略**（`static`、`static,1`、`dynamic`、`dynamic (块大小 = n/线程数)`、`guided`）在执行正弦求和任务时的运行时间。

The goal is to analyze how thread count and scheduling type affect performance.  
目标是分析线程数量与调度类型对性能的影响。

---

## 📊 Performance Results / 性能结果

### English
The following table shows execution time (in seconds) for different scheduling strategies under varying thread counts.

| Scheduling Type | 1 Thread | 2 Threads | 4 Threads | 8 Threads | 16 Threads | 32 Threads |
|-----------------|----------|-----------|-----------|-----------|------------|------------|
| **static** | 74.31646442 | 59.14268799 | 34.85139320 | 18.76682695 | 10.80228603 | 8.81772993 |
| **static,1** | 72.35043789 | 35.60473051 | 17.87033677 | 9.32715935 | 8.32118767 | 8.19046889 |
| **dynamic** | 71.93566066 | 36.10714750 | 18.38744728 | 9.68762560 | 8.91104906 | 7.93459292 |
| **dynamic (n/thread conut)** | 72.30147201 | 60.49671174 | 33.99682588 | 18.24713892 | 10.87619403 | 9.50183971 |
| **guided** | 71.14864171 | 35.80310069 | 18.10961270 | 10.89815314 | 9.34499462 | 8.22930088 |

---
### 中文
下表展示了不同调度策略在不同线程数下的运行时间（单位：秒）。

| 调度类型 | 1 线程 | 2 线程 | 4 线程 | 8 线程 | 16 线程 | 32 线程 |
|----------|--------|--------|--------|--------|---------|---------|
| **static** | 74.31646442 | 59.14268799 | 34.85139320 | 18.76682695 | 10.80228603 | 8.81772993 |
| **static,1** | 72.35043789 | 35.60473051 | 17.87033677 | 9.32715935 | 8.32118767 | 8.19046889 |
| **dynamic** | 71.93566066 | 36.10714750 | 18.38744728 | 9.68762560 | 8.91104906 | 7.93459292 |
| **dynamic (n/线程数)** | 72.30147201 | 60.49671174 | 33.99682588 | 18.24713892 | 10.87619403 | 9.50183971 |
| **guided** | 71.14864171 | 35.80310069 | 18.10961270 | 10.89815314 | 9.34499462 | 8.22930088 |
---