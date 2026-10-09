/*
 * sorter.h
 *
 * Declares a template function:
 *    
 *   sorter() : k-way merge sort.
 * 
 * 
 * You may add other functions if you wish, but this template function
 * is the only one that need to be exposed for the testing code.
 * 
 * Authors: C. Painter-Wakefield & Tolga Can
 * Edited by: Bradley Wasniak
 */

#ifndef _SORTER_H
#define _SORTER_H

#include <string>
#include <cstddef>
#include <vector>

/***
 * DO NOT put unscoped 'using namespace std;' in header files!
 * Instead put them at the beginning of class or function definitions
 * (as demonstrated below).
 *
 * For more details, see the commentary at the top of
 *   tests/header-sans-using-namespace.h
 * in this project repo.
 */

template <class T>
void sorter(std::vector<T> &item, std::size_t k) {  
	using namespace std;
	// write your solution for k-way merge sort below	
    if (item.size() <= 1) {
        return;
        
    }

    if (k <= 1) {
        for (size_t i = 1; i < item.size(); i++) {
            T value = item[i];
            size_t j = i;

            while (j > 0 && value < item[j - 1]) {
                item[j] = item[j - 1];
                j--;
            }


            item[j] = value;
        }
        return;
}

    vector<vector<T>> parts(k);

    size_t split = item.size() / k;
    size_t add = item.size() % k;
    size_t begin = 0;

    for (size_t i = 0; i < k; i++) {
        size_t size = split;

        if (i < add) {
            size++;
        }

        for (size_t j = 0; j < size; j++) {
            parts[i].push_back(item[begin + j]);
        }

        begin += size;
    }

    for (size_t i = 0; i < k; i++) {
        
        sorter(parts[i], k);
    }

    vector<size_t> index(k, 0);

    vector<T> final;

    while (final.size() < item.size()) {
        size_t small = k;

        for (size_t i = 0; i < k; i++) {
            if (index[i] < parts[i].size()) {
                if (small == k ||
                    parts[i][index[i]] < parts[small][index[small]]) {
                    small = i;

                }
            }  
        }

        if (small == k) {
            break;
        }

        final.push_back(parts[small][index[small]]);
        index[small]++;
    }


    item = final;
}
#endif
