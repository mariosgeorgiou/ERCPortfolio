#include "Ercsolver.h"


double ErcSolver::Sx(int i){
	return (Sigma * x)(i);
}

double ErcSolver::var(int i){
	return Sigma(i,i);
}

double ErcSolver::volty(){ //the overall volatility
	return sqrt(x.transpose() * Sigma * x);
}

void ErcSolver::setXi(int i){ //one step of the coordinate descent algorithm
	double alpha = var(i);
	double beta = Sx(i) - x(i) * var(i);
	double gamma = 0 - volty() / (float)n;
	double delta = beta * beta - 4 * alpha * gamma;
	x(i) = (0 - beta + sqrt(delta)) / (2.0 * alpha);
}


VectorXd ErcSolver::solve(MatrixXd S, int iterations){ //number of iterations
	n = S.rows();
	Sigma = S;
	x = VectorXd::Constant(n, 1.0/(float)n); //equal initial weight
	for (int iter = 0; iter < iterations; iter++){
		for (int i = 0; i < n; i++){
			setXi(i);
		}
	}
	return x;
}

