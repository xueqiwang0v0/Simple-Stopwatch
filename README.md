
# Stopwatch

A program that implements a digital stopwatch in C++ using pthreads. The stopwatch has one display on command line and three buttons (i.e., input keys). 

The display shows elapsed time as follows:

    MM:SS.d

where MM are two digits for minutes, SS are two digits for seconds, and d is one digit for deciseconds (1/10th of a second). Each component of the stopwatch should be controlled by a separate thread; i.e. one thread for minutes, one thread for seconds, and one thread for deciseconds, with the appropriate synchronization between them. 

The three input keys are start (`S`), pause (`P`) and reset (`R`) from your keyboard. Each key works as follows: start to start ticking, pause to stop the stopwatch from ticking, and reset to clear display to “00:00.0”. The reset key is enabled only when the stopwatch is in the stop mode.  If the start key is pushed when the timer is on pause, it will continue ticking from where it was paused.

The semantics of key pushes is as follows:

(1) S (start) key: start ticking
(2) P (pause) key: stop ticking
(3) R (reset) key: reset the counter to “00:00.0” if the stopwatch is paused. If the stopwatch is ticking, it should continue ticking without zeroing the time value (i.e., no effect).

A return / enter press is expected after each key press. Multiple commands that are not separated by a return should be considered invalid.

The stopwatch works on any sequence of commands; for example, “SPR”, “RPS”, or “SSRSSP” (here, the 2nd S (start) and the next R (reset) should have no effects.

This is assignment 2 of the course CIS 541 at UPenn.

Updated on 2020/10/22.
