const sum = require('./math');

function random(){
  let str = "";
  for(let i=0; i<6; i++){
    str += Math.floor(Math.random()*10).toString();
  }
  return str;
};

test('test 1 plus 2 result',()=>{
  
  console.log(random());
  expect(1).toBeTruthy();
})
