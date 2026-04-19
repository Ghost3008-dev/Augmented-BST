# Order Statistic Tree (Augmented BST) in C++

## Overview

This project implements an **Order Statistic Tree** using a Binary Search Tree (BST) augmented with subtree sizes.

It supports efficient order-based queries like:

* K-th smallest element
* Rank of an element

---

## Key Idea

Each node stores an extra field:

```cpp
int size; // number of nodes in subtree
```

This allows order-statistic operations in **O(log n)** (average case).

---

## Features

* Insert elements
* Delete elements
* Find k-th smallest element
* Find rank of a key
* Inorder traversal

---

## Data Structure

Each node contains:

* `key` → value
* `size` → subtree size
* `left`, `right` → pointers

---

## Time Complexity

### Average Case

* Insert → O(log n)
* Delete → O(log n)
* K-th smallest → O(log n)
* Rank → O(log n)

### Worst Case

* All operations → O(n) (skewed tree)

---

## Example

### Input

```cpp
{20, 10, 30, 5, 15, 25, 35}
```

### Output

```
Inorder: 5 10 15 20 25 30 35
3rd smallest: 15
Rank of 25: 5
```

---

## How to Run

### Compile

```bash
g++ -std=c++17 main.cpp -o bst
```

### Run

```bash
./bst
```

---

## Project Structure

```
.
├── main.cpp
└── README.md
```

---

## Limitations

* Not self-balancing
* Worst case O(n)
* No duplicate handling

---

## Improvements

* Convert to AVL / Red-Black Tree
* Handle duplicates
* Add iterative implementation
* Support range queries

---

## Applications

* Median finding
* Ranking systems
* Competitive programming

---
