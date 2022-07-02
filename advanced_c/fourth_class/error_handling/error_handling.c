// Handling errors in c
// CONVENTIONS
// 1) ---> if the function returns a pointer
/**
here we return 0 on error
**/

// 2) ---> if the function returns void
/**
here we return 0 on error
**/

// 2) ---> if the function returns a value which is not a pointer
/**
We will transform into something returning a status cause thats the aim
res = int f(....) -> status = f(...., int * res)
this is practical below
i = top(s)  --> st top(s, &i)

THE ABOVE IS THE BASIC CONCEPT
**/
