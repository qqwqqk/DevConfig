const sum = require('./math');

test('test 1 plus 2 result',()=>{
  expect(sum(1,2)).toBe(3);
})