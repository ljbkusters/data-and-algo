# Problem statement You are given two crystal balls. 

These balls break when dropped from an unknown hight (but never break when
dropped from a lower height). You work in an N story building and your crazy
boss has come up with the idea to find out which height the ball can be dropped
from without breaking by throwing them from of any of the floors in the
building. 

If both balls break you will have to face your boss and certainly be fired for
not giving him the answer to his question, but if you take too long your boss
will think you are just slacking off and fire you as well.

Find out the most efficient way to find out from which floor the ball may be
dropped!

# Reformulating the problem 

One can think of the N story building as a boolean array of values FALSE if the
ball doesn't break from that height and TRUE if the ball does break from that
height.

```
[f f f f f f f t t t t]
               ^
```

# Naive solution

Linear search the array until the first occurrence of TRUE.

O(N), doesn't use the second ball at all!


# Better solution

Unlike in binary search we cannot simply start in the middle because
there is no way of guarranteeing that (with only 2 shots) our second
try on the lower half doesn't fail.

Instead we can keep doubling our height untill one ball breaks

```
0: [f f f f f f f t t t t]
    ^              
1: [f f f f f f f t t t t]
      ^            
2: [f f f f f f f t t t t]
          ^            
3: [f f f f f f f t t t t]
                ^            
4: [f f f f f f f t t t t]
                        ^            
                        x first ball breaks
```
Now we have found a lower and upper bound for our search space in O(log N)

Since only one ball is left, we must now use linear search to continue.

However, the linear search area is of O(2^m) where m = O(log N) which means
that the linear search still has O(2^log N) = O(N). This is bad in worst case!

Best case approx O(log N) Worst case approx O(log N + N) = O(N)

# Best (general) solution

By breaking up the search space `N` into chunks of size `S` we can first
do `M = N/S` big steps `O(M)` and then do an `O(S)` linear search.

## But when is this optimized?
If we choose `S` large, our initial search will be small (`O(M) << O(N)`) but in
the worst case we have to do a long search of `O(S)` for non-trivial overhead
`S`. 

If we choose `S` small, our initial search `O(N/S)=O(N)` will be large but our
second search will be short `O(S)=O(1)`.

Disregarding any constants, it is obvious to see that this algorithm takes
O(N) time if the constant S is badly chosen.

However, if we choose `S=sqrt(N)` notice that `M=N/sqrt(N)=sqrt(N)`. This means
the initial large step search is `O(sqrt(N))` and the final search is also
`O(sqrt(N))`, making the total time complexity `O(sqrt(N))`.

## Optimized big-small linear search
Traverse in steps of `sqrt(N)` until fisrt ball breaks (this takes O(sqrt(N))

Then linear search the last range of size sqrt(N) (O(sqrt(N)))

```
0: [f f f f f ... f f t t t t ...] N
            ^
            idx = 1 * sqrt(N)
1: [f f f f f ... f f t t t t ...]
                  ^
                  idx = m * sqrt(N)
2: [f f f f f ... f f t t t t ...]
                            ^            
                            idx = (m+1) * sqrt(N)
3: [f f f f f ... f f t t t t ...]
                 |-----------|
                  Linear search
                  over region of size sqrt(N)
4: [f f f f f ... f f t t t t ...]
                      ^       
                      GOT EM
```

Total time complexity: O(sqrt(N))
Best case: O(sqrt N)
Worst case: O(sqrt N)

:)
