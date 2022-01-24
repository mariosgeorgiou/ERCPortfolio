# ERC Portfolio

ERC (equal risk contribution) Portfolio is a C++ library for deriving equal risk distributed portfolios. It implements the cyclical coordinate descent algorithm by Griveau-Billion, Richard and Roncalli. This is the [paper](https://arxiv.org/pdf/1311.4057.pdf).

## Installation

### Requirements
Make sure you have the [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page) library installed.
### Clone
Clone this repo to your local machine using ```https://github.com/mariosgeorgiou/ERCPortfolio```.

## Usage

```bash
cd src
make ercsolver
./ercsolver correlation-matrix-file
```
where ```correlation-matrix-file``` is a file containing the correlation matrix in space separated values.

## Roadmap
The library currently implements the non-optimized version of the algorithm where in each iteration the volatility of the portfolio is recomputed from the risk contribution.

### Next Steps
1. Optimize running time.
2. Create complex tests.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://choosealicense.com/licenses/mit/)
