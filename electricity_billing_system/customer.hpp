#pragma once

#include <string>

class Customer
{
public:
    Customer(const std::string& name, const std::string& contact_info, const std::string& meter_number);

public:
    std::string get_name() const;
    std::string get_contact_info() const;
    std::string get_meter_number() const;

    void set_name(const std::string& name);
    void set_contact_info(const std::string& contact_info);
    void set_meter_number(const std::string& meter_number);
    
private:
    std::string m_name;
    std::string m_contact_info;
    std::string m_meter_number;
};