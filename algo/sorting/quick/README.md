# Quicksort

An algorithm which takes on average O(n log(n)) time. Worst case it takes
O(n^2) time.

Sorts by devide and conquer by partitioning the array in smaller and smaller
chunks. The choice of the pivot is here chosen at random. If a balanced pivot
is taken, the partitions are roughly halved. In the worst case, the left
and right partition are completely unbalanced, which negates the purpose of
devide and coquer, thereby making it O(n^2) Q.E.D.[1] 

[1] (not a formal proof!) 
