#include "big_integer.hpp"
#include <iostream>

using namespace std;

int main(void){

    BigInteger num1, num2;

    int num3;

    cout << "Please input num1 and num2. (BigInteger)" << endl;
    cin >> num1 >> num2;

    cout << "Please input num3. (int)" << endl;
    cin >> num3;

    cout << "-num1 = " << -num1 << endl;

    cout << "num1 + num2 = " << num1 + num2 << endl;
    cout << "num1 - num2 = " << num1 - num2 << endl;
    cout << "num1 * num2 = " << num1 * num2 << endl;
    try{
        cout << "num1 / num2 = " << num1 / num2 << endl;
    }catch(string ex){
        cout << ex << endl;
    }
    try{
        cout << "num1 % num2 = " << num1 % num2 << endl;
    }catch(string ex){
        cout << ex << endl;
    }

    cout << "num1 == num2 = " << (num1 == num2) << endl;
    cout << "num1 != num2 = " << (num1 != num2) << endl;
    cout << "num1 > num2 = " << (num1 > num2) << endl;
    cout << "num1 < num2 = " << (num1 < num2) << endl;
    cout << "num1 >= num2 = " << (num1 >= num2) << endl;
    cout << "num1 <= num2 = " << (num1 <= num2) << endl;
 
    cout << "num1 + num3 = " << num1 + num3 << endl;
    cout << "num1 - num3 = " << num1 - num3 << endl;
    cout << "num1 * num3 = " << num1 * num3 << endl;
    try{
        cout << "num1 / num3 = " << num1 / num3 << endl;
    }catch(string ex){
        cout << ex << endl;
    }
    try{
        cout << "num1 % num3 = " << num1 % num3 << endl;
    }catch(string ex){
        cout << ex << endl;
    }

    cout << "num1 == num3 = " << (num1 == num3) << endl;
    cout << "num1 != num3 = " << (num1 != num3) << endl;
    cout << "num1 > num3 = " << (num1 > num3) << endl;
    cout << "num1 < num3 = " << (num1 < num3) << endl;
    cout << "num1 >= num3 = " << (num1 >= num3) << endl;
    cout << "num1 <= num3 = " << (num1 <= num3) << endl;

    cout << endl;
    cout << "num1 = " << num1 << endl;

    num1--;
    cout << "num1-- -> num1 = " << num1 << endl;

    num1++;
    cout << "num1++ -> num1 = " << num1 << endl;

    num1 += 1234567890;
    cout << "num1 += 1234567890 -> num1 = " << num1 << endl;

    num1 -= 1234567890;
    cout << "num1 -= 1234567890 -> num1 = " << num1 << endl;

    num1 *= 1234567890;
    cout << "num1 *= 1234567890 -> num1 = " << num1 << endl;

    try{
        num1 /= 1234567890;
        cout << "num1 /= 1234567890 -> num1 = " << num1 << endl;
    }catch(string ex){
        cout << ex << endl;
    }

    try{
        num1 %= 31316;
        cout << "num1 %= 31316 -> num1 = " << num1 << endl;
    }catch(string ex){
        cout << ex << endl;
    }

    return 0;
}
