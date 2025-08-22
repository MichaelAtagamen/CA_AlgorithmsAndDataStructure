# Algorithms & Data Structures – CA Project

This project implements three main components for the assessment:

1. **OrderedArray** – a templated dynamic array that keeps elements sorted.
2. **MySet** – a set class built on OrderedArray, ensuring uniqueness.
3. **Lead Deduplication** – a CSV-processing application to find unique and common sales leads.

---

## Part 1: OrderedArray

**Objective:**  
Implement a templated `OrderedArray` class that stores elements in natural order.

**Implementation Steps:**
1. Create class `OrderedArray<T>` using a dynamic array as private storage.
2. Implement constructors:
   - `OrderedArray(int grow_size)` – custom growth size.
   - `OrderedArray()` – default growth size.
3. Implement destructor `~OrderedArray()` to free all dynamic memory.
4. Implement main methods:
   - `void push(const T& newElement)` – inserts element in order.
   - `int length()` – returns the number of elements.
   - `T getElement(int index)` – returns element at index; default instance if out-of-range.
   - `bool remove(int index)` – removes element, returns success.
   - `int search(const T& target)` – searches for element, returns index or negative if not found.
   - `void clear()` – empties the array.
5. Test with different data types: `int`, `float`, `double`, and custom classes with comparison operators.

<img width="1506" height="637" alt="image" src="https://github.com/user-attachments/assets/77251cbb-1fc3-411c-9d7e-c279f4d6de52" />



---

## Part 2: MySet

**Objective:**  
Create `MySet` class using `OrderedArray` to store only unique elements.  

**Implementation Steps:**
1. Create class `MySet<T>` using `OrderedArray<T>` internally.
2. Ensure only unique elements are stored:
   - Add element only if it does not already exist.
3. Overload operators for set operations:
   - `Set | Set` → union of two sets.
   - `Set & Set` → intersection of two sets.
4. Test with multiple sets and verify union and intersection results.

<img width="1522" height="785" alt="image" src="https://github.com/user-attachments/assets/211f3c04-854f-4ec2-ac5e-a76e333ba202" />



---

## Part 3: Lead Deduplication

**Objective:**  
Process CSV files to identify unique and common leads based on phone numbers.

**Implementation Steps:**
1. Read two CSV files containing sales leads.
2. Store unique leads in a data structure (e.g., `MySet` or `OrderedArray`).
3. Identify and output:
   - Unique leads per rep.
   - Common leads between reps.
4. Handle missing files gracefully.
5. Output results to console or CSV.

<img width="1527" height="785" alt="image" src="https://github.com/user-attachments/assets/311524e1-5724-4ddc-951e-ce91c7d27679" />

