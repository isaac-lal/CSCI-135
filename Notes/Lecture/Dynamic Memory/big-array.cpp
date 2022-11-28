int main() {
    int n = 4;
    double* account_array = new double[n];
    for (int i = 0; i < n; i++)
    {
        account_array[i] = i*4;
    }
    //n = size of the original array
    double* bigger_array = new double[2 * n];
    for (int i = 0; i < n; i++)
    {
        bigger_array[i] = account_array[i];
    }
    delete[] account_array;
    account_array = bigger_array;
    bigger_array = nullptr;
    n = 2 * n;
}