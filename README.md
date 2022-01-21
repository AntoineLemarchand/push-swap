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
(on 10 000 tests, by number of operations)

<table>
	<th>
		<td colspan="2">Stack of 3</td>
		<td colspan="2">Stack of 5</td>
		<td colspan="2">Stack of 100</td>
		<td colspan="2">Stack of 500</td>
	</th>
	<tr>
		<td>min</td>
		<td colspan="2">0</td>
		<td colspan="2">0</td>
		<td colspan="2">489</td>
		<td colspan="2">5183</td>
	</tr>
	<tr>
		<td>mean</td>
		<td colspan="2">1</td>
		<td colspan="2">9</td>
		<td colspan="2">572</td>
		<td colspan="2">5495</td>
	</tr>
	<tr>
		<td>max</td>
		<td colspan="2">2</td>
		<td colspan="2">12</td>
		<td colspan="2">665</td>
		<td colspan="2">5878</td>
	</tr>
</table>
