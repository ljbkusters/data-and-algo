# A basic bubble sort algorithm

Very simple, straight forward sorting algorithm.

## Bubble sort

We are given an unsorted array of length `N`.

We first look at the 0th index of the array (first pointer). We increment a
second pointer (compare pointer) over all indices greater than the first index
`{1, ..., N-1}` and compare whether it is smaller than the current item. If so
we swap them, otherwise we do nothing.

After we have done this we are guaranteed to have found the smallest value in
the array and it will be in position 0.

We now increment our first pointer to 1 and our compare pointer loops over all
indices larger than the first pointer (`{2 ... N-1}`). Again this guarantees
that the next smallest value will be in the 1-st index.

We keep repeating this untill the entire list is sorted.

This algorithm has `O(N^2)` complexity which is easy to see:

1. In the first iteration (of the outer loop) we perform `N-1` comparisons.
2. In the second iteration we perform N-2 comparisons
3. This pattern contiues.

This means we in total have `S = N-1 + N-2 + ... + 2 + 1` total comparisons.
This famous series has the analytical solution `S=(N-1)(N-2)/2`, thus
`S=O(N^2)`.

## Example

We first define a pointer (1) on the 0th index
```
[10, 3, 5, 8, 20, -1, 30, 55, 0]
 ^
 1
```
We then loop another pointer (2) over all of the following arguments in the
array and compare it with the value in the 0th position (here `10`).

```
[10, 3, 5, 8, 20, -1, 30, 55, 0]
 ^   ^
 1   2
```

Since 3 is smaller than 10, we swap them, and increment our
compare pointer to the next position
```
[3, 10, 5, 8, 20, -1, 30, 55, 0]
 ^      ^
 1      2
```

5 is larger than 3, so we do nothing and increment to the next
position. This keeps going untill we hit -1 (at the 5th index).

```
[3, 10, 5, 8, 20, -1, 30, 55, 0]
 ^                 ^
 1                 2
```

We swap -1 with 3 and continue.

```
[-1, 10, 5, 8, 20, 3, 30, 55, 0]
  ^                ^
  1                2
```

As you can see, the first index is now the smallest. By induction it follows
that on any of the sub-arrays (m, n-1) for `m in {1, ..., n-2}` the same holds.
(Not a formal proof lol.)

# Compile by running

`$ g++ bubble.cpp -o bubble.exe`

(Or your favourite c++ compiler of choice, using `c++11`.)
