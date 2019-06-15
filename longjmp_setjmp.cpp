#include <cstdlib>
#include <setjmp.h>
#include <iostream>
#include <iomanip>

using namespace std;
jmp_buf jmp;

double Division_cal(double x, double y) {

	double resu = 0;
	
	if (x == 0) {
		longjmp(jmp, 1);
	}
	else {
		resu = y / x;
		return resu;
	}

}
void Exception_handling(void) {
	cout << "0 is included in a denominator" << endl;
}


int main(void) {

	double deno = 0;  //分母
	double nume = 0;  //分子
	double res = 0;   //結果

	cout << "   ★Division program★ " << endl;
	cout << " - Please enter a number - " << endl;
	
	while (1) {

		cout << "denominator：" << flush;
	
		if (!(cin >> deno)) {
			cout << "Input more than significant digits or non-numeric input" << endl;
			cin.clear();   //エラー状態をクリア
			cin.ignore(1024, '\n');   //内部バッファのデータを破棄
			continue;   //繰り返し
		}
		cin.ignore(1024, '\n');
		break;
	}

	while (1) {

		cout << "molecule   ：" << flush;

		if (!(cin >> nume)) {
			cout << "Input more than significant digits or non-numeric input" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		cin.ignore(1024, '\n');
		break;
	}
	if (setjmp(jmp) == 0) {
		res = Division_cal(deno, nume);
		cout << "Division result：" << setprecision(4) << res << endl;   //整数部・小数部含めて5桁表示
	}
	else {
		Exception_handling();
	}
	system("PAUSE");   //プログラムの一時停止
	
	return 0;
}
