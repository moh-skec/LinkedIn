#include "person.h"

Person::Person()
{
    // Default
}

Person::Person(int id, std::string name, int birth_year, std::string university, std::string major,
               std::string job_place, std::vector<int> connections, std::vector<std::string> specialties)
    : id(id), name(name), birth_year(birth_year), university(university),
      major(major), job_place(job_place), connections(connections),
      specialties(specialties)
{
}

Person::~Person()
{
    // Default
}

int Person::getId() const
{
    return this->id;
}
std::string Person::getName() const
{
    return this->name;
}
int Person::getBirthYear() const
{
    return this->birth_year;
}
std::string Person::getUniversity() const
{
    return this->university;
}
std::string Person::getMajor() const 
{
    return this->major;
}
std::string Person::getJobPlace() const 
{
    return this->job_place;
}
std::vector<int> const &Person::getConnections()
{
    return this->connections;
}
const std::vector<int> &Person::getConnections() const
{
    return this->connections;
}
const std::vector<std::string> &Person::getSpecialties()
{
    return this->specialties;
}
const std::vector<std::string> &Person::getSpecialties() const
{
    return this->specialties;
}

void Person::setId(int id) 
{ 
    this->id = id; 
}
void Person::setName(const std::string &name) 
{ 
    this->name = name; 
}
void Person::setBirth_year(int birth_year) 
{ 
    this->birth_year = birth_year; 
}
void Person::setUniversity(const std::string &university) 
{ 
    this->university = university; 
}
void Person::setMajor(const std::string &major) 
{ 
    this->major = major; 
}
void Person::setJobPlace(const std::string &job_place) 
{ 
    this->job_place = job_place; 
}
void Person::setSpecialties(const std::vector<std::string> &specialties) 
{ 
    this->specialties = specialties; 
}
void Person::setConnections(const std::vector<int> &connections) 
{ 
    this->connections = connections; 
}
