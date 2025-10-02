#include <iostream>
#include <functional>

using namespace std;

int until(int x, function<int(int)> f, function<bool(int)> g)
{
    while(!g(x))
    {
        x=(f(x));
    }
    return x;
}

int main()
{
    function<int(int)> f = [](int x){return x*2;};
    function<bool(int)>g= [](int x){return x>100;};
    cout<<until(1,f,g)<<endl;
    return 0;
}