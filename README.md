# Linked In

This project implements a social network to connect people based on their skills, similar to platforms like LinkedIn. The program suggests connections for users based on common specialties, university, major, job place, and the degree of connection.

## Features

- **Graph Data Structure**: Represents the social network.
- **Person Class**: Encapsulates user details and their connections.
- **Graph Operations**: Includes adding persons, adding connections, suggesting connections, and printing related people.

## Project Structure

The project is organized into multiple files:

- `include/person.h`: Header file for the `Person` class.
- `include/person.cpp`: Implementation file for the `Person` class.
- `include/graph.h`: Header file for the `Graph` class.
- `include/graph.cpp`: Implementation file for the `Graph` class.
- `src/linked_in.cpp`: Main application logic.

## Requirements

- **C++ Compiler**: Ensure you have a C++ compiler installed.
- **JSON Library**: The project uses the `nlohmann/json` library for JSON parsing. Ensure it is installed and available.

## Setup and Usage

1. **Clone the Repository**:

   ```sh
   git clone https://github.com/moh-skec/LinkedIn.git
   cd LinkedIn
