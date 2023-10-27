function insertAtIndex(arr, size, element, index, totalSize) {
  if (size >= totalSize) {
    return false;
  }
  for (let i = size - 1; i >= index; i--) {
    arr[i + 1] = arr[i];
  }
  arr[index] = element;
  size++;
  console.log(arr);
  return true;
}

function insertInSortedArray(arr, size, element, totalSize) {
  if (size >= totalSize) {
    return false;
  }
  let i = size - 1;
  while (i > 0 && arr[i] > element) {
    arr[i + 1] = arr[i];
    i--;
  }
  arr[i + 1] = element;
  console.log(arr);
}
insertAtIndex([10, 2, 4, 5, null, null], 4, 3, 2, 6);
insertInSortedArray([1, 3, 5, 6], 4, 4, 5);
