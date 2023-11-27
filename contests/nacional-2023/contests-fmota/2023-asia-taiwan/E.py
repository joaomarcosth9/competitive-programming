dp = {}

def dpp(a, b, m):
    if b == 0:
        return 1;
    elif b == 1:
        return a;
    if (b in dp):
        return dp[b];
    if ((b % 2) == 0):
        dp[b] = (dpp(a, b // 2, m)**2 - 2 + m) % m;
    else:
        dp[b] = (dpp(a, (b + 1) // 2, m) * dpp(a, b // 2, m) - a + m) % m;
    return dp[b];

a, b, m = map(int, input().split());

if (m == 1):
    print(0);
else:
    print(dpp(a, b, m));
