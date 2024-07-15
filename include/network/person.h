#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

class Person
{
private:
    int id;
    std::string name;
    int birth_year;
    std::string university;
    std::string major;
    std::string job_place;
    std::vector<int> connections;
    std::vector<std::string> specialties;

public:
    // Default constructor
    Person();

    // Parameterized constructor
    Person(int id, std::string name, int birth_year, std::string university, std::string major,
           std::string job_place, std::vector<int> connections, std::vector<std::string> specialties);

    // Default distructor
    ~Person();

    int getId() const;
    std::string getName() const;
    int getBirthYear() const;
    std::string getUniversity() const;
    std::string getMajor() const;
    std::string getJobPlace() const;
    const std::vector<int> &getConnections();
    const std::vector<int> &getConnections() const;
    const std::vector<std::string> &getSpecialties();
    const std::vector<std::string> &getSpecialties() const;

    void setId(int id);
    void setName(const std::string &name);
    void setBirth_year(int birth_year);
    void setUniversity(const std::string &university);
    void setMajor(const std::string &major);
    void setJobPlace(const std::string &job_place);
    void setConnections(const std::vector<int> &connections);
    void setSpecialties(const std::vector<std::string> &specialties);
};

#endif // PERSON_H
