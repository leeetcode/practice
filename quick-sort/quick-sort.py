def swap(arr, i, j):
    tmp = arr[i]
    arr[i] = arr[j]
    arr[j] = tmp

def q_sort(arr, start, end):
    seed = start
    j = end - 1
    i = start + 1
    while seed < j:
        if arr[seed] < arr[i]:
            swap(arr, i, j)
            j-=1
        else:
            swap(arr, seed, i)
            seed+=1
            i+=1
    if seed > start +1:
        q_sort(arr, start, seed)
    if end > seed + 2:
        q_sort(arr, seed + 1, end)



def quick_sort(arr):
    q_sort(arr, 0, len(arr))

arr = [4, 9, 7, 4, 3, 0, 1]
print "before sort:"
print arr
quick_sort(arr)
print "after sort:"
print arr
