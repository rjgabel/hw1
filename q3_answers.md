Part (a): While loop runs $O(\sqrt n)$ times, runtime is $O(\sqrt n)$.

Part (b): Inner for loop has $O(i^3)$ runtime. Outer for loop runs $n$ times but the if statement means that control flow reaches the inner for loop $\sqrt n$ times. Full time complexity is $O(n^{3.5})$.

Part (c): Innermost for loop has $O(\log n)$ runtime. The if statement can only be true one time for each $k$ so the innermost for loop will run at most $O(n)$ times. This would give us $O(n\log n)$ runtime, but the if statement is $O(1)$ inside of two for loops so it's actually $O(n^2)$.

Part (d): Inner for loop has $O(n)$ runtime (since `size` increases linearly with `n`). The interior of the if statement is executed $O(\log n)$ times, so final runtime is $O(n\log n)$.
