## Approximate the solutions to the BVP u'' = f(x) and compare it with the exact solution
### Analytical solution:
The differential equation is: $u'' = f(x) = 2x$  
Integrate $u'' = 2x$ once to find u':  
$$u' = \int 2x \, dx = x^2 + C_1$$  
where $C_1$ is a constant of integration.  
Integrate again to find u:  
$$u = \int (x^2 + C_1) dx = \frac {x^3 }{3} + C_1x + C_2$$  
where $C_2$ is another constant of integration.  
Now, let's apply the boundary conditions as: $u(0) = A = 0$ and $u(1) = B = 1$  
For $u(0) = 0$ substituting $x = 0$ and $u(0) = 0$ gives:  
$$0 = \frac {0^3}{3} + C_1 . 0 + C_2 \implies C_2 = 0$$  
For $u(1) = 1$ substituting $x = 1$ and $u(1) = 1$ gives:  
$$1 = \frac {1^3}{3} + C_1 . 1 + 0 \implies 1 = \frac {1}{3} + C_1$$  
Solving for $C_1$:  
$$C_1 = 1 - \frac {1}{3} = \frac {2}{3}$$  
Thus, the exact solution is:  
$$u(x) = \frac {x^3}{3} + \frac {2x}{3}$$

### Comments on results:
From the output, we can observe two trends:  
1. Error reduces as the number of interior points (N) increases, and
2. Error ratio increases as the number of interior points N increases, representing the convergence of solving BVP using finite difference approximations.
