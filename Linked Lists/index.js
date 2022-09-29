

let arr = [1, 2, 3, 4, 5]

arr.reduce((acc, el) => {
    return acc * el;
}, 1)


Array.prototype.myReduce = function (cb, initialValue) {
    let array = this;
    let acc = initialValue ? initialValue : array[0];
    let startIndex = initialValue ? 0 : 1;

    for (let i = startIndex; i < array.length; i++) {
        acc = cb(acc, array[i]);
    }

    return acc;
}

arr.myReduce((acc, el) => {
    return acc * el;
}, 1)