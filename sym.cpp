#include "sym.h"

Sym::Sym()
{

}

Sym::Sym(std::string &var)
{
    initSym(1,1);
    this->var[0][0] = var;
}

Sym::Sym(char var)
{
    initSym(1,1);
    this->var[0][0] = var;
}

void Sym::initSym(int row, int col)
{
    using namespace std;

    this->var = new string*[row];
    for(int i = 0; i < row; i++)
        this->var[i] = new string[col];

    this->coef = new double[row];

    this->rowSym = row;
    this->colSym = col;

    for(int i = 0; i < row; i++)
    {
        this->coef[i] = 1;
        for(int j = 0; j < col; j++)
            this->var[i][j] = "";
    }



}

bool **Sym::compSym(Sym sym1, Sym sym2)
{
    using namespace std;

    bool **ret;
    string temp1[sym1.rowSym], temp2[sym2.rowSym];

    ret = new bool*[sym1.rowSym];
    for(int i = 0; i < sym1.rowSym; i++)
        ret[i] = new bool[sym2.rowSym];

    for(int i = 0; i < sym1.rowSym; i++)
        temp1[i] = "";

    for(int i = 0; i < sym2.rowSym; i++)
        temp2[i] = "";

    for(int i = 0; i < sym1.rowSym; i++)
       for(int j = 0; j < sym1.colSym; j++)
           temp1[i] = sym1.var[i][j] + temp1[i];

    for(int i = 0; i < sym2.rowSym; i++)
       for(int j = 0; j < sym2.colSym; j++)
           temp2[i] = sym2.var[i][j] + temp2[i];

    for(int i = 0; i < sym1.rowSym; i++)
        for(int j = 0; j < sym2.rowSym; j++)
        {
            if(temp1[i] == temp2[j])
                ret[i][j] = true;
            else
                ret[i][j] = false;
        }

    return ret;
}

Sym Sym::operator+(Sym &symbolic)
{
//    bool **comp;
//    comp = compSym(*this, symbolic);

   Sym ret;
   int max = this->rowSym;

   if(symbolic.rowSym > this->rowSym)
       max = symbolic.rowSym;

   ret.initSym(this->rowSym+symbolic.rowSym, max);

   for(int i = 0; i < ret.rowSym; i++)
       for(int j = 0; j < ret.colSym; j++)
       {
           if( i == this->rowSym)
               ret.var[i+this->rowSym-1][j] = symbolic.var[i-this->rowSym][j];
           else
               ret.var[i][j] = this->var[i][j];
       }

   return ret;
}

void Sym::operator=(Sym &poly)
{
    this->initSym(poly.rowSym, poly.colSym);

    for(int i = 0; i < poly.rowSym; i++)
        for(int j = 0; j < poly.colSym; j++)
            this->var[i][j] = poly.var[i][j];

    for(int i = 0; i < poly.rowSym; i++)
        this->coef[i] = poly.coef[i];
}

void Sym::print()
{
    using namespace std;

    for(int i = 0; i < this->rowSym; i++)
    {
        if(i==0)
        {
            if(this->coef[i] < 0)
                cout<<" - ";
            else
                cout<<"";
        }
        else if(this->coef[i] == 1)
            cout<<" + ";
        else if(this->coef[i] == -1)
            cout<<" - ";
        else if(this->coef[i] < 0)
            cout<<" "<<this->coef[i];
        else
            cout<<" + "<<this->coef[i];
        for(int j = 0; j < this->colSym; j++)
            cout<<this->var[i][j];

    }
}
