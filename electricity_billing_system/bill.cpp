#include "bill.hpp"

Bill::Bill(const Customer customer, const double rate_per_unit)
    : m_customer(customer)
    , m_consumption(0.0)
    , m_rate_per_unit(rate_per_unit)
    , m_total_amount(0.0)
    , m_bill_date(0)
{
}

void Bill::set_customer(const Customer& customer)
{
    m_customer = customer;
}

void Bill::set_consumption(const double consumption)
{
    m_consumption = consumption;
}

void Bill::set_bill_date(const std::time_t bill_data)
{
    m_bill_date = bill_data;
}

void Bill::set_total_amount(const double total_amount)
{
    m_total_amount = total_amount;
}

void Bill::set_rate_per_unit(const double rate_per_unit)
{
    m_rate_per_unit = rate_per_unit;
}

Customer Bill::get_customer() const
{
    return m_customer;
}

double Bill::get_consumption() const
{
    return m_consumption;
}

double Bill::get_rate_per_unit() const
{
    return m_rate_per_unit;
}

std::time_t Bill::get_bill_date() const
{
    return m_bill_date;
}

double Bill::get_total_amount() const
{
    return m_total_amount;
}

void Bill::calculate_total_amount()
{
    m_total_amount = m_consumption * m_rate_per_unit;
}

void Bill::generate_bill() 
{
    std::stringstream ss;
    ss << "********** Electricity Bill **********\n";
    ss << "Customer Name: " << m_customer.get_name() << std::endl;
    ss << "Contact Info: " << m_customer.get_contact_info() << std::endl;
    ss << "Meter Number: " << m_customer.get_meter_number() << std::endl;
    ss << "--------------------------------------\n";
    ss << "Consumption: " << m_consumption << " units" << std::endl;
    ss << "Rate per Unit: $" << m_rate_per_unit << std::endl;
    ss << "Total Amount Due: $" << m_total_amount << std::endl;
    ss << "Bill Date: " << asctime(localtime(&m_bill_date));
    ss << "****************************************\n";
    std::cout << ss.str();
}

void Bill::save_bill_to_file() 
{
    std::string filename = m_customer.get_name() + "_bill" + ".txt";
    std::ofstream file(filename);

    if (file.is_open()) {
        file << "********** Electricity Bill **********\n";
        file << "Customer Name: " << m_customer.get_name() << std::endl;
        file << "Contact Info: " << m_customer.get_contact_info() << std::endl;
        file << "Meter Number: " << m_customer.get_meter_number() << std::endl;
        file << "--------------------------------------\n";
        file << "Consumption: " << m_consumption << " units" << std::endl;
        file << "Rate per Unit: $" << m_rate_per_unit << std::endl;
        file << "Total Amount Due: $" << m_total_amount << std::endl;
        file << "Bill Date: " << asctime(localtime(&m_bill_date));
        file << "--------------------------------------\n";
        file.close();
        std::cout << "Bill saved to " << filename << std::endl;

    } else {
        std::cout << "Error: Unable to save bill to file." << std::endl;
    }
}