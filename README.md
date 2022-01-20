# push-swap
A 42Paris project

the aim of this project is to order a stack using another stack with a limited
amount of operations :

- pa : push the top value of stack a to stack b
- pb : push the top value of stack b to stack a
- ra : the top value of a becomes the bottom value of a
- rb : the top value of b becomes the bottom value of b
- rra : the bottom value of a becomes the top value of a
- rrb : the bottom value of b becomes the top value of b
- sa : the first and second value of a are swapped
- sb : the first and second value of b are swapped
- ss : sa + sb
- rr : ra + rb
- rrr : rra + rrb

## Usage
```
./pushswap [range of number]
```
example
```
./pushswap 1 7 51 4 6 899 "1312 1664"
```

## performances
(on 1000 tests, by number of operations)

### stack of 3
|Type|nb of operations|
|:---|---:|
|min|0|
|mean|1|
|max|2|

### stack of 5
|Type|nb of operations|
|:---|---:|
|min|0|
|mean|9|
|max|12|

### stack of 100
|Type|nb of operations)|
|:---|---:|
|min|540|
|mean|614|
|max|695|

### stack of 500
|Type|nb of operations)|
|:---|---:|
|min|5183|
|mean|5495|
|max|5878|
