#define EIGEN_MATRIXBASE_PLUGIN "CorrelationMatrix.h"
#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <fstream>
#include "Ercsolver.h"

using namespace std;
using namespace Eigen;

#define MAXBUFSIZE ((int)1e6)

MatrixXd readMatrix(const char *filename)
{
    int cols = 0, rows = 0;
    double buff[MAXBUFSIZE];

    // Read numbers from file into buffer.
    ifstream infile;
    infile.open(filename);
    while (!infile.eof())
    {
        string line;
        getline(infile, line);

        int temp_cols = 0;
        stringstream stream(line);
        while (!stream.eof())
            stream >> buff[cols * rows + temp_cols++];

        if (temp_cols == 0)
            continue;

        if (cols == 0)
            cols = temp_cols;

        rows++;
    }

    infile.close();

    rows--;

    // Populate matrix with numbers.
    MatrixXd result(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result(i, j) = buff[cols * i + j];

    return result;
};

int main(int argc, char **argv)
{
    char *filename;
    if (argc == 2)
    {
        filename = argv[1];
    }
    else
    {
        std::cout << "Usage: ./ercsolve correlation-matrix-file\n";
        return 1;
    }
    MatrixXd Sigma = readMatrix(filename);
    if (!Sigma.isCorrelationMatrix())
    {
        std::cout << "It is not a correlation matrix.\n"
                  << std::endl;
        return 1;
    }
    ErcSolver solver;
    VectorXd solution = solver.solve(Sigma, 50);
    std::cout << "The risk contributions are\n"
              << solution / solution.sum() << std::endl;
    return 0;
}
