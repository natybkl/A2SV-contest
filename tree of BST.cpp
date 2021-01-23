int height(node *root) {
    if (root == nullptr) return -1;

    return max(
        height(root -> left)  + 1,
        height(root -> right) + 1
    );

}

