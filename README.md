# Infection

Interview problem for Khan Academy internship, Summer 2016.

**Zhihao Li** @ *Carnegie Mellon University*  
[LinkedIn](https://www.linkedin.com/in/lizhihao) |
[Website](http://codinfox.github.io) |
[Email](http://www.google.com/recaptcha/mailhide/d?k=01tG4h5A_4eXHg3FR7Rcjpeg==&c=AL516Fdp41ihb-wT0F8H7wmeQHf4yLuXPQd6uK-aNYc=)

TOC
* [Functional Points](#functional-points)
* [How to run the program](#how-to-run-the-program)
* [Algorithm Design](#algorithm-design)
* [TODOs](#todos)
* [Misc.](#misc)

## Functional Points

- [x] `total_infection`
- [x] `limited_infection`
- [ ] User relationship update (see [TODOs](#todos))

## How to run the program

The program is written in C++ (`-std=c++0x`) with Xcode 7.0.1 on Mac OS X 10.11. The main program does not have a binary file (even it does, it may need to recompile), so the best way to run the program is via Xcode. Just open the Xcode project file, [set the arguments](https://developer.apple.com/library/ios/recipes/xcode_help-scheme_editor/Articles/SchemeRun.html), and ENJOY😃.

### The main program

The main program accepts 1 command line argument, which specifies the "database" file (generated by [testcase_generator](#testcase_generator)).

When running, it is an interactive console like:

```
Incremental Service Console
DB file: ~/Projects/Infection/testcase.txt
** We assume ALL OPERATIONS ARE LEGAL **
>
```

You can input commands after the prompt `>`. The commands include:

1. `t#`, where `#` is a user id. This lists all user ids that have relationship with user `#`. Relationship means either coach or coached by.
2. `l#`, where `#` is a limit number. This lists around `#` many user ids that are infected.
3. Any other commands will quit the program.

**NOTICE: I assume all the operations are legal, which means that no operations will try to query non-existant users.**

### testcase_generator

This little tool helps to generate testcases. The source file for this is `testcase_generator.cpp` and I provide a compiled binary (compiled under `Apple LLVM version 7.0.0 (clang-700.0.72) Target: x86_64-apple-darwin15.0.0`). You may need to recompile it.

The tool accepts 2 command line arguments:

```
./testcase_generator <NUMBER OF USERS> <FORMAT>
```

`<FORMAT>` can be either `cstyle` or `file`, where `cstyle` will generate C++ styled codes that can be pasted directly into the source code (see https://github.com/codinfox/KAInfection/blob/master/Test/testUserGraph.cpp#L34), and `file` will generate a "dababase" file format.

The tool outputs to standard out, so redirection is needed to create a file.

Example:

```
./testcase_generator 1000 file >> testcase.txt
```

This will generate 1000 users and their relationships in the format of a database file, and redirect the output to testcase.txt.

### Unit tests

To run unit tests, first change the Xcode target to Test (by clicking on the project name at the top of the left sidebar). And then run it 👊.

## Algorithm Design

### Model

The problem is modeled as finding the connected components in an undirected graph.

### Assumptions

1. According to 2014's data that Khan Academy has more than 10 million unique users per month and 400 million views of all videos. Therefore, I assume that Khan Academy has ~50 million users in total, which is around 50M.
2. According to my own and my friends using experience with Khan Academy, I assume that most people on Khan Academy does not have any relationship with others, and the number of nodes in a connected component should distributed logarithmically.
3. This incremental deployment service will be used frequently and thus it is reasonable for this service to have its own server to store and update data. Moreover, whenever there is a change in the graph, the data in this server should change as well.
4. Based on assumption 1 and 3, it is feasible to store all the space overhead resulted from the algorithm in memory (we normally will not raise more than 500 bytes overhead per user, which, in total, 25G).
5. Our data structure needs to be easily serializable.
6. Even if we do limited_infection, we still want all users in a cluster infected at the same time.

### Details

I first traverse the whole graph (using BFS and avoid recursion), finding all the connected components and save them. At the same time, roughly partition all the components into 10 categories according to their sizes: 2<sup>0</sup>~2<sup>1</sup>, 2<sup>1</sup>~2<sup>2</sup>, ..., 2<sup>9</sup>~Inf.

The time complexity for traversal is *O*(*n*). And the space complexity for storing the clusters is *O*(*n*).

#### total_infection

Since we have all the clusters saved, just look up the element and return the cluster.

The time complexity is *O*(*1*).

#### limited_infection

Since we partitioned the clusters to 10 categories based on their sizes, to find roughly the limit number of users, we first find the partition where the specified limit is closest to. Starting from this partition, we randomly choose one cluster from it and add all its users in to the result set. If the size of the result set if smaller than the limit, randomly choose another one from this partition. If there is no more clusters in this partition to choose from, randomly choose one from the smaller partitions.

Worst-case time complexity is *O*(*n*), *n* is the limit. On average, it is approximately *O*(log*n*).

## TODOs

At the very beginning when I first see this problem, I consider this incremental deployment service as a constantly running program. Therefore, when solving it, I also try to take the graph update into consideration. That one of the reasons [why I use `KVector`](#why-kvector) over `vector`. However, due to time limit (and I really don't want to spend too much time on this, although it's interesting), I fail to implement the update algorithm. But I would like to describe here.

### User relationship update

After that we have found all the connected components, we want to update the connected components when the graph changes instead of re-computing all the connected components. There are totally 3 cases for graph change:

1. A new user is added into the graph. This will not change the clusters at all.
2. A user from component A links to component B. In this case, we just need to merge the 2 components and update all its users' `cluster_id`. With `KVector`, this is fast.
3. A user leaves component A. In this case, we need to traverse the whole component to see if the leaving of A leads to the split of he component. This is usually cheap.

## Misc.

### Why `KVector`
`KVector` is an adapter to `std::vector`, but supports faster remove by recording the free slots resulted from element removal. The idea is taken from cache, where element is not really removed but marked as removed. Next time when a new element is added, the new element will replace the removed element.

This design makes removing faster but sacrifices sequential access. But that's okay, since we don't need sequential access in our scenario. By making removing faster, this data structure helps to speed up the cluster split, which will be extensively used in user relationship update case.
