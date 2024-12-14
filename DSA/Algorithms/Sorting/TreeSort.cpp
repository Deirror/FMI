void treeSort(std::vector<int>& v) {
    Bst<int> bst;
    for (int i = 0; i < v.size(); i++)
        bst.insert(v.at(i));

    unsigned index = 0;
    for (auto it = bst.begin(); it != bst.end(); it++)
        v.at(index++) = *it;
}
