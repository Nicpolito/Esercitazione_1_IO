#include <iostream>
#include <fstream>
#include <vector>

// Funzione per mappare i valori nel range [-1, 2]
double mapValue(double value) {
    // Mappatura dei valori nel range [-1, 2]
    return -1 + (value - 1) * (2 - (-1)) / (5 - 1);
}

int main() {
    // Apertura del file di input
    std::ifstream inputFile("data.csv");
    if (!inputFile) {
        std::cerr << "Impossibile aprire data.csv" << std::endl;
        return 1;
    }

    // Apertura del file di output
    std::ofstream outputFile("result.csv");
    if (!outputFile) {
        std::cerr << "Impossibile creare result.csv" << std::endl;
        return 1;
    }

    // Lettura dei valori dal file di input e mappatura
    double value;
    std::vector<double> mappedValues;
    while (inputFile >> value) {
        double mappedValue = mapValue(value);
        mappedValues.push_back(mappedValue);
    }

    // Calcolo della media cumulativa dei valori mappati
    double cumSum = 0;
    for (size_t i = 0; i < mappedValues.size(); ++i) {
        cumSum += mappedValues[i];
        double mean = cumSum / (i + 1);
        // Scrittura dei risultati nel file di output
        outputFile << mean << std::endl;
    }

    // Chiusura dei file
    inputFile.close();
    outputFile.close();

    std::cout << "Risultato scritto in result.csv" << std::endl;

    return 0;
}
