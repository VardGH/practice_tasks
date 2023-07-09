#include "report_generator.hpp"

void ReportGenerator::generate_report(const Patient& patient)
{
    std::string report_filename = patient.get_name() + "_" + patient.get_birth_data() + "_" + ".txt";
    std::ofstream report_file(report_filename);

    if (report_file.is_open()) {
        report_file << "Patient Name: " << patient.get_name() << std::endl;
            report_file << "Date of Birth: " << patient.get_birth_data() << std::endl;
            report_file << "Gender: " << patient.get_gender() << std::endl;
            report_file << "Contact Information: " << patient.get_contact_info() << std::endl;

            report_file << "Medical History:" << std::endl;
            auto med_history = patient.get_med_history();
            report_file << "Diagnosis: " << med_history.get_diagnoses() << std::endl;
            report_file << "Treatment: " << med_history.get_treatments() << std::endl;
            report_file << "Medication: " << med_history.get_medications() << std::endl;
            report_file << std::endl;

            report_file.close();
            std::cout << "Report generated successfully." << std::endl;

    } else {
        std::cout << "Unable to open report file." << std::endl;
    }
}