#pragma once

#include "interaction.hpp"
#include "customer.hpp"
#include "report_generator.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

class CRMSystem
{
public:
    void register_customer(const std::string& name, const std::string& contact_info);
    void display_customer_details(const std::string& name) const;
    void generate_snd_save_report(const std::string& namer) const;
    void add_interaction(const std::string& customer_name, Interaction* interaction);

private:
    std::vector<Customer> m_customers;
};