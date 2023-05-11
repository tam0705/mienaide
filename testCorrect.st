{%
    B10915013
    Test program
%}

% global variables
const  n: int := 8
var i := 1

% iterative function
function itFibonacci (n: int) : int
  var Fn: int
  var FNminus1: int
  var temp: int

  Fn := 1
  FNminus1 := 1
  loop
    exit when (n <= 2) 
    temp := Fn
    Fn := Fn + FNminus1
    FNminus1 := temp
    n := n - 1
  end loop
  result Fn
end itFibonacci

% main program 
put "N: "
put n
skip
put "Result of iterative computation:\n"
for decreasing i : n .. 1
    put i
    put ": "
    put itFibonacci(i)
    put "\n"
end for
