/* Corey Garvey - July 12
 * Javascript Closures */

function sayHello(name) {
    var text = "Hello " + name;
    var say = function() { console.log(text); }
    say();
}
console.log("Ex 1: ");
sayHello('Joe');

function sayHello2(name) {
    var text = "Hello " + name; //local variable
    var say = function() { console.log(text); }
    return say;
}
console.log("Ex 2: ");
var say2 = sayHello2('Bob');
say2();


// Variable remains within closure
function say667() {
    // Local var that ends up within closure
    var num = 42;
    var say = function() { console.log(num); }
    num++;
    return say;
}
console.log("Ex 3: ");
var sayNumber = say667();
sayNumber(); // 43 


// Global functions declared within closure
var gLogNumber, gIncreaseNumber, gSetNumber;
function setupSomeGlobals() {
    var num = 42;
    gLogNumber = function() { console.log(num); }
    gIncreaseNumber = function() { num++; }
    gSetNumber = function(x) { num = x; }
}
console.log("Ex 4: ");
setupSomeGlobals();
gIncreaseNumber();
gLogNumber(); // 43
gSetNumber(5);
gLogNumber(); // 5

var oldLog = gLogNumber // 5
setupSomeGlobals();
gLogNumber(); // 42
oldLog(); // 5

// Defining functions within a loop
function buildList(list) {
    var result = [];
    for (var i=0; i<list.length; i++){
        var item = 'item' + i;
        var item_value = list[i];
        // item_value is 3 for all uses of this function because that is
        //      the most recently defined value of list[i] when it is run
        //      list[i] is undefined because i has gone to 3, and there is no list[3]
        result.push( function() { console.log(item + ' ' + list[i] + ' ' + i)});
    }
    return result;
}
function testList() {
    var fnList = buildList([1,2,3]);
    for (var j=0; j<fnList.length; j++){
        fnList[j]();
    }
}
console.log("Ex 5: ");
testList();

function sayAlice() {
    var say = function() { console.log(alice); }
    var alice = "Hello Alice";
    return say;
}
console.log("Ex 6: ");
sayAlice()();
// Above calls function returned from sayAlice()
//  Instantiation and call separated below
var alice = sayAlice();
alice();

function newClosure(someNum, someRef){
    var num = someNum;
    var anArray = [1,2,3];
    var ref = someRef;
    return function(x) {
        num += x;
        anArray.push(num);
        console.log('num: ' + num +
            '; anArray: ' + anArray.toString() +
            '; ref.someVar: ' + ref.someVar + ';');
    }
}
console.log("Ex 7: ");
obj = { someVar: 4 };
fn1 = newClosure(4, obj);
fn2 = newClosure(5, obj);
fn1(1);
fn2(1);
obj.someVar++;
fn1(2);
fn2(2);
