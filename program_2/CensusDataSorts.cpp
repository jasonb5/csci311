/**
 * @file CensusDataSorts.cpp   Sort functions for census population data.
 * 
 * @brief
 *    Implements several different types of sorts. Data can be sorted
 * by population or by name of town. This file contains all of the sorting
 * functions and their helpers.
 *
 * @author Judy Challinger
 * @date 2/22/13
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include "CensusData.h"

/**
 * Performs an insertion sort on data vector.
 *
 * @param type  Sorting criteria; Population or City
 */
void CensusData::insertionSort(int type) {
    for (unsigned int i = 1; i < data.size(); ++i) {
        Record* tmp = data[i];
        int j = i - 1;
    
        while (j >= 0 && isGreater(type, data[j], tmp)) {
            data[j+1] = data[j];
            
            --j;
        }

        data[j+1] = tmp;
    }
}

/**
 * Performs a merge sort on data vector.
 *
 * @param type  Sorting criteria; Population or City
 */
void CensusData::mergeSort(int type) {
    mergeSort(type, 1, data.size());
}

/**
 * Performs a quick sort on data vector.
 *
 * @param type  Sorting criteria; Population or City
 */
void CensusData::quickSort(int type) {
    quickSort(type, 0, data.size()-1);
}

/**
 * Finds the mid point of the current sub array. Calls mergeSort on 
 * left and right arrays and merges results.
 *
 * @param type  Sorting criteria; Population or City
 * @param min   Minimum index of sub array
 * @param max   Maximum index of sub array
 */
void CensusData::mergeSort(int type, int min, int max) {
    if (min < max) {
        int mid = floor((max + min) / 2);

        mergeSort(type, min, mid);
        mergeSort(type, mid+1, max);

        merge(type, min, mid, max);
    }
}

/**
 * Copies left and right sub arrays into vectors. Iterates
 * through all values in left and right vectors copying 
 * them back into data vector in order.
 *
 * @param type  Sorting criteria; Population or City
 * @param min   Minimum index of sub array
 * @param mid   Mid index of sub array
 * @param max   Maximum index of sub array
 */
void CensusData::merge(int type, int min, int mid, int max) {
    int n1, n2, i, j, k;
    vector<Record*> vecL, vecR;

    n1 = mid - min + 1;
    n2 = max - mid;

    for (i = 1; i <= n1; i++) {
        vecL.push_back(data[min+i-2]);
    }

    for (j = 1; j <= n2; j++) {
        vecR.push_back(data[mid+j-1]);
    }

    i = j = 0;

    for (k = min; k <= max; k++) {
        // checks for indices leaving array bounds then compares
        if (j >= (int)vecR.size() || 
            (i < (int)vecL.size() && 
            isGreater(type, vecR[j], vecL[i]))) {
            
            data[k-1] = vecL[i++];
        } else {
            data[k-1] = vecR[j++];
        }
    }
}

/**
 * Partitions the array then calls quick sort on each partition.
 * 
 * @param type  Sorting criteria; Population or City
 */
void CensusData::quickSort(int type, int min, int max) {
    int p;

    if (min < max) {
        p = partition(type, min, max);
    
        quickSort(type, min, p-1);
        quickSort(type, p+1, max);
    }
}

/**
 * Picks a pivot key, then orders keys less than and greater then
 * the pivot. Finished by swaping the pivot in between the partitions.
 *
 * @param type  Sorting criteria; Population or City
 * @param min   Minimum index of sub array
 * @param max   Maximym index of sub array
 * @return      New index of the pivot key
 */
int CensusData::partition(int type, int min, int max) {
    int i;
    Record* tmp;
    Record* pivot = data[max];

    i = min - 1;

    for (int j = min; j < max; j++) {
        if (isGreater(type, pivot, data[j])) {
            ++i;
            
            tmp = data[i];

            data[i] = data[j];

            data[j] = tmp;
        }
    }

    tmp = data[i+1];

    data[i+1] = data[max];

    data[max] = tmp;

    return i+1;
}

/**
 * Helper function, compares records based of off sorting criteria.
 *
 * @param type  Sorting criteria; Population or City
 * @param r1    Base Record
 * @param r2    Comparison Record
 * @return      True if r1 > r2 otherwise False
 */
bool CensusData::isGreater(int type, Record* r1, Record* r2) {
    if (type == CensusData::POPULATION) {
        return (r1->population > r2->population);
    } else if (type == CensusData::NAME) {
        if (r1->city->compare(*(r2->city)) > 0) {
            return true;
        } else {
            return false;
        }
    } else {    
        return false;
    }
}
