def fixedPoint(f, x, k):
	for i in range(k):
		x = f(x)
		print(x)
	return x

if __name__ == "__main__":
	guess = eval(input("input guess of root: "))
	n = eval(input("input number of iterations: "))
	# FPI for x^3+x-1
  #func = lambda x: 1 - x**3
  #func = lambda x: (1-x)**(1/3)
	# func = lambda x: (1+2*x**3)/(1+3*x**2)
	# FPI for x-x^{1/3)-2
	# func = lambda x: x**(1/3)+2
	#func = lambda x: (x-2)**3
	# func = lambda x: x**3 - x**2 - 10*x + 7
	# func = lambda x: (3 * x**2 - 10) / 2 * (x**3-10*x+7) ** (1/2)
	# func = lambda x: (x**3 - x**2 +7)/10
	# func = lambda x: (x**(3) - 10 * x + 7)**(1/2)
	func = lambda x: 7 / ((- x ** 2) + x + 10)



	root = fixedPoint(func, guess, n)
	print("root is approx ",root)

	
