//
// Created by Hoang, Quang on 2019-11-21.
//

/**
 * @param {string[]} transactions
 * @return {string[]}
 */
var invalidTransactions = function(a) {
    a = a.map(t => t.split(","));
    res = [];
    for(let i = 0; i < a.length; i++) {
        if (parseInt(a[i][2]) > 1000) res.push(a[i].join(","));
        else {
            for(let j = 0; j < a.length; j++) {
                if (a[i][0] === a[j][0] && a[i][3] !== a[j][3] && Math.abs(parseInt(a[i][1]) - parseInt(a[j][1])) <= 60)
                    res.push(a[i].join(","));
            }
        }
    }
    return [...new Set(res)]
};