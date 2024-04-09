# Binary search on ordered lists

Binary search on ordered lists/arrays (i.e. sorted array) is a `O(log(N))`
algorithm for search.

With the assumption that an array is ordered, we traverse the array
by first looking at the half index, then, if our searched value is larger
do the same procedure again in the upper half, and if the value is lower
than the search value, we do the same procedure in the lower half of the
array.

Here is a neat visualization.

```
An array with x as our searched value

1: [          ?      x   ]
              ^
              |
            we start our search at the middle of the array

Since we know the value x is larger than our current value
we know the bottom half cannot contain the value.

2: [~~~~~~~~~~~     ?x   ]
                    ^
                    |
            we now look in the middle
            of the upper half of the array
            darn, we just missed it (but the computer 
            has no way of knowing this!)

Again our value is larger than the search value, so we dismiss
the lower half and do another step of search

3: [~~~~~~~~~~~~~~~~~x?  ]
                      ^
                      |
            we now look in the middle
            of the upper half of the array

This time our value is smaller than the search value, so we dismiss
the upper half and do another step of search

4: [~~~~~~~~~~~~~~~~~x~~~]
                     ^
                     |
            we now look in the middle
            of the LOWER half of the array

Only one value is left, and it is our search value
we can now return that it is indeed contained!
```

Here I have implemented a boolean `contains` version, i.e. the function
returns true if the searched value is contained in the array, or flase otherwise.
It is straightforward to implement an index finding version (returning -1 if the
value is not contained).
