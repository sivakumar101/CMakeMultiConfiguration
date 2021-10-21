#include <iostream>
#include <version.h>

int main()
{
#ifdef VORTEX
    std::cout << "Vendor [VORTEX] Version [" << get_version() <<"]\n";
#else
    std::cout << "Vendor [RTI] Version [" << get_version() <<"]\n";
#endif

    return 0;
}
