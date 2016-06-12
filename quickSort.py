def quickSort(data):
    if len(data) == 0 or not isinstance(data, (list, str)):
        return []
    pivot = data[0]
    left = [x for x in data[1:] if x <= pivot]
    right = [x for x in data[1:] if x > pivot]
    return quickSort(left) + [pivot] + quickSort(right)

if __name__ == '__main__':
    data = [2, 3, 4, 1, 3, -1, 0]
    data = quickSort(data)
    print(data)
