/**
 * @param {number[]} ages
 * @return {number}
 */

const request = function (a, b) {

    a *= 1;
    b *= 1;

    return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
}

var numFriendRequests = function (ages) {

    let count = new Map();


    ages.forEach(function (age) {

        if (count.has(age)) {
            count.set(age, count.get(age) + 1);
        } else {
            count.set(age, 1);
        }

    });

    let res = 0;

    let countKeys = Array.from(count.keys());



    countKeys.forEach(function (a) {
        countKeys.forEach(function (b) {

            a *= 1;
            b *= 1;

            if (request(a, b)) {
                if (a == b) {
                    res += count.get(a) * (count.get(b) - 1);
                } else {
                    res += count.get(a) * count.get(b);
                }
            }

        })
    })

    return res;


};

console.log(numFriendRequests([14, 14, 15]));   // 0
console.log(numFriendRequests([1, 3, 4, 7]));   // 0
console.log(numFriendRequests([16, 16]));       // 2
console.log(numFriendRequests([16, 17, 18]));   // 2
console.log(numFriendRequests([20, 30, 100, 110, 120]));    // 3
