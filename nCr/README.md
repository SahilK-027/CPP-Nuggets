# Problem: Finding nCr for large numbers

## Step 1: Understanding the problem
In combinatorics, 
```diff
𝑛𝐶𝑟 = 𝑛! / 𝑟! ⋅ (𝑛−𝑟)!
```
For large values of `𝑛`, the factorial `𝑛!` grows rapidly and can exceed computational limits. Even with modulo 𝑀 (1000000007), directly dividing factorials isn't feasible because modular arithmetic doesn't support division directly.

> [!NOTE]  
> - The number `1000000007` is a commonly used prime number in competitive programming and computer science for modular arithmetic. Here's why:
> - 1000000007 is a prime number, which is crucial for applying Fermat's Little Theorem.
> - 1000000007 is close to 10^9 , which is large enough to prevent intermediate results from overflowing in most calculations.
> - 1000000007 fits within a 32-bit integer (the max value of a 32-bit integer is 2^31 − 1 = 2147483647).


## Step 2: Why Modulo is Important
When 𝑛 becomes large (e.g., 𝑛 = 100000), n! becomes a huge number. To keep calculations manageable, we use modulo 𝑀

For example, if M=1000000007, we calculate:

```diff
𝑛𝐶𝑟 % M = (𝑛! % M) / (𝑟! ⋅ (𝑛−𝑟)!) % M
```

## Step 3: Problem with Division Under Modulo
Direct division isn't allowed in modular arithmetic. For example: (a / b) % M
doesn't work directly. Instead, we need the modular inverse of
b (denoted as 𝑏^−1 % 𝑀).

Using the modular inverse:

```diff
(a / b) % M = (a ⋅ 𝑏^−1) % M
```

## Step 4: Modular Inverse Using Fermat's Little Theorem
If 𝑀 is a prime, Fermat's Little Theorem says:

```diff
b ^ −1 = (b ^ M−2) % M
```
So, to find the modular inverse of 𝑏, (b ^ M−2) % M using modular exponentiation.

## Step 5: Modular Exponentiation
Modular exponentiation efficiently calculates 𝑎^𝑏 % 𝑀 using repeated squaring.

Example:
Compute 
3^4 % 5:

```diff
3^2 % 5 = 9 % 5 = 4
hence,
3^4 % 5 = 4 ^ 2 % 5 = 16 % 5 = 1
```
