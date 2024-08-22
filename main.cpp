#include "include/KD_tree.h"

int main()
{
    KD_tree tree;
    tree.insert(City("New York", 40.7128, -74.0060));
    tree.insert(City("Los Angeles", 34.0522, -118.2437));
    tree.insert(City("Chicago", 41.8781, -87.6298));
    tree.insert(City("Houston", 29.7604, -95.3698));
    tree.insert(City("Phoenix", 33.4484, -112.0740));
    tree.insert(City("Philadelphia", 39.9526, -75.1652));
    tree.insert(City("San Antonio", 29.4241, -98.4936));
    tree.insert(City("San Diego", 32.7157, -117.1611));
    tree.insert(City("Dallas", 32.7767, -96.7970));
    tree.insert(City("San Jose", 37.3382, -121.8863));
    tree.insert(City("Austin", 30.2672, -97.7431));
    tree.insert(City("Jacksonville", 30.3322, -81.6557));
    tree.insert(City("San Francisco", 37.7749, -122.4194));
    tree.insert(City("Indianapolis", 39.7684, -86.1581));
    tree.insert(City("Columbus", 39.9612, -82.9988));
    tree.insert(City("Fort Worth", 32.7555, -97.3308));
    tree.insert(City("Charlotte", 35.2271, -80.8431));
    tree.insert(City("Seattle", 47.6062, -122.3321));
    tree.insert(City("Denver", 39.7392, -104.9903));
    tree.insert(City("Washington", 38.9072, -77.0369));
    tree.insert(City("Boston", 42.3601, -71.0589));
    tree.insert(City("El Paso", 31.7619, -106.4850));
    tree.insert(City("Detroit", 42.3314, -83.0458));
    tree.insert(City("Nashville", 36.1627, -86.7816));
    tree.preOrder();
}