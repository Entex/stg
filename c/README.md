# Usage
```bash
Usage: stg [OPTION...]
            STG or Spanning Tree Generator is a program that generates a spanning tree
            with random lengths between nodes used for calculating a spanning tree

  -l, --length=integer       Maximum length between nodes
  -n, --nodes=integer        Number of nodes
  -o, --odds=integer         Odds of path between nodes (0-100)
  -p, --pretty               print pretty format
  -?, --help                 Give this help list
      --usage                Give a short usage message
  -V, --version              Print program version

Mandatory or optional arguments to long options are also mandatory or optional
for any corresponding short options.

Report bugs to rjak@kth.se.
```

# Compile

## Linux
`gcc stg.c -o stg`

## MacOS
install brew `https://brew.sh/`

`brew install argp-standalone`

`gcc -I/opt/homebrew/Cellar/argp-standalone/1.3/include/ -L/opt/homebrew/Cellar/argp-standalone/1.3/lib/ -largp stg.c -o stg`

# Run
```bash
./stg -n 5 -l 30 -o 35

Output:
-------
[[0, 0, 0, 10, 12], [0, 0, 22, 0, 0], [0, 22, 0, 23, 0], [10, 0, 23, 0, 2], [12, 0, 0, 2, 0]]
```
## pretty
use the `-p` flag for a pretty output
```bash
./stg -p -n 30 -o 35 -l 99

Output:
-------
 0  0 99  0  0  0 39  0  0  0  0  0  0 53  2  0  0 74  0  0  0 47 47  0  0  0  0  0 93 74 
 0  0  0  0  0  0 70  0 22  0  0  0  0 19 35  0 61  0 90  0 35  0 81  0 54  0 40  0 63 10 
99  0  0  0  0  0  0  0 91  0 80  0 93  0  0  0  0  0  0  0  0  0  0  0  0  0 47 94  0  0 
 0  0  0  0 20  2 41 75 26  0  0  0  0  0  0  0  0  0  0 69  0  0  5  0  0  0  0  0  0  0 
 0  0  0 20  0  0  0  0 11  0  0  0  0  0  0  0  0  1 51  0  0  0 56  0  0  0 44 55  0  0 
 0  0  0  2  0  0  0  0  0  0 50  0  0  0  0 81  0  0 64  0  0  0 58  0 70 65  0  0  0 95 
39 70  0 41  0  0  0  0  0  0  0 80 28 45  0 82  0 21  0  0  0  0 88  0  0 60 91  0  0  0 
 0  0  0 75  0  0  0  0  0 48 90  0  0  0  0  0  0  0  0  0  5  0  0  0  0  0  0 41  0  0 
 0 22 91 26 11  0  0  0  0  0 92 70  0  0  0  0 87 95 78 57  0  5  0 29  0  0 95  0  0 68 
 0  0  0  0  0  0  0 48  0  0 27 26  0  5  0  0  0  0  0 89  0 35 49 58  0  0 74 35 20 28 
 0  0 80  0  0 50  0 90 92 27  0  0  0  0 12 78  0  0  0  0  0  0  0  0  0 84  0  0  0  0 
 0  0  0  0  0  0 80  0 70 26  0  0 71  0  0 66  0 78  0 99 58 87  0  0 40  0  0  0  0  0 
 0  0 93  0  0  0 28  0  0  0  0 71  0  0  0  0  0  0  0  0  0  3  0 45 50  0 11  0  0  0 
53 19  0  0  0  0 45  0  0  5  0  0  0  0  0  4 43  0  0 96  0 69  0  0  0  0  0 24  0  0 
 2 35  0  0  0  0  0  0  0  0 12  0  0  0  0 33  0  0 92  0  0  0  0  0  0  0  0  7  0 43 
 0  0  0  0  0 81 82  0  0  0 78 66  0  4 33  0  0 34 13 54  8  0  0  0  0 83  0  0  0 53 
 0 61  0  0  0  0  0  0 87  0  0  0  0 43  0  0  0  0 46 74 84  0  0 60 74 53  0  0  0  0 
74  0  0  0  1  0 21  0 95  0  0 78  0  0  0 34  0  0  0  0  0 13  0  0  0  0  0  0 72  0 
 0 90  0  0 51 64  0  0 78  0  0  0  0  0 92 13 46  0  0  0 94  0 43  0  0  0 78  0  0  0 
 0  0  0 69  0  0  0  0 57 89  0 99  0 96  0 54 74  0  0  0 34  0 39 41 61  0  0  0 48  0 
 0 35  0  0  0  0  0  5  0  0  0 58  0  0  0  8 84  0 94 34  0  0  0 85  0  0  0 84  0  0 
47  0  0  0  0  0  0  0  5 35  0 87  3 69  0  0  0 13  0  0  0  0  0  0  0  0 85  0 54  0 
47 81  0  5 56 58 88  0  0 49  0  0  0  0  0  0  0  0 43 39  0  0  0  0  0  0 23  0  0  0 
 0  0  0  0  0  0  0  0 29 58  0  0 45  0  0  0 60  0  0 41 85  0  0  0  0 48  0  0  0 79 
 0 54  0  0  0 70  0  0  0  0  0 40 50  0  0  0 74  0  0 61  0  0  0  0  0  0 11  0 56  0 
 0  0  0  0  0 65 60  0  0  0 84  0  0  0  0 83 53  0  0  0  0  0  0 48  0  0  0 12  0  0 
 0 40 47  0 44  0 91  0 95 74  0  0 11  0  0  0  0  0 78  0  0 85 23  0 11  0  0  0 25 11 
 0  0 94  0 55  0  0 41  0 35  0  0  0 24  7  0  0  0  0  0 84  0  0  0  0 12  0  0 35  0 
93 63  0  0  0  0  0  0  0 20  0  0  0  0  0  0  0 72  0 48  0 54  0  0 56  0 25 35  0 69 
74 10  0  0  0 95  0  0 68 28  0  0  0  0 43 53  0  0  0  0  0  0  0 79  0  0 11  0 69  0
```
