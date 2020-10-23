
# Assignment 2


Write a program that implements a digital stopwatch in C++ using pthreads. The stopwatch has one display on command line and three buttons (i.e., input keys). 

The display shows elapsed time as follows:

    MM:SS.d

where MM are two digits for minutes, SS are two digits for seconds, and d is one digit for deciseconds (1/10th of a second). Each component of the stopwatch should be controlled by a separate thread; i.e. one thread for minutes, one thread for seconds, and one thread for deciseconds, with the appropriate synchronization between them. 

The three input keys are start (`S`), pause (`P`) and reset (`R`) from your keyboard. Each key works as follows: start to start ticking, pause to stop the stopwatch from ticking, and reset to clear display to “00:00.0”. The reset key is enabled only when the stopwatch is in the stop mode.  If the start key is pushed when the timer is on pause, it will continue ticking from where it was paused.

The semantics of key pushes is as follows:

(1) S (start) key: start ticking
(2) P (pause) key: stop ticking
(3) R (reset) key: reset the counter to “00:00.0” if the stopwatch is paused. If the stopwatch is ticking, it should continue ticking without zeroing the time value (i.e., no effect).

A return / enter press is expected after each key press. Multiple commands that are not separated by a return should be considered invalid.

Your stopwatch must work on any sequence of commands; for example, “SPR”, “RPS”, or “SSRSSP” (here, the 2nd S (start) and the next R (reset) should have no effects.

Note that the carriage return character, `\r`, can be used to overwrite text on the command line; e.g. to overwrite the time 00:00.0 with 00:00.1, rather than proceeding to the next line. Additionally, `setbuf(stdout, NULL);` can be used to disable buffering of standard out, allowing output to be printed to the console without newlines.

The assignment should be completed in C++.  You should explain/justify how well your program keeps time.

__Due: 11:59 pm, Monday, Sept 21, 2020__
Late Policy: 3% off for every 24 hours late.  No submissions will be accepted after 1 week from the due date.

Submission instructions:

The assignment should be submitted via Codio in this workspace. When you have completed the assignment, mark the assignment as completed (through the “Education” dropdown). Note, once you have marked an assignment as completed, it will be read-only; if this was a mistake, contact one of the TAs to re-enable the assignment. Your submission should include the following:

1) The source code and necessary files that will be used for compiling your program on Codio. The files should be consistent with your instructions on how to compile/run your timer.

2) A writeup (text or Markdown), in which you should:
  2a. Give step-by-step instructions on how to compile and run your timer in the Codio environment. 
  2b. Explain the accuracy of your timer implementation by providing convincing evidence and arguments. For example, you may test your timer against a reference clock, list the factors that you think may affect your timer’s accuracy and try to bound the accuracy by referring to the documentation of the programming language (C++) / OS (Ubuntu) that you use.  Also, state explicitly any timing assumptions on system calls that you have used in your arguments.


## Skeleton Code
The current Makefile will automatically compile all `.cpp` and `.h` files present in the folder into an executable named `assignment2`. It is already configured to include the pthread library. In the terminal (Tools->Terminal), run `make` to compile the program, `make clean` to delete the compiled files, and `./assignment2` to run the executable.

Updated on 9/8/20.
