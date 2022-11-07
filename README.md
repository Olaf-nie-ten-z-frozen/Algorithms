The Village administration office was not used to working with a large number of invoices. And orders to build infrastructure on the Island kept coming in. In addition, the Village Administrator had recently hired a nephew from a neighboring village, and he was not very good with a printer. He printed many invoices several or more times each. Now the entire office is filled with them. The village leader turned to Ada and Serweryn for help. He asked them for some tool to organize all the invoices alphabetically. Ada and Serweryn came up with the idea to use a binary tree structure for this. They also came up with the idea of not having to enter the same invoice mistakenly printed by Soltys' nephew several times. It is enough to store the number of occurrences of each invoice in such a tree.

Input:
In the standard input, the first line shows the number of printed invoices to be entered n, followed by n lines containing the names of the invoices. The names can consist of numbers and uppercase letters.

0 ≤ n ≤ 3000000

Output:
Output a list of n entered invoices sorted in ascending order on the following lines.

Example:
Input:
10
AAAAAAAA1234
BC21374A12
POAB0986541
XZASQ4689
POAB0986541
SWE1243D23
POAB0986541
DER098765532
VV1111111
VV1111111
Output:
AAAAAAAAA1234
BC21374A12
DER098765532
POAB0986541
POAB0986541
POAB0986541
SWE1243D23
VV1111111
VV1111111
XZASQ4689
