son ami ektu pore tore txt dicchi oita solve kore dibi ai diye
ok?
ok bhai
Problem A

Misty’s Mishti Dilemma
Time limit: 2 seconds  Memory limit: 512 MB

Misty has a massive sweet tooth. To satisfy his cravings, he sends his juniors out to buy mishti
(sweets) from the famous Satkhira Ghosh Dairy in Khulna. But there is a catch: the city is
filled with competitor shops trying to use the same brand value (like Adi Satkhira Ghosh Dairy,
Shatkhira Vagyakul Ghosh Dairy, etc.)!
Since the juniors did not coordinate among themselves, they visited different shops and brought
back N mishtis in total. Unfortunately, many of the sweets turned out to be the exact same
flavor. Every distinct flavor of mishti has a unique “sweetness level”, which can be measured as
a non-negative integer.
Misty is a very particular food critic. He wants to taste each flavor exactly once. If there
are duplicate mishtis with the exact same sweetness level, he keeps just one for himself and
generously gives all the identical extras to his friend, Bristy.
After distributing the extras, Misty is left with a collection of strictly distinct mishtis. To
determine the “Ultimate Sweetness Score” of his tasting session, Misty combines the sweetness
levels of all the mishtis he kept using the legendary computer science operation: bitwise XOR.
Given the sweetness levels of the N mishtis the juniors originally brought, help Misty find the
Ultimate Sweetness Score!
Input
The first line of the input contains a single integer N (1 ≤ N ≤ 5 · 105

), the total number of

mishtis the juniors brought back.
The second line contains N space-separated integers A1, A2, . . . , AN (0 ≤ Ai ≤ 1018), the
sweetness levels of the mishtis.
Output
Print a single integer: the bitwise XOR of all the distinct sweetness levels in Misty’s collection.
If only one distinct mishti remains, the answer is simply the sweetness level of that mishti.
Examples
Sample Input 1 Sample Output 1
5
4 1 4 2 1

7

Sample Input 2 Sample Output 2
6
1 2 3 4 5 6

7

Sample Input 3 Sample Output 3
3
10 10 10

10

2

Problem Set