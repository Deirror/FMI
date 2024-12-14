
void generateBinaryNumbers(size_t n) {
    queue<std::string> q;
    q.push("1");
    while(n--) {
        string currentNumber = q.front();
        q.pop();
        cout << currentNumber << " ";
        q.push(currentNumber + "0");
        q.push(currentNumber + "1");
    }
}
