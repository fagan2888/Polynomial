#ifndef GUARD_TERM_H
#define GUARD_TERM_H

class Term {
private:
	long double 	_coef;
	unsigned int 	_pow;

public:
	Term() : _coef(0), _pow(0) {};
	Term(long double a_n, unsigned int n) : _coef(a_n), _pow(n) {};
	Term(const Term& copy) : _coef(copy._coef), _pow(copy._pow) {};
};

#endif