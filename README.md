# canonical-coin-system-test
Test whether a given coin system is canonical or not bases on its denominators. A coin system is canonical if you can produce the optimal combinations of coins for any coin sum by always picking the largest denomation lower than the remaining sum.

## Input
An integer **n**, the number of denominations in the coin system, followed by **n** space seperated integers which represent the different denominations in the coin system.

## Output
Outputs 
> canonical

if the coin system is canonical and
> non-canonical

if it is not.

### Example
The traditional British coin system is canonical:

**Input:**
```
12
1 2 5 10 20 50 100 200 500 1000 2000 5000
```

**Output:**
```
canonical
```
