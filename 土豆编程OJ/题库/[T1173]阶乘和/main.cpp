#include <iostream>
#include <vector>
using namespace std;

// 大整数类
class BigInteger {
private:
	vector<int> digits; // 存储大整数的每一位数字
	
public:
	// 构造函数
	BigInteger() {}
	
	BigInteger(int num) {
		while (num > 0) {
			digits.push_back(num % 10);
			num /= 10;
		}
	}
	
	// 重载加法运算符
	BigInteger operator+(const BigInteger& other) const {
		BigInteger result;
		int carry = 0;
		int i = 0, j = 0;
		
		while (i < digits.size() || j < other.digits.size() || carry > 0) {
			int sum = carry;
			if (i < digits.size()) {
				sum += digits[i];
				i++;
			}
			if (j < other.digits.size()) {
				sum += other.digits[j];
				j++;
			}
			result.digits.push_back(sum % 10);
			carry = sum / 10;
		}
		
		return result;
	}
	
	// 重载乘法运算符
	BigInteger operator*(const BigInteger& other) const {
		BigInteger result;
		result.digits.resize(digits.size() + other.digits.size(), 0);
		
		for (int i = 0; i < digits.size(); i++) {
			int carry = 0;
			for (int j = 0; j < other.digits.size(); j++) {
				int product = digits[i] * other.digits[j] + carry + result.digits[i + j];
				result.digits[i + j] = product % 10;
				carry = product / 10;
			}
			result.digits[i + other.digits.size()] = carry;
		}
		
		return result;
	}
	
	// 输出大整数
	void print() {
		bool a=0;
		for (int i = digits.size() - 1; i >= 0; i--) {
			if(a!=0){
				cout << digits[i];
			}
			else if(digits[i] != 0){
				cout << digits[i];
				a=1;
			}
		}
		cout << endl;
	}
};

// 计算阶乘和
BigInteger factorialSum(int n) {
	BigInteger sum(0);
	BigInteger factorial(1);
	
	for (int i = 1; i <= n; i++) {
		factorial = factorial * BigInteger(i);
		sum = sum + factorial;
	}
	
	return sum;
}

int main() {
	int n;
	cin >> n;
	
	BigInteger result = factorialSum(n);
	result.print();
	return 0;
}
