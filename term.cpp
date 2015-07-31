#include <iostream>

class Term {
private:
	long double _coefficient;
	unsigned int _power;

public:
	Term(const long double coefficient = 0.0, const unsigned int power = 0) : _coefficient(coefficient), _power(power) {};
	Term(const Term& copy) : _coefficient(copy._coefficient), _power(copy._power) {};

	long double getCoefficient() const { return _coefficient; }
	unsigned int getPower() const { return _power; }

	void setCoefficient(const long double coefficient) { _coefficient = coefficient; }
	void setPower(const int power) { _power = power; }

	Term& operator=(const Term& term) { _power = term._power; _coefficient = term._coefficient; return *this; }

	Term& operator+=(const Term& term) { if(_power == term._power) _coefficient += term._coefficient; return *this; }
	Term& operator-=(const Term& term) { if(_power == term._power) _coefficient += term._coefficient; return *this; }
	Term& operator*=(const Term& term) { _power += term._power; _coefficient *= term._coefficient; return *this; }
	Term& operator/=(const Term& term) { _power -= term._power; _coefficient /= term._coefficient; return *this; }

	bool operator==(const Term& check) const { return (_power == check._power) && (_coefficient == check._coefficient); }
	bool operator>(const Term& check) const { return (_power > check._power) || (_coefficient > check._coefficient); }
	bool operator<(const Term& check) const { return (_power < check._power) || (_coefficient < check._coefficient); }

	friend std::istream& ::operator>>(std::istream&, Term&);
	friend std::ostream& ::operator<<(std::ostream&, const Term&);
};

Term operator+(const Term& one, const Term& two) { Term three = one; return three += two; }
Term operator-(const Term& one, const Term& two) { Term three = one; return three -= two; }
Term operator*(const Term& one, const Term& two) { Term three = one; return three *= two; }
Term operator/(const Term& one, const Term& two) { Term three = one; return three /= two; }

bool operator!=(const Term& term1, const Term& term2) { return !(term1 == term2); }
bool operator>=(const Term& term1, const Term& term2) { return !(term1 < term2); }
bool operator<=(const Term& term1, const Term& term2) { return !(term1 > term2); }

std::ostream& operator<<(std::ostream& out, const Term& term) {
	out << "(" << term._coefficient << "," << term._power << ")";
	return out;
}
