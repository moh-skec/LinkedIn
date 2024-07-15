#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <set>
#include <vector>
#include "person.h"

class Graph
{
private:
    std::map<int, Person> people;
    std::map<int, std::set<int>> adjacency_list;

    int bsfShortestPath(int start_id, int target_id);

public:
    Graph();

    ~Graph();

    const std::map<int, Person> &getPeople();
    const std::map<int, Person> &getPeople()  const;
    const std::map<int, std::set<int>> &getAdjacencyList();
    const std::map<int, std::set<int>> &getAdjacencyList() const;

    void setPeople(const std::map<int, Person> &connections);
    void setAdjacencyList(const std::map<int, std::set<int>> &specialties);

    void addPerson(const Person &person);
    void addConnection(int person1_id, int person2_id);
    std::vector<int> suggestConnections(int person_id);
    void printRelatedPeople(int person_id);
};

#endif // GRAPH_H
