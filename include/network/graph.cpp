#include "graph.h"
#include <queue>
#include <algorithm>
#include <iostream>

Graph::Graph()
{
    // Default
}

Graph::~Graph()
{
    // Default
}

const std::map<int, Person> &Graph::getPeople()
{
    return this->people;
}
const std::map<int, Person> &Graph::getPeople() const
{
    return this->people;
}
const std::map<int, std::set<int>> &Graph::getAdjacencyList()
{
    return this->adjacency_list;
}
const std::map<int, std::set<int>> &Graph::getAdjacencyList() const
{
    return this->adjacency_list;
}

void Graph::setPeople(const std::map<int, Person> &people)
{
    this->people = people;
}
void Graph::setAdjacencyList(const std::map<int, std::set<int>> &adjacency_list)
{
    this->adjacency_list = adjacency_list;
}

// Breadth-First Search to find the shortest path between two nodes
int Graph::bsfShortestPath(int start_id, int target_id)
{
    if (start_id == target_id)
        return 0;

    std::map<int, bool> visited;
    std::map<int, int> distance;
    std::queue<int> q;

    visited[start_id] = true;
    distance[start_id] = 0;
    q.push(start_id);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        std::set<int> v = adjacency_list[current];
        for (int i : v)
        {
            if (!visited[i])
            {
                visited[i] = true;
                distance[i] = distance[current] + 1;
                q.push(i);

                if (i == target_id)
                {
                    return distance[i];
                }
                // else: Not reached yet
            }
            // else: Visited neighbor
        }
        // The target was not in this node's neighbors
    }

    return -1; // No path found
}

void Graph::addPerson(const Person &person)
{
    people[person.getId()] = person;
}

void Graph::addConnection(int person_1_id, int person_2_id)
{
    // Ensure both people are in the graph
    if (people.count(person_1_id) && people.count(person_2_id) && (people[person_1_id].getBirthYear() > 2007 && people[person_1_id].getBirthYear() > 2007 || people[person_1_id].getBirthYear() <= 2007 && people[person_1_id].getBirthYear() <= 2007))
    {
        adjacency_list[person_1_id].insert(person_2_id);
        adjacency_list[person_2_id].insert(person_1_id);
    }
    // else: No connection
}

std::vector<int> Graph::suggestConnections(int person_id)
{
    std::map<int, double> scores;
    Person target_person = people[person_id];
    std::map<int, Person> v = people;

    for (auto &[id, person] : v)
    {
        if (id == person_id)
        {
            continue;
        }

        double score = 0;

        // Check common specialties
        std::set<std::string> target_specialties(target_person.getSpecialties().begin(), target_person.getSpecialties().end());
        std::set<std::string> person_specialties(person.getSpecialties().begin(), person.getSpecialties().end());
        std::vector<std::string> common_specialties;
        std::set_intersection(target_specialties.begin(), target_specialties.end(),
                              person_specialties.begin(), person_specialties.end(),
                              std::back_inserter(common_specialties));
        score += 5 * common_specialties.size();

        // Check university
        if (target_person.getUniversity() == person.getUniversity())
        {
            score += 3;
        }

        // Check major
        if (target_person.getMajor() == person.getMajor())
        {
            score += 2;
        }

        // Check job place
        if (target_person.getJobPlace() == person.getJobPlace())
        {
            score += 1;
        }

        // Check connection degree
        int degree = bsfShortestPath(person_id, id);
        if (degree != -1)
        {
            score += 1.0 / degree;
        }

        scores[id] = score;
        // This connection has been weighted
    }

    // Sort by score
    std::vector<std::pair<int, double>> sorted_scores(scores.begin(), scores.end());
    std::sort(sorted_scores.begin(), sorted_scores.end(), [](const std::pair<int, double> &a, const std::pair<int, double> &b)
              { return b.second < a.second; });

    // Get top 5 suggestions
    std::vector<int> suggestions;
    for (size_t i = 0; i < std::min(5, (int)sorted_scores.size()); i++)
    {
        suggestions.push_back(sorted_scores[i].first);
    }

    return suggestions;
}

void Graph::printRelatedPeople(int person_id)
{
    if (!people.count(person_id))
    {
        std::cout << "Person with ID " << person_id << " not found." << std::endl;
        return;
    }

    std::set<int> visited;
    std::queue<int> q;
    q.push(person_id);
    visited.insert(person_id);

    std::cout << "People related to the person with ID " << person_id << ":" << std::endl;

    for (int conn : adjacency_list[person_id])
    {
        Person person = people[conn];
        std::cout << "Person ID: " << person.getId() << ", Name: " << person.getName() << std::endl;
    }

    std::cout << std::endl;
}
