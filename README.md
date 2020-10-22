# cpp-sort-algorithim

## The Rundown
This program finds the user specified number in a user specified group. It illustrates a divide and conquer algorithim for sorted lists.

## The Algorithim.
The actual algorithim first tests the two extremes. Then depending on whether it's too high or too low, it splits the group in half. Then it recursively does this eliminating half of the group size each time. For example, if you have ten numbers as such and **3** is the selected number to find:

```
1   2   [3]   4   5   6   7   8   9   10
```

First it test #1. Returning too low it removes #1 from the group and tests the extreme: #10. This returns too high. From there we remove 10 and test the middle vaue: #5, which returns too high. The algorithim thus deletes all # >= 5. From there it splits the group in half again. Now with only 2, 3 ,4 remaining it selects the middle value again: which happens to be 3 our selected number. 

