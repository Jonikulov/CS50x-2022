// Binary Search Algorithm
If no doors
    return false
If number behind doors[middle]
    return true
else if number < doors[middle]
    search doors[0] through doors[middle - 1]
else if number > doors[middle]
    search doors[middle + 1] through [n - 1]
