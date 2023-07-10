#pragma once

#include "customer.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>

class Bill
{
public:
    Bill(const Customer customer, const double rate_per_unit);

public:
    Customer get_customer() const;
    double get_consumption() const;
    double get_rate_per_unit() const;
    double get_total_amount() const;
    std::time_t get_bill_date() const;

    void set_customer(const Customer& customer);
    void set_consumption(const double consumption);
    void set_rate_per_unit(const double rate_per_unit);
    void set_total_amount(const double total_amount);
    void set_bill_date(const std::time_t bill_data);

public:
    void calculate_total_amount();
    void generate_bill();
    void save_bill_to_file();

private:
    Customer m_customer;
    double m_consumption;
    double m_rate_per_unit;
    double m_total_amount;
    std::time_t m_bill_date;
};