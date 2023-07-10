#pragma once

#include "interaction.hpp"
#include <string>
#include <vector>

class Customer
{
public:
    Customer(const std::string& nmae, const std::string& contact_info);
    ~Customer();
public:
    std::string get_name() const;
    std::string get_contact_info() const;
    const std::vector<Interaction*>& get_interactions() const;

    void set_name(const std::string& nmae);
    void set_contact_info(const std::string& contact_info);
    void add_interaction(Interaction* interaction);

private:
    std::string m_name;
    std::string m_contact_info;
    std::vector<Interaction*> m_interactions;
};