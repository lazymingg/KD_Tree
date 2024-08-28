#include "../include/Serialize.h"

void serializeKDTree(string filePath, Node* root)
{
    fstream fs;
    fs.open(filePath, ios::binary | ios::out);
    if (!fs.is_open())
    {
        cout << "Cannot open file!" << endl;
        return;
    }
    serializeKDTreeNode(fs, root);
    fs.close();
}

void serializeKDTreeNode(fstream &fs, Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    
    int cityNameLen = node->data.cityName.length();
    // Writing node's data
    fs.write((char*)(&cityNameLen), sizeof(int));
    fs.write(node->data.cityName.c_str(), cityNameLen);
    fs.write((char*)(&node->data.location), sizeof(Point2D));

    // Placeholder for left and right child positions
    // -1 is for NULL at left or right node

    // Getting leftPos to add data later if existed
    streampos leftPos = fs.tellp();
    streamoff leftOffset = -1;
    fs.write((char*)(&leftOffset), sizeof(leftOffset));

    // Getting rightPos to add data later if existed
    streampos rightPos = fs.tellp();
    streamoff rightOffset = -1;
    fs.write((char*)(&rightOffset), sizeof(rightOffset));

    streamoff currentPos = fs.tellp();
    if (node->left)
    {
        fs.seekp(leftPos);
        leftOffset = currentPos;
        // Changing value to notice there exist a left node
        fs.write((char*)(&leftOffset), sizeof(leftOffset));
        fs.seekp(currentPos);
        serializeKDTreeNode(fs, node->left);
        currentPos = fs.tellp();
    }

    if (node->right) {
        fs.seekp(rightPos);
        rightOffset = currentPos;
        // Changing value to notice there exist a right node
        fs.write((char*)(&rightOffset), sizeof(rightOffset));
        fs.seekp(currentPos);
        serializeKDTreeNode(fs, node->right);
    }
}

Node* deserializeKDTreeNode(fstream &fs)
{
    if (fs.eof())
    {
        return nullptr;
    }

    int cityNameLen;
    // Reading city's name length
    fs.read((char*)(&cityNameLen), sizeof(int));
    
    // Reading city's name
    string cityName(cityNameLen, '\0');
    fs.read(&cityName[0], cityNameLen);

    Point2D location;
    fs.read((char*)(&location), sizeof(Point2D));

    // Getting notice of the existence of a left node or right node, -1 is for NULL
    streamoff leftOffset, rightOffset;
    fs.read((char*)(&leftOffset), sizeof(leftOffset));
    fs.read((char*)(&rightOffset), sizeof(rightOffset));
    Node* node = createNode({cityName, location});

    // Deserialize the left child
    if (leftOffset != -1) {
        streampos currentPos = fs.tellg();
        fs.seekg(leftOffset);
        node->left = deserializeKDTreeNode(fs);
        fs.seekg(currentPos);
    }

    // Deserialize the right child
    if (rightOffset != -1) {
        streampos currentPos = fs.tellg();
        fs.seekg(rightOffset);
        node->right = deserializeKDTreeNode(fs);
        fs.seekg(currentPos);
    }

    return node;
}

KD_tree deserializeKDTree(string filePath)
{
    KD_tree Tree;
    fstream fs;
    fs.open(filePath, ios::binary | ios::in);
    if (!fs.is_open())
    {
        cout << "Cannot open file!" << endl;
        return Tree;
    }
    Tree.root = deserializeKDTreeNode(fs);
    fs.close();
    return Tree;
}