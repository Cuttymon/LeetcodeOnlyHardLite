const memo = {};

function isMatch(s: string, p: string): boolean {
    const key = s + ' ' + p;
    const matchedMemo = memo[key];
    if (matchedMemo !== undefined) {
        return matchedMemo;
    }

    if (s.length === 0 && p.length === 0) {
        memo[key] = true;
        return true;
    }

    if (p.length === 0) {
        memo[key] = false;
        return false;
    }

    let result = false;
    const trimedS = 0 < s.length ? s.slice(1, s.length) : null;
    if (p[1] === '*') {
        const trimedP = 0 < p.length ? p.slice(2, p.length) : null;
        if (p[0] === '.' || p[0] === s[0]) {
            result = (trimedP !== null && isMatch(s, trimedP)) ||
                (trimedS !== null && isMatch(trimedS, p)) ||
                (trimedS !== null && trimedP !== null && isMatch(trimedS, trimedP));
        } else {
            result = trimedP !== null && isMatch(s, trimedP)
        }
    } else {
        const trimedP = 0 < p.length ? p.slice(1, p.length) : null;
        if (p[0] === '.' || p[0] === s[0]) {
            result = trimedS !== null && trimedP !== null && isMatch(trimedS, trimedP)
        } else {
            result = false;
        }
    }

    memo[key] = result;
    return result;
};