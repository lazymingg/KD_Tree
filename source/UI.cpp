#include "../include/UI.h"

void showMenu()
{
    // Just the menu of the CLI
    cout << "-----------------------------MENU-----------------------------" << endl;
    cout << "1: Load the list of cities from a CSV file" << endl;
    cout << "2: Insert a new city into the KD-Tree" << endl;
    cout << "3: Insert multiple new cities into the KD-Tree from a CSV file" << endl;
    cout << "4: Nearest neighbor search with set of latitude and longitude coordinates" << endl;
    cout << "5: Query all cities within a rectanglar region defined by its geographical boundaries" << endl;
    cout << "6: Serialize the current KD Tree to a binary file" << endl;
    cout << "7: Load a KD Tree from a binary file (Warnings: All contents of the current tree will be lost)" << endl;
    cout << "0: Exit" << endl;
    cout << endl;
}

int handleMode()
{
    // Function used get the mode's number, ensuring that a number will be return
    cout << "Please enter a mode: ";
    string modeLine;
    getline(cin, modeLine);

    stringstream ss(modeLine);
    string mode;
    getline(ss, mode, ' ');

    int res;
    if (mode != "" && mode[0] >= '0' && mode[0] <= '9')
    {
        res = stoi(mode);
    }
    else{
        res = -1;
    }
    return res;
}

int handleOutputMode()
{   
    // Getting the output mode, depending on the user answer
    // 0 = Display none, 1 = Display to console ONLY, 2 = Write to CSV file ONLY, 3 = Display to console and write to CSV
    int mode = 0;
    string ans1;
    cout << "Do you want to output results to the console? (Y/N)" << endl;
    while (true)
    {
        // Ensuring a correct answer has to be input to continue
        cout << "Your answer: ";
        getline(cin, ans1);
        if (ans1 == "Y" || ans1 == "y")
        {
            mode += 1;
            break;
        }
        else if (ans1 == "N" || ans1 == "n")
        {
            break;
        }
        cout << "Invalid answer!!!" << endl;
    }

    string ans2;
    cout << "Do you want to output results to a CSV file? (Y/N)" << endl;
    while (true)
    {
        // Ensuring a correct answer has to be input to continue
        cout << "Your answer: ";
        getline(cin, ans2);
        if (ans2 == "Y" || ans2 == "y")
        {
            mode += 2;
            break;
        }
        else if (ans2 == "N" || ans2 == "n")
        {
            break;
        }
        cout << "Invalid answer!!!" << endl;
    }
    return mode;
}

void interfaceMenu(KD_tree &Tree, int mode)
{   
    // Getting the mode number and switch to the corresponding function for that mode
    vector<City> cityList;

    // All the mode depending on the mode variable
    switch (mode)
    {
        case 1:
            cityList = modeLoadCity();
            cout << "Loaded total of " << cityList.size() << " cities" << endl;
            break;
    
        case 2:
            modeInsertNewCity(Tree);
            break;

        case 3:
            modeInsertMultiNewCity(Tree);
            break;

        case 4:
            modeNearestNeighborSearch(Tree);
            break;

        case 5:
            modeRangeSearch(Tree);
            break;

        case 6:
            modeSerialize(Tree);
            break;

        case 7:
            modeDeserialize(Tree);
            break;
    }
}

vector<City> modeLoadCity()
{
    // Mode 1: Load city from a CSV file

    string filePath;

    cout << "Input the absolute filepath: ";
    getline(cin, filePath);

    return readFile(filePath);
}

bool handleStringToDouble(string s, double &val)
{
    // Ensuring the input string has to be a number that can be turned into datatype double
    if (s == "" || ((s[0] < '0' || s[0] > '9') && s[0] != '-'))
    {
        cout << "Please enter a valid number!" << endl;
        return false;
    }

    int lenS = s.length();
    if (s[0] == '-' && (lenS == 1 || s[1] < '0' || s[1] > '9'))
    {
        cout << "Please enter a valid number!" << endl;
        return false;
    }

    size_t pos;
    val = stod(s, &pos);
    
    if (pos < lenS)
    {
        cout << "Please enter a valid number!" << endl;
        return false;
    }

    return true;
}

bool handleStringToInt(string s, int &val)
{
    // Ensuring the input string has to be a number that can be turned into datatype int
    if (s == "" || s[0] < '0' || s[0] > '9')
    {
        cout << "Please enter a valid number!" << endl;
        return false;
    }
    
    size_t pos;
    val = stoi(s, &pos);
    
    if (pos < s.length())
    {
        cout << "Please enter a valid number!" << endl;
        return false;
    }

    return true;
}

void modeInsertNewCity(KD_tree &Tree)
{
    // Mode 2: Insert a new city
    City getCity;

    cout << "Insert the city name: ";
    getline(cin, getCity.cityName);

    while (true)
    {
        // Ensuring a correct lattitude will be inputted
        cout << "Insert the latitude of the city: ";
        string latitude;
        getline(cin, latitude);
        if (handleStringToDouble(latitude, getCity.location.latitude))
        {
            if (getCity.location.latitude > 90 || getCity.location.latitude < -90)
            {
                cout << "Please enter a valid number! (-90 <= x <= 90)" << endl;
                continue;
            }
            break;
        }
    }

    while (true)
    {
        // Ensuring a correct longitude will be inputted
        cout << "Insert the longitude of the city: ";
        string longitude;
        getline(cin, longitude);
        if (handleStringToDouble(longitude, getCity.location.longitude))
        {
            if (getCity.location.longitude > 180 || getCity.location.longitude < -180)
            {
                cout << "Please enter a valid number! (-180 <= x <= 180)" << endl;
                continue;
            }
            break;
        }
    }

    if (insert(Tree.root, getCity, START_DEPTH))
    {
        cout << "City \"" << getCity.cityName << "\" has been inserted" << endl;
    }
}

void modeInsertMultiNewCity(KD_tree &Tree)
{
    // Mode 3: Inserting multiple cities from a CSV file
    vector<City> cityList = modeLoadCity();

    int listSize = cityList.size();
    int cnt = 0;

    for (int i = 0; i < listSize; i++)
    {
        if (insert(Tree.root, cityList[i], START_DEPTH))
        {
            cnt++;
        }
    }
    cout << "Inserted total of " << cnt << " cities" << endl;
}

void modeNearestNeighborSearch(KD_tree &Tree)
{
    // Mode 4: Getting the nearest neighbor
    int numPoint;
    while (true)
    {
        // Ensuring a correct number will be inputted
        cout << "Insert the number of coordinates needed to find the nearest neighbor: ";
        string numPointS;
        getline(cin, numPointS);
        if (handleStringToInt(numPointS, numPoint))
        {
            break;
        }
    }   

    int outputMode = handleOutputMode();
    fstream fs;
    string filePath;

    if (outputMode == 2 || outputMode == 3)
    {
        // Opening CSV file to input depend on mode
        cout << "Input the absolute filepath: ";
        getline(cin, filePath);
        fs.open(filePath, ios::out);
        if (!fs.is_open())
        {
            cout << "Cannot open file!" << endl;
            return;
        }
        fs << "PointLatitude,PointLongitude,NearestCityName,CityLatitude,CityLongitude" << endl;
        fs.close();
    }

    Point2D pointHandle;

    for (int i = 0; i < numPoint; i++)
    {
        while (true)
        {
            cout << "Insert the latitude of the coordinate: ";
            string latitude;
            getline(cin, latitude);
            if (handleStringToDouble(latitude, pointHandle.latitude))
            {
                if (pointHandle.latitude > 90 || pointHandle.latitude < -90)
                {
                    cout << "Please enter a valid number! (-90 <= x <= 90)" << endl;
                    continue;
                }
                break;
            }
        }

        while (true)
        {
            cout << "Insert the longitude of the coordinate: ";
            string longitude;
            getline(cin, longitude);
            if (handleStringToDouble(longitude, pointHandle.longitude))
            {
                if (pointHandle.longitude > 180 || pointHandle.longitude < -180)
                {
                    cout << "Please enter a valid number! (-180 <= x <= 180)" << endl;
                    continue;
                }
                break;
            }
        }

        Node* neareastCity = searchNearestNeighbor(Tree.root, pointHandle);
        cout << endl;
        if (outputMode == 1)
        {
            cout << "The nearest city is: " << neareastCity->data.cityName << endl;
            cout << "Latitude: " << neareastCity->data.location.latitude <<" " << "Longitude: " << neareastCity->data.location.longitude << "\n\n"; 
        }
        else if (outputMode == 2)
        {
            fs.open(filePath, ios::app);
            fs << pointHandle.latitude << "," << pointHandle.longitude << "," << neareastCity->data.cityName << "," << neareastCity->data.location.latitude << ",";
            fs << neareastCity->data.location.longitude << endl;
        }
        else if (outputMode == 3)
        {
            cout << "The nearest city is: " << neareastCity->data.cityName << endl;
            cout << "Latitude: " << neareastCity->data.location.latitude <<" " << "Longitude: " << neareastCity->data.location.longitude << endl; 
            fs.open(filePath, ios::app);
            fs << pointHandle.latitude << "," << pointHandle.longitude << "," << neareastCity->data.cityName << "," << neareastCity->data.location.latitude << ",";
            fs << neareastCity->data.location.longitude << endl;
        }
    }
}

void outputRangeSearchConsole(vector<Node*> res, int resSize)
{
    // Output console for Range search
    cout << endl << "All cities within the boundaries are: " << endl;

    for (int i = 0; i < resSize; i++)
    {
        cout << i + 1 << ". City name: " << res[i]->data.cityName << endl;
        cout << "Latitude: " << res[i]->data.location.latitude << " " << "Longitude: " << res[i]->data.location.longitude << endl;
    }
}

void outputRangeSearchCSV(vector<Node*> res, int resSize)
{
    // Output CSV file for Range search
    string filePath;

    cout << "Input the absolute filepath: ";
    getline(cin, filePath);
    
    fstream fs;
    fs.open(filePath, ios::out);
    if (!fs.is_open())
    {
        cout << "Cannot open file!" << endl;
        return;
    }
    fs << "City,Latitude,Longitude" << endl;
    for (int i = 0; i < resSize; i++)
    {
        fs << res[i]->data.cityName << "," << res[i]->data.location.latitude << "," << res[i]->data.location.longitude << endl;
    }
    fs.close();
}

void modeRangeSearch(KD_tree &Tree)
{
    // Mode 5: Getting all the city within a rectangular area
    Point2D bottom_left;
    Point2D top_right;

    while (true)
    {
        // Ensuring a correct latitude will be inputted
        cout << "Insert the latitude of the bottom left coordinate of the rectangle: ";
        string latitude;
        getline(cin, latitude);
        if (handleStringToDouble(latitude, bottom_left.latitude))
        {
            if (bottom_left.latitude > 90 || bottom_left.latitude < -90)
            {
                cout << "Please enter a valid number! (-90 <= x <= 90)" << endl;
                continue;
            }
            break;
        }
    }

    while (true)
    {
        // Ensuring a correct longitude will be inputted
        cout << "Insert the longitude of the bottom left coordinate of the rectangle: ";
        string longitude;
        getline(cin, longitude);
        if (handleStringToDouble(longitude, bottom_left.longitude))
        {
            if (bottom_left.longitude > 180 || bottom_left.longitude < -180)
            {
                cout << "Please enter a valid number! (-180 <= x <= 180)" << endl;
                continue;
            }
            break;
        }
    }

    while (true)
    {
        // Ensuring a correct latitude will be inputted
        cout << "Insert the latitude of the top right coordinate of the rectangle: ";
        string latitude;
        getline(cin, latitude);
        if (handleStringToDouble(latitude, top_right.latitude))
        {
            if (top_right.latitude > 90 || top_right.latitude < -90)
            {
                cout << "Please enter a valid number! (-90 <= x <= 90)" << endl;
                continue;
            }
            break;
        }
    }

    while (true)
    {
        // Ensuring a correct longitude will be inputted
        cout << "Insert the longitude of the top right coordinate of the rectangle: ";
        string longitude;
        getline(cin, longitude);
        if (handleStringToDouble(longitude, top_right.longitude))
        {
            if (top_right.longitude > 180 || top_right.longitude < -180)
            {
                cout << "Please enter a valid number! (-180 <= x <= 180)" << endl;
                continue;
            }
            break;
        }
    }

    vector<Node*> res = searchRange(Tree.root, bottom_left, top_right);
    int resSize = res.size();

    int outputMode = handleOutputMode();
    // 0 = None, 1 = only console, 2 = only CSV, 3 = both
    
    // Switching output mode
    if (outputMode == 1)
    {
        outputRangeSearchConsole(res, resSize);
    }
    else if (outputMode == 2)
    {
        outputRangeSearchCSV(res, resSize);
    }
    else if (outputMode == 3)
    {
        outputRangeSearchCSV(res, resSize);
        outputRangeSearchConsole(res, resSize);
    }
}

void modeSerialize(KD_tree &Tree)
{
    // Mode 6: Serialize the current KD tree
    string filePath;

    cout << "Input the absolute filepath: ";
    getline(cin, filePath);
    serializeKDTree(filePath, Tree.root);
}

void modeDeserialize(KD_tree &Tree)
{
    // Mode 7: Deserialize a KD tree from a binary file
    string filePath;

    cout << "Input the absolute filepath: ";
    getline(cin, filePath);
    deleteTree(Tree.root);
    Tree = deserializeKDTree(filePath);
}