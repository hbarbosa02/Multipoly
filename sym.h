#ifndef __SYM_H_INCLUDED
#define __SYM_H_INCLUDED

#include <string>
#include <iostream>



class Sym
{
private:
    std::string **var;
    int rowSym, colSym;
    double *coef;

    void initSym(int row, int col);
    bool **compSym(Sym sym1, Sym sym2);
public:
    Sym();
    Sym(char var);
    Sym(std::string &var);

    //void initSym(int row, int col);

    Sym operator+(Sym &);
    void operator=(Sym &);

    void print();
};

#endif // SIMBOLIC_H
