This problem uses a monotonic decreasing stack. We traverse the temperature array from right to left and maintain indices of days
with higher temperatures. For each day, we pop all indices with temperatures less than or equal to the current
day and calculate the difference to find the next warmer day.