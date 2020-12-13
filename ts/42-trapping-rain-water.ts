import {strict as assert} from 'assert';

const trap = (height: number[]) => {
  if (height.length === 0) {
    return 0;
  }
  const lpass = depthPass(height);
  const rpass = depthPass(height.reverse()).reverse();
  return lpass.reduce((sum, x, i) => {
    return sum + Math.min(x, rpass[i]);
  });
};

const depthPass = (height: number[]) => {
  let h = 0;
  return height.map(x => {
    h = Math.max(h, x);
    return h - x;
  });
};

assert.equal(trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]), 6);
assert.equal(trap([4, 2, 0, 3, 2, 5]), 9);
