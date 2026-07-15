Find maximum profit from buying and selling stock once.

Algorithm:
1. Track minimum price seen so far
2. For each price, calculate profit if selling today
3. Update maximum profit

Key Insight:
- Buy at lowest price before current day
- Sell at current price for maximum profit
- One pass solution
