#include "management_system.hpp"

void ManagementSystem::register_doctor(const std::string& name, const std::string& specialization, const int experience, const std::string& contact_info)
{
    m_doctors.push_back(Doctor(name, specialization, experience, contact_info));
    std::cout << "Doctor registered successfully." << std::endl;
}

void ManagementSystem::register_patient(const std::string& name, const std::string& birth_data, const std::string& gender, const std::string& contact_info)
{
    m_patients.push_back(Patient(name, birth_data, gender, contact_info));
    std::cout << "Patient registered successfully." << std::endl;
}

bool ManagementSystem::is_valid_patient_index(const int patient_index) const 
{
    return patient_index >= 0 && patient_index < m_patients.size();
}

void ManagementSystem::add_med_history_entry(const int patient_index, const std::string& diagnosis, const std::string& treatment, const std::string& medication)
{
    if (is_valid_patient_index(patient_index)) {
        m_patients[patient_index].set_med_history(MedicalHistory(diagnosis, treatment, medication));
        std::cout << "Medical history entry added successfully." << std::endl;
    } else {
        std::cout << "Invalid patient index." << std::endl;
    }
}

void ManagementSystem::generate_report(const int patient_index) 
{
    if (is_valid_patient_index(patient_index)) {
        m_report_generator.generate_report(m_patients[patient_index]);
    } else {
        std::cout << "Invalid patient index." << std::endl;
    }
}