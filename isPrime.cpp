#include<iostream>

bool isPrime(int num);

int main()
{
    int num;
    std::cin >> num;

    if(isPrime(num))
        std::cout << "this is a prime" << std::endl;
    else
        std::cout << "not a prime" << std::endl;

    return 0; 
}

bool isPrime(int num)
{
    if(num == 1)
        return false;
    for (int i = 2; i * i <= num; ++i)
        if( num % i == 0 )
            return false;
    return true;
}