#include "customer.hpp"

Customer::Customer(const std::string& name, const std::string& contact_info, const std::string& meter_number)
    : m_name(name)
    , m_contact_info(contact_info)
    , m_meter_number(meter_number)
{
}

std::string Customer::get_name() const
{
    return m_name;
}

std::string Customer::get_contact_info() const
{
    return m_contact_info;
}

std::string Customer::get_meter_number() const
{
    return m_meter_number;
}

void Customer::set_name(const std::string& name)
{
    m_name = name;
}

void Customer::set_contact_info(const std::string& contact_info)
{
    m_contact_info = contact_info;
}

void Customer::set_meter_number(const std::string& meter_number)
{
    m_meter_number = meter_number;
}