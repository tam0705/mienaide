function a(a:int, b:int, c:int):int
	result a + (b + c) + a + c
end a

function b(a:int):int
	result 2 * a
end b

function c(c:int):int
	result c / 2.5
end c

% put a(b(a(1,2,3)), 1, c(b(1)))

put "n"