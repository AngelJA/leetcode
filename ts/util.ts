import {strict as assert} from 'assert';

let test_number = 0;

const test = (input: any, expected: any) => {
  test_number += 1;
  console.log(`=== test ${test_number} ===`);
  try {
    assert.deepEqual(input, expected);
    console.log('passed!');
  } catch(e) {
    console.log(e);
  }
  console.log('\r');
}

export { test };
