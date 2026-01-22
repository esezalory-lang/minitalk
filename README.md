*This project has been created as part
of the 42 curriculum by esezalor*

## Description
You must create a communication program in the form of a **client** and a **server**
* The client must send the specified string to the server. Once received, the server must print it
    * The server must display the string without delay

**Bonus Description**
* The server must acknowledge each received message by sending a signal to the client.
* Must support unicode characters (emojis)!

## Instructions

If you are running on MacOS, in the header file `minitalk.h` you must remove the following:
```c
# define _POSIX_SOURCE
# define _DEFAULT_SOURCE
```
as certain signal handling functions are already exposed by default.

The ideal first step after you git clone the repo is to proceed with the `make` and `make clean` command in order to compile all files and only have the two executables `./server` and `./client`.

You must have two terminals in front of you so you can run each executable side by side.
Within the first terminal, in your command line run the `./server` executable first which will output: `"Server PID: XXXX"` followed by a newline

In your second terminal you can then run `./client [PID_SERVER] [STRING_TO_PASS]`

Without delay you will see in the server terminal your message displayed followed by a newline as well as in your client terminal a message that reads `"Message Received"`

You can then reproduce this behavior with messages that approach the terminal's input limit, as well as with emojis.


## Resources
I first read through the various Linux manual pages for the definitions of signal-related functions, and their respective properties.

I also read through the signal handling section in the [GNU Library](https://sourceware.org/glibc/manual/2.42/html_mono/libc.html#Signal-Handling) to get a better sense of how the signal handling ecosystem works.

Additionally Jacob Sorber' [video](https://www.youtube.com/watch?v=83M5-NPDeWs&pp=ygUJc2lnYWN0aW9u0gcJCYcKAYcqIYzv) on how to handle signals was very helpful.

I also acknowledge the usage of Gemini's Thinking and Pro models with the ***"Guided Learning"*** parameter on to further deepen my understanding of signals.
If you also want a visual global overview of the workflow of the push_swap code, below is the Obsidian workflow:
file:///home/esezalor/Downloads/Minitalk%20Diagram.png
