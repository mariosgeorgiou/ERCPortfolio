inline bool isCorrelationMatrix(void) const {
	return (this->rows() == this->cols() && 
			this->isApprox(this->transpose()) &&
			this->lpNorm<Infinity>() <= 1);
}
