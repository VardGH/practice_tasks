#pragma once

#include <vector>
#include <string>
#include "customer.hpp"
#include "bill.hpp"

class ElectricityBillingSystem 
{
public:
    void register_customer(const std::string& name, const std::string& contact_info, const std::string& meter_number, double rate_per_unit);
    void input_electricity_consumption(const std::string& meter_number, const double consumption);
    void generate_bill(const std::string& meter_number, const double rate_per_unit);
    void save_bill_to_file(const std::string& meter_number);

private:
    Customer* find_customer_by_meter_number(const std::string& meter_number);
    Bill* find_pending_bill_by_meter_number(const std::string& meter_number);
    Bill* find_generated_bill_by_meter_number(const std::string& meter_number);
    Bill* find_generated_bill(const std::string& meter_number);

private:
    std::vector<Customer> m_customers;
    std::vector<Bill> m_bills;
};