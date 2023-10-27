function insertAtIndex(arr, size, index) {
  for (let i = index; i < size; i++) {
    arr[i] = arr[i + 1];
  }
}
let arr = [10, 2, 4, 5, null, null];
insertAtIndex(arr, 4, 2);
console.log({ arr });
