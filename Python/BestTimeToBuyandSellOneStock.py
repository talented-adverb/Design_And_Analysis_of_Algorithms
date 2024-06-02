'''
(buyday , SellDay) => sellDay > buyDay

Input: prices=[7,1,5,3,6,4]
Output: 5

Input: prices=[7,6,4,3,1]
Output: 0

if profit in -ve then it is taken as 0
'''

# def maxProfit(prices: list[int])-> int: # O(n^2) / O(1)
#     maxProfit = 0
#     for buyDay in range(len(prices)-1): # O(n)
#         for sellDay in range(buyDay+1,len(prices)): # O(n)
#             currProfit=prices[sellDay]-prices[buyDay]
#             if currProfit > maxProfit:
#                 maxProfit=currProfit
#     return maxProfit

'''
(buyday , SellDay) => sellDay > buyDay

Input: prices=[7,1,5,3,6,4]
buyDay = 1 => sellingPrice -1, where sellingPrice is from {5,3,6,4}
sellingPrice is max(5,3,6,4)
Output: 6-1=5
buyDay = 2 => sellingPrice -5, where sellingPrice is from {3,6,4}
sellingPrice is max(3,6,4)
Output: 6-5=1

'''
# def maxProfit(prices: list[int])-> int: # O(n^2) / O(1)
#     maxProfit = 0
#     for buyDay in range(len(prices)-1): # O(n)
#         currMaxProfit=max(prices[buyDay+1:])-prices[buyDay] 
#         #   O(n) Subarray's timecomplexity Also max function traverses the whole list so-> O(n)
#         maxProfit=max(maxProfit,currMaxProfit)
#     return maxProfit

# O(n^2)->O(n)

'''
We can also loop from the starting where we know the sellDay
and find the buyDay that has the min price
'''

def maxProfit(prices: list[int])-> int: # O(n) / O(1)
    maxProfit=0
    maxPrice=prices[-1]
    for buyDay in range(len(prices)-2,-1,-1): # O(n)
        currMaxProfit= maxPrice - prices[buyDay]
        maxProfit= max(maxProfit,currMaxProfit)
        maxPrice=max(maxPrice,prices[buyDay])
    return maxProfit

prices=[7,6,4,3,1]
print(maxProfit(prices))
