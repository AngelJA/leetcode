import {strict as assert} from 'assert';
import * as fs from 'fs';

let test_number = 0;

const runTest = (input: any, expected: any) => {
  test_number += 1;
  console.log(`=== test ${test_number} ===`);
  console.time('test');
  try {
    assert.deepEqual(input, expected);
    console.log('passed!');
  } catch(e) {
    console.log(e);
  }
  console.timeEnd('test');
  console.log('\r');
}

const runTests = (file: string, f: (...args: any[]) => any) => {
  const tests: {
    inputs: any[],
    expected: string[]
  }[] = JSON.parse(fs.readFileSync(file).toString());
  tests.forEach(testCase => {
    runTest(f(...testCase.inputs), testCase.expected);
  });
}

export { runTest, runTests };
