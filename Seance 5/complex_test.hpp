#ifndef complexHPP
#define complexHPP
#include <iostream>
#include <cmath>

//5 chiffre apres la virgule
#define precision 1e5
 
class Complex
{
private:
	double mRealPart;
	double mImaginaryPart;
	friend Complex operator *(double, const Complex& );
	friend Complex operator +(double, const Complex&);
	friend Complex operator -(double, const Complex&);
	friend std::ostream& operator<<(std::ostream& , const Complex& );
public:
	Complex():mRealPart(0.0),mImaginaryPart(0.0){};
	Complex(double a, double b, bool polar=0){
		if(polar){
			mRealPart = std::round(a * std::cos(b) * precision) / precision;
			mImaginaryPart = std::round(a * std::sin(b) * precision) / precision;
		}else{
			mRealPart =a;
			mImaginaryPart = b;
		}
		
	};
	//fonction statique : une fonctione globalbe à une classe il nya pas de this.
	~Complex(){};
	Complex(double a) : Complex(a,0.0){}; 
	Complex(float a) : Complex(static_cast<double>(a)){};
	Complex(int a) : Complex(static_cast<double>(a),0.0){};
	Complex operator + (const Complex& c)const{
		return Complex(mRealPart + c.mRealPart, mImaginaryPart+c.mImaginaryPart);
	}
	Complex operator * (double a) const{
		return Complex(a*mRealPart, a*mImaginaryPart);
	}
	Complex operator -(const Complex& c)const{
		return Complex(mRealPart - c.mRealPart, mImaginaryPart-c.mImaginaryPart);
	}
	Complex operator *(const Complex& c)const{
		return Complex(mRealPart * c.mRealPart - mImaginaryPart*c.mImaginaryPart, mRealPart * c.mImaginaryPart + c.mRealPart * mImaginaryPart);
	}
	//a +ib * a'+ib' = aa' + i * (a*b' + a'*b) -b*b'
	Complex& operator +=(const Complex&c ){
		mRealPart += c.mRealPart;
		mImaginaryPart += c.mImaginaryPart;
		return *this;
	}
	Complex& operator -=(const Complex&c){
		mRealPart -= c.mRealPart;
		mImaginaryPart -= c.mImaginaryPart;
		return *this;
	}
	Complex& operator *=(const double c){
		mRealPart *= c;
		mImaginaryPart *= c;
		return *this;	
	}
	Complex& operator *=(const Complex& c){
		(*this)= (*this)*c;
		return *this;
	}

	void print() const {
		if (mRealPart != 0 || mImaginaryPart != 0) {
			if (mRealPart != 0) {
				std::cout << mRealPart << " ";
			}
			if (mImaginaryPart < 0) {
				std::cout << "- " << std::abs(mImaginaryPart) << " i";
			} else if (mImaginaryPart > 0) {
				if (mRealPart != 0) {
					std::cout << "+ ";
				}
				if(mImaginaryPart ==1){
					std::cout << "i";
				}else{
					std::cout << mImaginaryPart << " i";
				}
				
			}
			std::cout << std::endl;
		} else {
			std::cout << "0" << std::endl;
		}
	}

	double getReal(){
		return this->mRealPart;
	}
	double getIm(){
		return this->mImaginaryPart;
	}
};
Complex operator *(double a, const Complex& c){
		return Complex(a*c.mRealPart, a*c.mImaginaryPart);
	}
Complex operator +(double a, const Complex& c){
	return Complex(a+c.mRealPart,c.mImaginaryPart);
};
Complex operator -(double a, const Complex&c){
	return Complex(a-c.mRealPart,c.mImaginaryPart);
};

std::ostream& operator<<(std::ostream& aStream, const Complex& c)
{
     if (c.mRealPart != 0 || c.mImaginaryPart != 0) {
			if (c.mRealPart != 0) {
				aStream << c.mRealPart << " ";
			}
			if (c.mImaginaryPart < 0) {
				aStream << "- " << std::abs(c.mImaginaryPart) << " i";
			} else if (c.mImaginaryPart > 0) {
				if (c.mRealPart != 0) {
					aStream << "+ ";
				}
				if(c.mImaginaryPart ==1){
					aStream << "i";
				}else{
					aStream << c.mImaginaryPart << " i";
				}
				
			}
			aStream << std::endl;
		} else {
			aStream << "0" << std::endl;
		}
    return aStream;
}
extern const Complex I(0.0,1.0);
#endif
