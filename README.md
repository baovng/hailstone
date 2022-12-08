# CSF-hailstone

## Due: December 07 by 23:59:59

---

## Introduction

The purpose of this programming project is for you to be familiar with the software architecture of client-server programs written in C in a Linux environment. This can be accomplished by modifying the sample client-server programs provided on our course website. Suggestion: Read this assignment multiple times so you have a clear picture how to complete this assignment.

The Hailstone sequence is an integer sequence based on the rule:
Given an arbitrary positive integer $n$:

1. If $n$ mod $2 == 0$, then $n = n / 2$, otherwise $n = 3*n+1$.
2. Repeat step 1

**_The Collatz conjecture states that this process will eventually reach the number 1, regardless of which positive integer $n$ is chosen initially._**

## Logistics

1. This is an individual project.
2. Submit your solution via GitHub Classroom.
3. Clarifications and corrections will be sent to the class via TCU email.
4. You may do your work on your own personal computer.
5. Your program will be tested on `babbage.cs.tcu.edu`.
6. This project is worth 100 points.

## Modifications Summary

Modify your "echo server" into a "hailstone sequence server". Modify your client program to prompt and read a single, positive integer from standard input. This integer will be sent to the server. The server process will send back the integers of the hailstone sequence one integer at a time back to the client. Extra output messages are used to verify proper execution of the client and the server.

## Project Setup

Rename the files as follows:

1. Rename the file `echoclient.c` to `client.c`.
2. Rename the file `echoserverp.c` to `server.c`.
3. Rename the file `echo.c` to `compute.c`.

Using the new file names, edit `compute.c` and change the name of the function from `echo` to `compute`. You will also have to change the name of the function prototype from `echo` to `compute` in `server.c`.

To build the client program use the following compile statement:

```text
gcc –I. -o client client.c csapp.c
```

To build the server program use the following compile statement:

```text
gcc –I. –o server server.c compute.c csapp.c
```

Create a `Makefile` for your client and server programs. This makefile must be able to create or update one or both programs by just typing a single `make` command. Do not continue with the project unless you have this part working. If you are having difficulties, you may ask a classmate to help you or send me an email or stop by my office hours.

## Running Your Project

Start and test the existing client-server programs. Verify that they are working. This will demonstrate an "echo server".

1. Open two terminal windows. Have both terminal windows in your project subdirectory.
2. Start the server in one of the terminal windows. It will appear that nothing is happening (blinking cursor).

```text
babbage$ ./server 30203
```

3. Now start the client program in the other terminal window. It will also appear that nothing is happening.

```text
babbage$ ./client localhost 30203
```

4. On the client terminal type a short message. The message will (should) be read by the client process, sent to the server process, and then sent back to the client process. The client process will print the string it received from the server to standard output.

## Client Program Modifications

1. The client program will have two command line arguments: the IP address or web address of the server and the port number.
2. Once the client has made a successful connection to the server:port, output a "connection established message".
3. Read the "welcome message" from the server and display it to standard output.
4. Read a positive integer from standard input. The client will perform data validation. If the integer is zero or negative, prompt the user to re-enter a positive integer.
5. Send the integer to the server. It may be best to send the integer to the server as a character string.
6. The client will then receive and output messages from the server until EOF.
7. Repeat steps 4-6 until user enters ^d to stop reading integers.
8. Program exits without errors.

**Refer to the sample execution section below. The output must look identical.**

## Server Program Modifications

1. Add extra `printf()` statements at various locations in the server program to verify proper execution. See sample execution below.
2. Use the `Getnameinfo()` function to get the hostname and hostport information.
3. Modify the `compute()` function to generate the integers for the hailstone sequence of integer $n$. Each integer computed should be converted into a string.
4. Each message sent back to the client will have a prefix of `[HSS:n:m]`. The "HSS" is shorthand for Hailstone Sequence Server. The $n$ is the $n^{th}$ integer connection established. The $m$ is the $m^{th}$ message sent to the client. See sample execution below for examples.

**Refer to the sample execution section below. The output must look identical**

## Sample Execution

Here is a sample execution with respect to the client.

```text
babbage$ ./client localhost 30203 [ENTER]
--> Hailstone Sequence Client v1.0
--> Connection Established To localhost Port 30203
[HSS:1:1] Welcome to the Hailstone Sequence Server v1.0

--> Enter A Positive Integer (^d to quit): 8
[HSS:2:2] Starting with 8
[HSS:2:3] 4
[HSS:2:4] 2
[HSS:2:5] 1
[HSS:2:6] Finished.  Number of iterations = 3

--> Enter A Positive Integer (^d to quit): 11
[HSS:3:2] Starting with 11
[HSS:3:3] 34
[HSS:3:4] 17
[HSS:3:5] 52
[HSS:3:6] 26
[HSS:3:7] 13
[HSS:3:8] 40
[HSS:3:9] 20
[HSS:3:10] 10
[HSS:3:11] 5
[HSS:3:12] 16
[HSS:3:13] 8
[HSS:3:14] 4
[HSS:3:15] 2
[HSS:3:16] 1
[HSS:3:17] Finished.  Number of iterations = 14

--> Enter A Positive Integer (^d to quit): ^d
--> Disconnected from localhost port 30203.  Goodbye.
babbage$
```

Here is sample execution with respect to the server.

```text
babbage$ ./server 30203 [ENTER]
Hailstone Sequence Server v1.0
Listening On Port 30203

Waiting for connection...
Server connected to localhost (127.0.0.1:46226)
Received 8
Sending sequence
Closing connection

Waiting for connection...
Server connected to localhost (127.0.0.1:42162)
Received 11
Sending sequence
Closing connection

Waiting for connection...
^c
babbage$
```
