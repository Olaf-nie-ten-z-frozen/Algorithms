As part of the further modernization of the Island, Ada and Serweryn wanted to build transmission towers and the highest peaks in the area were perfect for this. The most economical way of arranging the towers was to start work on the lowest selected peak, gradually moving higher and higher, up to the highest peak.

The island was very mountainous. All the peaks there had a name. The members of the tribe had a special respect for the peaks, the height of which above sea level was a power of two. Ada and Serweryn decided to respect their liking and to handle the peaks of such heights in the first place.

Entry:
In the first line of input there is an integer t denoting the number of tests. Then there are t datasets. Each set consists of an integer n denoting the number of peaks. In the next n lines there are lines describing the peaks. The description consists of a one-word string s - the name of the peak and a positive integer w - the height of the peak in meters above sea level.

1 ≤ t ≤ 10
1 ≤ n ≤ 50,000
1 ≤ w <2 ^ 32
Exit:
On the output for each data set, the program should print an ordered list of the peaks in the order in which the towers were placed. Each peak is to be displayed in s-w format. For peaks with the same values, the order in which they appear in the list must be followed.

Example:
Entry:
3
5
Indrys 3
Fossa 67
Dingo 64
Werveta 10
Quetzal 1
3
Indrys 3
Fossa 2
Dingo 4
1
Indrys 10
Exit:
Kwezal-1 Dingo-64 Indrys-3 Werweta-10 Fossa-67
Fossa-2 Dingo-4 Indrys-3
Indrys-10
