'''

2 POINTER APPROACH

Input: g=[1,2,3] Min. size of cookies that child will content with 
       s=[1,1] Cookie size 
       Assign cookie s[j] to g[i] if s[j] >=g[i]
Output: 1

It's optimal to assign cookies to children with minimum grid factor 
Always assign minimum size cookies from all possible options 

Input: g=[1,2], s=[1,2,3] 
Output: 2

We get the same answer whether we apple it or not => Always assign minimum size cookies from all possible options 

But it's not always true 

Counter example

Input: g=[1,2,3], s=[1,2,3] 
If we apply it => Ans => 3
Else Ans => 2
 
'''

def findContentChildren(g:list[int],s: list[int])-> int :
    # O(nlogn) + O(mlogm) / O(1)
    g.sort() #O(n log n)
    s.sort() #O(n log n)
    i,j = 0,0
    solution = 0
    while i< len(g) and j< len(s): #O(m + n)
        if g[i] > s[j] : 
            j += 1
        else: 
            solution += 1
            i += 1
            j += 1
    return solution 

g = [2,3,5,7]
s = [1,2,5,6,6]

'''
solution => 3
(2,2)
(3,5)
(5,6)

'''

print(findContentChildren(g,s)) 

print(findContentChildren([1,2,3],[1,1]))





