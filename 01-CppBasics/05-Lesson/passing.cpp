

void changing(int* a, int &b){

    *a=10;
    //std::cout << "*a= " << a << std::endl;
    b=20;
    //std::cout << "&b = " << &b << std::endl;
}


int main(){

    int a{ 3 }, b{ 8 };

    changing(&a,b);

    //std::cout << "In main after " << std::endl;
    //std::cout << "&a = " << &a << std::endl;
    //std::cout << "&b = " << &b << std::endl;


    return 0;
}