#include <eigen3/Eigen/Dense>

using namespace Eigen;

class ErcSolver
{

private:
	VectorXd x;		//asset weight vector
	MatrixXd Sigma; //correlation matrix
	int n;			//number of assets

	double Sx(int);

	double var(int);

	double volty(); //the overall volatility

	void setXi(int); //one step of the coordinate descent algorithm

public:
	VectorXd solve(MatrixXd, int); //number of iterations
};
