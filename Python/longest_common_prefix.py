# # While computing time complexity 
# # Do not use the same notation for different things
# def LCP(s1,s2): #O(L) use capital L to donate number of iterations 
#     n=min(len(s1),len(s2)) #O(L) / O(L) 
#     commonPrefix=""
#     for i in range(n):
#         if(s1[i]!=s2[i]):
#             break;
#         commonPrefix+=s1[i]
#     return commonPrefix

# def longestCommonPrefix(strs: list[str])->str: #O(n*L)
# #strs=Name of the parameter
# #list[str] indicates that str is list of strings and [str] specifies that elements are strings 
# #-> str indicates return type of function 
#     longestCommonPrefix=LCP(strs[0],strs[1])#O(L) / O(L)
#     for i in range(2,len(strs)):#O[n]
#         longestCommonPrefix=LCP(longestCommonPrefix,strs[i])#O(L) / O(L) 
#     return longestCommonPrefix # SpaceComplexity=O(L)

# print(longestCommonPrefix(["flower","flow","flat"]))

# Method_2

def areEqual(strs,index): # O(n)
    for i in range(1,len(strs)): # O(n)
        if(strs[i][index]!=strs[0][index]):
            return False
        return True 

def longestCommonPrefix(strs: list(str))->str: #O[n*L] / O[L]
    minLength=strs[0]
    for i in range(1,n):# O(n)
        minLength=min(strs[1],len(strs[i]))
    # **IMPORTANT**
    # minLength=min(len(word) for word in strs) O(n*L)
    # Python copies the word from the strs into word variable which take O(l) time 
     longestCommonPrefix="" # / O[L]
     for i in range(minLength): #O(L)
        if areEqual(strs,i): # O(n)
            longestCommonPrefix+=strs[0][i] # O(1)
        else:
            break
    return longestCommonPrefix #Space: O(L)
