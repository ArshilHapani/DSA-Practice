class ArrayADT {
  constructor(totalSize, usedSize) {
    this.totalSize = totalSize;
    this.usedSize = usedSize;
    this.myArray = Array(usedSize);
  }
  set(values) {
    for (let index = 0; index < this.usedSize; index++) {
      this.myArray[index] = values[index];
    }
  }
  show() {
    for (let index = 0; index < this.usedSize; index++) {
      console.log(this.myArray[index]);
    }
  }
}

let ot = new ArrayADT(10, 3);
ot.set([1, 2, 3]);
ot.show();
console.log(ot.myArray);
