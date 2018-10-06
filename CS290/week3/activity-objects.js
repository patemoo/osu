
function deepEqual(itemOne, itemTwo) {
    let isEqual = true;
    if ((itemOne && (typeof itemOne === 'object')) && (itemTwo && (typeof itemTwo === 'object'))) {
        for (key in itemOne) {
            if (!deepEqual(itemOne[key], itemTwo[key])) {
                return false;
            }
        }
    } else {
        if (itemOne !== itemTwo) {
            return false;
        }
    }
    return isEqual;
}

let obj = {here: {is: "an"}, object: 2};
console.log(deepEqual(obj, obj));
// → true
console.log(deepEqual(obj, {here: 1, object: 2}));
// → false
console.log(deepEqual(obj, {here: {is: "an"}, object: 2}));
// → true