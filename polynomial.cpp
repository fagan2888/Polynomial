#include <iostream>
#include <list>

class Polynomial {
private:
	std::list<Term>	_terms;

public:
	Polynomial() : _terms(std::list<Term>()) {};

	long double getTermCoefficient(const unsigned int power) {
		for(auto i = _terms.begin(); (i != _terms.end()) && (i->getPower() <= power); ++i)
			if(i->getPower() == power)
				return i->getCoefficient();
		return 0.0;
	}

	Polynomial& operator+=(const Term& add) {
		if(add.getCoefficient() == 0.0)
			return *this;
		for(auto i = _terms.begin(); i != _terms.end(); ++i)
			if(i->getPower() > add.getPower()) {
				_terms.insert(i, add);
				return *this;
			}
			else if(i->getPower() == add.getPower()) {
				i->setCoefficient(i->getCoefficient() + add.getCoefficient());
				return *this;
			}
		this->_terms.push_back(add);
		return *this;
	}

	Polynomial& operator+=(const Polynomial& add) {
		for(auto i = add._terms.begin(); i != add._terms.end(); ++i)
			*this += *i;
		return *this;
	}

	friend std::ostream& ::operator<<(std::ostream&, const Polynomial&);
};

std::ostream& operator<<(std::ostream& out, const Polynomial& polynomial) {
	out << "[";
	for(auto i = polynomial._terms.begin(); i != polynomial._terms.end(); ++i)
		out << *i;
	out << "]";
	return out;
}
