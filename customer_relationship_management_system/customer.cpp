#include "customer.hpp"

Customer::Customer(const std::string& nmae, const std::string& contact_info)
    : m_name(nmae)
    , m_contact_info(contact_info)
{
}

Customer::~Customer()
{
    for (Interaction* interaction : m_interactions) {
        delete interaction;
    }
}

std::string Customer::get_name() const
{
    return m_name;
}

std::string Customer::get_contact_info() const
{
    return m_contact_info;
}

const std::vector<Interaction*>& Customer::get_interactions() const
{
    return m_interactions;
}

void Customer::set_name(const std::string& name)
{
    m_name = name;
}

void Customer::set_contact_info(const std::string& contact_info)
{
    m_contact_info = contact_info;
}

void Customer::add_interaction(Interaction* interaction)
{
    m_interactions.push_back(interaction);
}