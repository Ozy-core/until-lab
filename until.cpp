#include <iostream>
#include <functional>
#include <cassert>

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
    int x;
    x=1;
    cout<<until(x,f,g)<<endl;

    // asserts tested here
    assert(until(1,f,g)==128);
    assert(until(5,f,g)==160);
    assert(until(10,f,g)==160);
    
    //This statement below should make the program error out
    //assert(until(50,f,g)==128);

    assert(until(100,f,g)==200);

    return 0;
}