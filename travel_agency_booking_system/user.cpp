#include "user.hpp"


User::User(const std::string& name, const std::string& contact_info)
    : m_name(name)
    , m_contact_info(contact_info)

{
}

std::string User::get_name() const
{
    return m_name;
}

std::string User::get_contact_info() const
{
    return m_contact_info;
}

void User::set_name(const std::string& name)
{
    m_name = name;
}

void User::set_contact_info(const std::string& contact_info)
{
    m_contact_info = contact_info;
}