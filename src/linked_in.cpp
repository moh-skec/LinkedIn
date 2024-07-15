#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <network/person.cpp>
#include <network/graph.cpp>

// Load people from JSON file
std::vector<Person> load_people_from_json(const std::string &file_path)
{
    std::ifstream file(file_path);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file: " + file_path);
    }

    nlohmann::json v;
    file >> v;
    if (v.empty())
    {
        throw std::runtime_error("File is empty or invalid JSON format: " + file_path);
    }

    std::vector<Person> people;
    for (auto &i : v)
    {
        try
        {
            // Validate required fields
            if (!i.contains("ID") || !i.contains("Name") ||
                !i.contains("Year of Birth") || !i.contains("University") ||
                !i.contains("Major") || !i.contains("Job Place") ||
                !i.contains("Connections") || !i.contains("Specialties"))
            {
                throw std::runtime_error("Missing required field in JSON data.");
            }

            // Initialize person object
            Person person(
                i["ID"].get<int>(),
                i["Name"].get<std::string>(),
                i["Year of Birth"].get<int>(),
                i["University"].get<std::string>(),
                i["Major"].get<std::string>(),
                i["Job Place"].get<std::string>(),
                i["Connections"].get<std::vector<int>>(),
                i["Specialties"].get<std::vector<std::string>>());

            people.push_back(person);
        }
        catch (const nlohmann::json::exception &e)
        {
            std::cerr << "JSON parsing error: " << e.what() << " in person data: " << i << std::endl;
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << "Data error: " << e.what() << " in person data: " << i << std::endl;
        }
        // Person 'i' checked
    }

    return people;
}

int main()
{
    try
    {
        // Load JSON data
        std::string current_path = std::filesystem::current_path().string();
        current_path.erase(current_path.length() - 4, 4);
        for (size_t i = 0; i < current_path.size(); i++)
        {
            if (current_path[i] == '\\')
            {
                current_path[i] = '/';
            }
            // else: Same charater
        }

        std::string file_path = current_path + "/mnt/data/inputFile.json";
        std::vector<Person> v = load_people_from_json(file_path);

        // Initialize Graph
        Graph graph;

        // Add people to the graph
        for (auto &i : v)
        {
            graph.addPerson(i);
        }

        // Add connections to the graph
        for (auto &i : v)
        {
            std::vector<int> u = i.getConnections();
            for (auto j : u)
            {
                graph.addConnection(i.getId(), j);
            }
        }

        // Generate and print connection suggestions for a specific user
        std::cout << "Please enter an ID between 1 and " << v.size() << ":\n";

        int target_user_id;
        std::cin >> target_user_id;

        if (std::cin.fail())
        {
            std::cin.clear();                                                   // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter an integer." << std::endl;
        }
        else if (target_user_id < 1 && target_user_id > 30)
        {
            std::cout << "The number is not between 1 and " << v.size()<< ".\n";
        }

        std::vector<int> u = graph.suggestConnections(target_user_id);

        std::cout << "Suggestions for user " << target_user_id << ":\n";
        for (auto i : u)
        {
            std::cout << i << "\n";
        }

        // Print all related people for a specific user
        graph.printRelatedPeople(target_user_id);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
