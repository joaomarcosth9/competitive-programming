set -e

if [ $# -ne 3 ]; then
    echo "Usage: ./brute_macos.sh <your_code> <brute_force> gen.cpp"
    exit 1
fi

g++-12 -O2 $1 -o /tmp/__code
g++-12 -O2 $2 -o /tmp/__brute
g++-12 -O2 $3 -o /tmp/__gen

for((i = 1; ; ++i)); do
    /tmp/__gen > /tmp/__input_file
    /tmp/__code < /tmp/__input_file > /tmp/__myAnswer
    /tmp/__brute < /tmp/__input_file > /tmp/__correctAnswer
    diff /tmp/__myAnswer /tmp/__correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done

echo "WA on the following test:"
cat /tmp/__input_file
echo "Your answer is:"
cat /tmp/__myAnswer
echo "Correct answer is:"
cat /tmp/__correctAnswer
