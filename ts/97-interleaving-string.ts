import {strict as assert} from 'assert';

const isInterleave = (s1: string, s2: string, s3: string): boolean => {
  return r(s1, 0, s2, 0, s3, 0);
};

const r = (
  s1: string,
  i: number,
  s2: string,
  j: number,
  s3: string,
  k: number
): boolean => {
  if (k === s3.length) {
    return i === s1.length && j === s2.length;
  }
  if (s3[k] === s1[i]) {
    if (r(s1, i + 1, s2, j, s3, k + 1)) {
      return true;
    }
  }
  if (s3[k] === s2[j]) {
    return r(s1, i, s2, j + 1, s3, k + 1);
  }
  return false;
};

let s1 = 'aabcc';
let s2 = 'dbbca';
let s3 = 'aadbbcbcac';
assert.equal(isInterleave(s1, s2, s3), true);

s1 = 'aabcc';
s2 = 'dbbca';
s3 = 'aadbbbaccc';
assert.equal(isInterleave(s1, s2, s3), false);

s1 = '';
s2 = '';
s3 = 'a';
assert.equal(isInterleave(s1, s2, s3), false);

s1 = 'a';
s2 = '';
s3 = 'aa';
assert.equal(isInterleave(s1, s2, s3), false);

s1 = 'a';
s2 = 'bb';
s3 = 'baa';
assert.equal(isInterleave(s1, s2, s3), false);

s1 = 'a';
s2 = 'b';
s3 = 'a';
assert.equal(isInterleave(s1, s2, s3), false);
