'''
Problem: https://www.geeksforgeeks.org/coin-change-dp-7/
Intuition: countSum?
'''

def CoinChange(target, coins):
    table = []
    for i in range(target + 1):
        table.append(0)
    table[0] = 1
    print(table)
    for i in range(len(table)):
        for j in range(len(coins)):
            if i + coins[j] <= target:
                index = i + coins[j]
                table[index] += table[i]
        print(table)
    return table[target]

print(CoinChange(4, [1,2,3]))
#print(CoinChange(10, [2,5,3,6]))