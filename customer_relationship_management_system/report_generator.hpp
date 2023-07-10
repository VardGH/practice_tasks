#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include "customer.hpp"

class ReportGenerator
{
public:
    static void generate_report(const Customer& customer);
private:
    static void save_report(const std::string& report, const std::string& file_name);
};