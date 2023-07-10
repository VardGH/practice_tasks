#include "report_generator.hpp"

void ReportGenerator::generate_report(const Customer& customer)
{
    std::stringstream report;
    report << "Customer Name: " << customer.get_name() << std::endl;
    report << "Contact Info : " << customer.get_contact_info() << std::endl;
    report << "Interaction History:";

    for (const Interaction* interaction : customer.get_interactions()) {
        //report << "Date: " << std::ctime(&interaction->get_data());
        report << "User: " << interaction->get_user() << std::endl;
    }
    std::cout << report.str();

    std::string file_name = customer.get_name() + "_" + ".txt";
    save_report(report.str(), file_name);

}

void ReportGenerator::save_report(const std::string& report, const std::string& file_name) 
{
    std::ofstream file(file_name);
    if (file.is_open()) {
        file << report;
        file.close();
        std::cout << "Report saved to " << file_name << std::endl;
    } else {
        std::cout << "Failed to save the report." << std::endl;
    }
}