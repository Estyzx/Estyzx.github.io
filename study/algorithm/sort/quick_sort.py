def quick_sort(arr, l, r):
    if l >= r:
        return
    pivot = arr[l]
    i = l+1
    j = r
    while i <= j:
        while i <= j and arr[j] > pivot:
            j -= 1
        while i <= j and arr[i] < pivot:
            i += 1
        if i <= j:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1
    arr[l], arr[j] = arr[j], arr[l]
    quick_sort(arr, l, j - 1)
    quick_sort(arr, j + 1, r)


arr = [5, 4, 3, 2, 1]
print(arr)
quick_sort(arr, 0, len(arr) - 1)
print(arr)
