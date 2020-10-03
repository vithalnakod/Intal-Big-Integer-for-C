                 Intal 

1. Introduction

An intal is a non-negative integer of arbitrary length. The integer is stores as a null terminated string of ASCII characters. An intal is represented as a string of decimal digits that are stored in big - endian style,
 that is the most significant digit is at the head of the string. 

In C, the maximum length of an integer can be 20, if we use unsigned long long int, where as Intal is of arbitrary length. This implementation supports up to 1000 digits but with minor changes it can be
implemented for arbitrary length. 

Since C doesn't support such large integers, we have implemented arithmetic operations along with GCD, Factorial, Binomial coefficient, Fibonacci series etc.

Usually such large numbers find applications in the field of astronomy and cosmology. So the intal library would be helpful in many ways as C doesn't support such large integers. 
The intal library would be of great help for programs involving calculations etc in the field of astronomy.


2. Approach 

The various functions implemented are:
1) intal_add: return sum of two intals.
2) intal_diff: return difference between two intals.
3) intal_compare: return 1 if intal1 > intal2, 0 if intal1==intal2, -1 if intal2 > intal1.
4) intal_multiply: return product of two intals.
5) intal_mod: return result of intal1 % intal2
6) intal_gcd: return gcd of the two intals
7) intal_pow: given a intal and an integer return intal raise to the integer
8) intal_fibonacci: given an integer n, return nth fibonacci number
9) intal_factorial: given an integer n, return the factorial of n
10)intal_bincoeff: given two integers n and k, return nCk
11)intal_max: given an array of intals, return the offset of max intal
12)intal_min: given an array of intals, return the offset of min intal 
13)intal_search: given an array of intals and a key, return the first occurrence of the key in the array.
14)intal_binsearch: given an array and a key, implement binary search
15)intal_sort: given an array, sort the array in place and in O(nlogn).
16)coin_row_problem: return maximum amount of money that can be collected.


Let’s now look at how each of these functions were implemented.

1. intal_add

In this function, first we store the intals in new array in reversed form and then add digit by digit and store the sum of both the digits along with sum of carry in the same position in a new array.
The carry is updated by dividing this sum by 10 and sum is updated by the result of modulo 10. This sum is stored in the same position as that of digits.
In this way, we add digit by digit and store it in our final answer. At last we copy all array characters to a new array so that all the leading zeros are avoided if any and then we free the memory allocated 
to the two new arrays created and return the new copied array.

2. intal_diff 

In this function, we first call the compare function to check as to which intal is greater. If both the intals are equal, then we just return “0” as the difference of equal intals will be 0.
We create two new arrays and store the intals in reverse form. Then we subtract digits of same position in arrays and also subtract the carry, if this result is less than 0 then we add 10 to it and make
 the carry equal to 1. Then we store the final result in a new array in the same position.
In many cases, the length of one intal will be greater than the other, in that case, we subtract till the minimum length digits with their respective positions in other array and store it in our answer array, 
then the remaining digits of the maximum length intal are subtracted with carry and stored in answer array in the same position. The same method is used for intal_add too.
At last we copy all array characters to a new array so that all the leading zeros are avoided if any and then we free the memory allocated to the two new arrays created and return the new copied array.

3. intal_compare 

In this function, we first check the length of the intals, if the length of intal1 is greater than intal2 then we return 1, else if the length of intal2 is greater than intal1 then we return -1,
else we traverse through both the intals and if any digit of intal1 is greater then return 1, else if any digit of intal2 is greater than intal1 then return -1. If all digits are equal then we return 0 
indicating that both the intals are equal.

4. intal_multiply 

In this function, we first check if any of the intal is equal to “0”, if any intal is “0”, then we return “0” as the product of 0 with anything will be always 0.
We create a new array and initialize all the array elements with character ‘0’. 
We then multiply each digit of intal1 with each digit of intal2 and store the result in a new array. The positioning of the result in new array is achieved through the two variable named index1 and index2.
We also add the carry and the digit already present at the specific position (i.e. we update the elements). The new carry is set to result divided by 10. The array element is updated to mod 10.
At last we copy the final result into a new array to avoid all the leading zeros and free up all the memory allocated to temporary arrays used in the function and return the product of the two elements.

5. intal_mod

We use two new character arrays named temp and res. First we copy intal1 to res and then till intal2 is greater than res, we first initialize temp to intal2 and then till temp is equal to or greater 
than res we multiply temp with “2”, then res is updated to the difference between res and temp. 
To compare res with intal2 and temp with res we use the intal_compare function which is described in (3). 
Then at last we check if res is equal to 0 which means that intal2 divides intal1, we return “0”, else we copy the difference of temp and res to new array named res or just copy res based on the variable named flag. 
At last free up all the memory used by temporary arrays and return the answer.

6. intal_gcd 

We have used recursion to find the gcd of the given two intals. First we compare if intal2 is equal to 0 by using the intal_compare function and if intal1 is equal to 0 then we return "0",
else we return intal_gcd(intal2, intal1%intal1)
To find intal1 mod intal2 we use the intal_mod function which is described in (5)
Used another function named gcdHelp,  to avoid memory leaks

7. intal_pow

In this function we use two extra arrays named res and copy_intal1. First we initialize res with “1” and copy intal1 to copy_intal1. We use a variable named f and set it equal to n,
then till f is equal to or less than 0, we multiply res and copy_intal1 if f is odd and store it in res. We use intal_multiply function for this. Then divide f by 2 and then update copy_intal1 by 
copy_intal1 * copy_intal1. Again intal_multiply function is used for this. Once f is equal to zero or less than 0, we free up the memory allocated to copy_intal1 and return res.


8. intal_fibonacci

Given an unsigned integer n, we have to return the nth fibonacci number. We have used dynamic programming for this. First we check if n is 0 or if n is 1, then we return n itself else 
create dp (array of strings(intals)) table of n+1 size and initialize all elements to “0”. Then the element at index one is updated to “1”. Then we use the recursive relation dp[i]= dp[i-1]+dp[i-2]. 
Using this recursive relation, we get the nth fibonacci number. We use intal_add function to get the sum of dp[i-1] and dp[i-2] and store it in dp[i]. We do this so on up to n and get the nth Fibonacci number.
At last we copy the answer and free up the dp table and return the answer.

9. intal_factorial

Given an unsigned integer n, we have to return the factorial of n. We have used dynamic programming for this. First we check if given n is 0 or if its equal to 1, if so then return n itself, 
else create a dp table (array of intals) and initialize all elements to “0”. Then update the element at index 1 with “1”. The recurrence relation we get is dp[i]= i*dp[i-1]. 
Then we update ith element with i*dp[i-1]. We use intal_multiply function to get the product. But intal_multiply takes intals as arguments so we have to convert i to string, to achieve 
this we have used sprintf which convert integer to a string. 
We do this till n and get the factorial of n.
At last we copy the answer to a new array and free up the dp table and return the answer.

10. intal_bincoeff

Given 2 integers n, k return C(n, k). We again use dynamic programming for this. Initialize all elements to “0”. Then update element at first index to “1”. We use the Pascal’s identity C(n, k)= C(n-1,k)+ C(n-1,k-1).
We use intal_add to add two intals and store it in the dp table. 
We iterate from i=0 to i= n, and for every i, we iterate from j=min(i,k) to j=0, and update dp[j]= dp[j]+dp[i-1]. 
The min_find function is used to return the minimum number. It takes two numbers and returns the minimum number among those two numbers.
At last we free up the dp table and return the answer.  

11. intal_max

Given an array of intals, we have to return the offset of maximum intal. First we create a new array(string) named max_ele and copy the first element to it. Then we iterate over the array and compare 
each intal with the max_ele, if the intal is greater than max_ele, then update the max_ele to the array element and update index variable accordingly. 
Then free up the memory and return the index (offset).We use the intal_compare function to compare the intals. 
 
12. intal_min

Given an array of intals, we have to return the offset of mniimum intal. First we create a new array(string) named min_ele and copy the first element to it. Then we iterate over the array and 
compare each intal with the min_ele, if the intal is smaller than min_ele, then update the min_ele to the array element and update index variable accordingly. 
Then free up the memory and return the index (offset). We use the intal_compare function to compare the intals.

13. intal_search

Given an array of intals and a key, find the first occurrence of key in the array. We use a variable named index which is set to -1 and iterate over the array and compare the array element with 
key and if both are equal then we update the index and break the for loop and return the index and if there is no key present in the array then we return -1.

14. intal_binsearch

Given an array of intals and a key, find the first occurrence of key in the array and if there is no key present then return -1 and we have to implement binary search for this.
We have used another recursive function (named helper) which takes the array, start, end and key as arguments. It first checks if start>end, if so then there is no key present in the array. 
Then we use the variable mid which is equal to start + (end-start)/2. If arr[mid] is equal to key then return mid, else if arr[mid]>key then we call the same function with end updated to mid-1, else if 
arr[mid]<key then we call the same function with start being updated to mid+1.
In the main function i.e. in intal_binsearch we call the recursive function and store the result in a variable named index. Now we have to check if this is the index of first occurrence, so we iterate from 
that index to left side till either index becomes 0 or till the array element at index ‘index’ is not equal to key and then we finally return the index.

15. intal_sort

Given an array of intals, sort the array in place and in O(nlogn). We have used heap sort algorithm. We have used another function named heapify which is used to heapify a subtree rooted with node i 
which is an index in arr. 
First we iterate from i=n/2 to i=0 and heapify the arr. Then iterate the array from i=n-1 to i=1 and swap the first element with arr[i].
This is a void function, so there is no need to return anything.
16. coin_row_problem

Given a row of n coins, we have to return the maximum amount of money which can be collected but given the constraint that no two coins adjacent in the initial row are picked.
We use three variables named firstele, secondele and excluding. We initialize first element with arr[0] and secondele with “0”. Then iterate over the array and compare if firstele and 
secondele are same by using the intal_compare function, if they both are same then we copy the firstele into excluding, else we copy secondele into excluding. 
Then we add secondele and arr[i] and store it in firstele and then copy excluding into secondele. 
At that we free up all the memory used and return the secondele which is the maximum amount which can collected. 

That’s all about the functions implemented


3. Future Work

I would like to work on this project and implement some basic arithmetic operations such as addition, difference, multiply etc even for negative numbers.
I would also like to implement Karatsuba algorithm for intal_multiplication.
I would also like to implement commonly known sorting algorithms.  
Implementation of ‘Inserting an element (intal) into an sorted array’ would also be a good idea. 

The intal library can be extended to integers of arbitrary length with minor changes in the code. But few functions would take a lot of time.
