function largestGoodInteger(num: string): string {
  for (let i = 9; i >= 0; i--) {
    const s = i.toString().repeat(3);
    if (num.indexOf(s) >= 0) return s;
  }
  return "";
}

console.log(largestGoodInteger("6777133339"));
