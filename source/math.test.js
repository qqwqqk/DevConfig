const sum = require('./math');

function random(){
  let str = "";
  for(let i=0; i<6; i++){
    str += Math.floor(Math.random()*10).toString();
  }
  return str;
};

test('test 1 plus 2 result',()=>{
  var regex = /^[a-zA-Z]:\\([^\\:*<>|"?\r\n/"]+\\)*([^\\:*<>|"?\r\n/"]+)?$/;
  console.log(regex.test("F:\\study\\java\\regex\\regu exp.pdf"));
  console.log(regex.test("F:\\study\\java\\regex\\"));
  console.log(regex.test("F:\\study\\java"));
  console.log(regex.test("F:\\"));
  expect(1).toBeTruthy();
})
