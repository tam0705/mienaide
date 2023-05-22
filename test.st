{%
    B10915013
    Test program
%}

% global variables
const  n: int := 8
var i := 1
var arr : array 1 .. 8 of int

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

function deep(val: bool) : string
  loop
    exit when true
    if val then
      result "yes"
    else
      result "no"
    end if
  end loop
end deep

procedure putArray(num: int, a: array 1 .. 8 of int)
  for i : 1 .. n
    a[i] := num - 1
    if (a[i] < 1) then
      a[i] := 1
    end if
    put itFibonacci(a[i]) + num
    put "\n"
  end for
end putArray

procedure fakeMain()
  put "N: "
  put n
  skip
  put "Result of iterative computation:\n"
  putArray(10, arr)
end fakeMain

% main program
begin
  var s: string := "Don't mind me"
  var ss := "I'm just for test purposes"
  var r: real := 1 + 1.0 * (2.5 - 3) / 2.7
  put s
  put ss
  put deep(true)
  arr[1] := 0
end

fakeMain()
