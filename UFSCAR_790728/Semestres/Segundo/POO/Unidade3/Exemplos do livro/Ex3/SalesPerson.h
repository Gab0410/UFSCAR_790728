#ifndef SALESP_H
#define SALESP_H

class SalesPerson{
    public:
        SalesPerson();
        void printSales();
        void getSalesUser();
        void setSales(int,double);
    private:
        double totalSales();
        double sales[12];

};
#endif