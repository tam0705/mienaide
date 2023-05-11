B10915013 Compiler Project 2

This file is the description of the difference between my old and new lex files.

First of all, the biggest change is the implementation of symbol table.
Previously, I implemented the table inside my lex scanner,
but now it is separated to new files symbols.h and symbols.c.
The reason is so that lex and yacc can use it together.

The next change is how I cannot group similar sentences anymore,
since with each token I have to return different things.
For example, I would previously group all keywords (begin, end, bool, etc.) into one regex group 'keyword',
and I would just print the keyword out all in caps.
But now, I have to disband this group and explicitly specify each keyword what token they should return.

Another change is the location of the main function.
Since there is now yacc file and there can only be one main function in each program,
it should certainly belong to the yacc parser file and not the lex file.

Finally, there are two new items that should be scanned by lex: \r and EOF. This is to fix two issues:
- Without capturing \r, the scanner would regard it as . (any character) instead, thus printing 'bad character' and exiting my program.
  Somehow, in my test file, \r exists in the end of each line together with \n. This does not happen with the first project.
- If the end of file has no \n, the scanner wouldn't print the content of the last line to the console.
  Thus, when EOF is captured, it would print the content of the last line instead.

