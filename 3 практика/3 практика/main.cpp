#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

template <class Type>
using Vector = std::vector<Type>;
template <class Type>
using Matrix = std::vector<std::vector<Type>>;

template <class Type>
void read_matrix(std::istream& input, size_t n, Matrix<Type>& matrix) {
    matrix.resize(n, Vector<Type>(n));

    for (auto& row : matrix)
        for (auto& item : row) input >> item;
    return;
}

template <class Type>
Matrix<Type> matrix_sum(const Matrix<Type>& lhs, const Matrix<Type>& rhs) {
    size_t n = lhs.size();
    Matrix<Type> result(n, Vector<Type>(n));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            result[i][j] = lhs[i][j] + rhs[i][j];
        }
    }
    return result;
}

template <class Type>
Matrix<Type> matrix_multiply(const Matrix<Type>& lhs, const Matrix<Type>& rhs) {
    size_t n = lhs.size();
    Matrix<Type> result(n, Vector<Type>(n));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            for (size_t k = 0; k < n; ++k) {
                result[i][j] += lhs[i][k] * rhs[k][j];
            }
        }
    }
    return result;
}

std::pair<size_t, size_t> matrix_get_max_absolute(
    const Matrix<double>& matrix) {
    double max = 0;
    std::pair<size_t, size_t> result{ 0, 0 };
    size_t n = matrix.size();

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            if (fabs(matrix[i][j]) > max) {
                max = matrix[i][j];
                result = { i, j };
            }

    return result;
}

template <class Type>
void matrix_remove_row_col(Matrix<Type>& matrix, size_t row, size_t col) {
    size_t n = matrix.size();

    for (size_t i = 0; i < n; ++i) {
        matrix[i].erase(col + matrix[i].begin());
    }
    matrix.erase(row + matrix.begin());
}

template <class Type>
void print_matrix(std::ostream& output, const Matrix<Type>& matrix) {
    for (auto& row : matrix) {
        for (auto& item : row) output << item << ' ';
        output << '\n';
    }
    output.flush();
}

int key(int argc, char* argv[], const char* key) {
    for (int i = 0; i < argc; ++i)
        if (!strcmp(argv[i], key))
            return i;
    return 0;
}

int main(int argc, char* argv[]) {
    if (key(argc, argv, "-h")) {
        std::cerr << "Usage: " << argv[0] << " [-i <input_file>] [-o <output_file>]" << std::endl;
        std::exit(1);
    }

    size_t n;
    Matrix<double> a, b, c;

    std::istream* input;
    int k;
    if (k = key(argc, argv, "-i")) {
        std::cout << "input from file" << std::endl;
        input = new std::ifstream(argv[k + 1]);
    }
    else {
        input = &std::cin;
    }

    if (input == &std::cin)
        std::cout << "Enter n:" << std::endl;
    *input >> n;
    if (input == &std::cin)
        std::cout << "Enter A:" << std::endl;
    read_matrix(*input, n, a);
    if (input == &std::cin)
        std::cout << "Enter B:" << std::endl;
    read_matrix(*input, n, b);
    if(input == &std::cin)
        std::cout << "Enter C:" << std::endl;
    read_matrix(*input, n, c);

    if (input != &std::cin) {
        delete input;
    }

    Matrix<double> d = matrix_multiply(matrix_sum(a, b), c);

    std::ostream *output;
    if (k = key(argc, argv, "-o")) {
        std::cout << "output to file" << std::endl;
        output = new std::ofstream(argv[k + 1]);
    }
    else {
        output = &std::cout;
    }

    if (output == &std::cout)
        *output << "D:\n";
    print_matrix(*output, d);
    auto [i, j] = matrix_get_max_absolute(d);

    matrix_remove_row_col(d, i, j);
    if (output == &std::cout)
        *output << "D after removal:\n";
    print_matrix(*output, d);

    if (output != &std::cout) {
        delete output;
    }
    return 0;
}

