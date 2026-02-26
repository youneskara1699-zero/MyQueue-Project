MyQueue Project - C++ Queue Implementation

Overview

A comprehensive C++ implementation of a Queue data structure built on a custom doubly linked list. This project showcases object-oriented design patterns and generic programming techniques.

Features

Generic Type Support: Template-based design works with any data type

Core Queue Operations: Push, Pop, Front, Back, Size, Clear

Extended Functionality: Reverse, Update items, Insert at any position

Efficient Memory Management: Automatic cleanup with no memory leaks

Architecture

clsDblLinkedList<T>: Foundation doubly linked list with complete CRUD operations

clsMyQueue<T>: Queue wrapper providing FIFO (First-In-First-Out) interface

Primary Operations
Push: Add element to the back of queue

Pop: Remove element from the front of queue

Front/Back: Access elements at both ends

GetItem: Access element by index position

Learning Outcomes

This implementation demonstrates:

Queue (FIFO) data structure principles

Doubly linked list internals

Class inheritance and composition

Template metaprogramming

Manual memory management

Exception-safe design

Technical Requirements

C++ compiler (C++11 or later recommended)

Standard Template Library (STL) not required

Reverse: Invert the entire queue order

Clear: Remove all elements
