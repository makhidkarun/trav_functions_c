# This repo is ARCHIVED
Please see the Issues for reasons. We encourage contributions, if you want to contribute to the code base please ask a group moderator to unarchive the repo.



trav_functions_c
================

C based functions for Traveller

```
die_roller:
Usage:  die_roller [options]  
	 -a    Number, positive or negative, to be added to the total
	 -e    Explode die if roll MAX
	 -f    Roll dice as flux
	 -h    Help information
	 -m    Minimum die number
	 -M    Maximum die number
	 -n    Number of die
	 -t    Return 0 if roll vs target number. Defaults to -t 8
	 -V    Version information
```

Of the options, -a, -m, -M, -n, and -t require an extra argument.
For example, 
    ```
    die_roller -n 2 -m 1 -M 6
    ```

Would roll 2d6. This is the default action, given no other options.


trav_chargen:
-a <stats>, -s <stats>
Default is 2-C.


dice.c/dice.h:
Various dice conventions in one library.


