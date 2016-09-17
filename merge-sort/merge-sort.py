def m_sort(arr, arr1, start, end):
    mid = (start + end)/2
    if mid > start + 1:
        m_sort(arr, arr1, start, mid)
    if end > mid + 1:
        m_sort(arr, arr1, mid, end)

    i = start
    j = mid
    k = start
    while i < mid and j < end:
        if arr[i] < arr[j]:
            arr1[k] = arr[i]
            i+=1
        else:
            arr1[k] = arr[j]
            j+=1
        k += 1
    while i < mid:
        arr1[k] = arr[i]
        i+=1
        k+=1
    while j < end:
        arr1[k] = arr[j]
        j+=1
        k+=1
    for index in range(start, end):
        arr[index] = arr1[index]

def merge_sort(arr):
    arr1 = [0] * len(arr)
    m_sort(arr, arr1, 0, len(arr))


arr = [4, 9, 7, 4, 3, 0, 1]
print "before sort:"
print arr
merge_sort(arr)
print "after sort:"
print arr
