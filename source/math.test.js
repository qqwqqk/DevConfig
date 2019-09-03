const sum = require('./math');

function random(){
  let str = "";
  for(let i=0; i<6; i++){
    str += Math.floor(Math.random()*10).toString();
  }
  return str;
};

function delbrackets(str){
  let res = "";
  let count = 0;
  for(let i = 0 ; i < str.length; i++){
    if(str[i] == '('){ count++ ; continue; }
    if(str[i] == ')'){ count-- ; continue; }
    if(count == 0){res += str[i];}
  }
  return res;
}

function delbackspace(str){
  let res = "";
  for(let i = 0 ; i < str.length; i++){
    if(str[i] == '<' && res.length > 0){ res = res.substring(0, res.length-1) ;}
    if(str[i] != '<') { res += str[i];}
  }
  return res;
}

let str = read_line();
let str1 = delbrackets(str);
let str2 = delbackspace(str1);
console.log(str2);

function read(str){
  let str1 = delbrackets(str);
  let str2 = delbackspace(str1);
  return str2;
}
let str = read_line();
read(str);

test('test 1 plus 2 result',()=>{
  
  var arr="a<<b((c)<)fff(dd)<";
  var result = "bff";

  expect(read(arr)).toEqual(result);
})
