#!/bin/bash
set -e

g++-14 -O2 gen.cpp -o gen # pode fazer o gerador em python se preferir
g++-14 -O2 M.cpp -o brute
g++-14 -O2 M2.cpp -o code

for((i = 1; ; ++i)); do
    ./gen 2 > in
    ./code < in > out
    ./brute < in > ok
    diff -w out ok || break
    echo "Passed test: " $i
done

echo "WA no seguinte teste:"
cat in
echo "Sua resposta eh:"
cat out
echo "A resposta correta eh:"
cat ok
