# 
def bin_search(arr, start, end, key):
    if end - start == 1:
        if arr[start] == key:
            return start
        else:
            return -1
    mid = (start + end)/2
    if arr[mid] == key:
        return mid
    elif arr[mid] > key:
        return bin_search(arr, start, mid, key)
    else:
        return bin_search(arr, mid, end, key)

# [50, 89, 97, 103, 19, 22, 36, 45]
def fold_bin_search(arr, start, end, key):
    if end - start == 1:
        if arr[start] == key:
            return start
        else:
            return -1
    mid = (start + end)/2
    if arr[mid] == key:
        return mid
    elif arr[mid] < arr[end - 1]:
        if arr[mid] <= key and key <= arr[end - 1]:
            return bin_search(arr, mid, end, key)
        else:
            return fold_bin_search(arr, start, mid, key)
    else:
        if arr[start] <= key and key <= arr[mid - 1]:
            return bin_search(arr, start, mid, key)
        else:
            return fold_bin_search(arr, mid, end, key)


arr = [50, 89, 97, 103, 19, 22, 36, 45]
print arr
for elem in arr:
    index = fold_bin_search(arr, 0, 8, elem)
    if index == -1:
        print "error. elem " + str(elem) + " not found!"
    else:
        print "elem " + str(elem) + " found. index:" + str(index)

ano_arr = [11, 25, 35, 52, 65, 99, 180]
for elem in ano_arr:
    index = fold_bin_search(arr, 0, 8, elem)
    print "elem " + str(elem) + " no found. index:" + str(index)
