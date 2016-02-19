//
//  sorting.cpp
//  CMPT225Assigment3
//
//  Created by Kevin Zhang on 2016-02-16.
//  Copyright © 2016 Kevin Zhang. All rights reserved.
//

#include "sorting.hpp"
#include <iostream>

// File:        sorting.cpp
// Author:      Geoffrey Tien
//              (your name)
// Date:        2016-02-08
// Description: Skeleton file for CMPT 225 assignment #3 sorting functions and helpers
//              Function bodies to be completed by you!

// Complete your sorting algorithm function implementations here
template <class T>
void Swap(T arr[], int i, int j);

// Selection Sort
// (your comments here)
template <class T>
int SelectionSort(T arr[], int n)
{
    int count = 0; // counter for barometer operations
    for (int i=0; i<n; ++i) {
        for (int j =i+1; j<n; ++j) {
            count++;
            if (arr[i]>arr[j]) {
                Swap(arr, i, j);
            }
            count++;
        }
        count++;
    }
    return count;
}

// Quicksort
// (your comments here)
template <class T>
int Quicksort(T arr[], int n)
{
    int count = 0;
    int low = 0;
    int high = n-1;
    QuicksortHelper(arr, low, high, count);
    return count;
}

template <class T>
void QuicksortHelper(T arr[], int low, int high, int& counter)
{
    if (low < high) {
        int pivotindex = QSPartition(arr, low, high, counter);
        QuicksortHelper(arr, low, pivotindex-1, counter);
        counter++;
        QuicksortHelper(arr, pivotindex+1, high, counter);
        counter++;
    }
}

template <class T>
int QSPartition(T arr[], int low, int high, int& counter)
{
    T pivot = arr[high];
    int pivotindex = low;
    for (int j=pivotindex; j<=high-1; ++j) {
        if (arr[j]<=pivot) {
            Swap(arr, pivotindex, j);
            pivotindex++;
        }
        counter++;
    }
    Swap(arr, pivotindex, high);
    return pivotindex;
}

// Randomized Quicksort
// (your comments here)
template <class T>
int RQuicksort(T arr[], int n)
{
    int count = 0;
    int low = 0;
    int high = n-1;
    RQuicksortHelper(arr, low, high, count);
    return count;
}

template <class T>
void RQuicksortHelper(T arr[], int low, int high, int& counter)
{
    if (low<high) {
        int pivotindex = RQSPartition(arr, low, high, counter);
        RQuicksortHelper(arr, low, pivotindex-1, counter);
        counter++;
        RQuicksortHelper(arr, pivotindex+1, high, counter);
        counter++;
    }
}

template <class T>
int RQSPartition(T arr[], int low, int high, int& counter)
{
    int pivotindex = low + rand()%(high-low+1);
    Swap(arr, high, pivotindex);
    return QSPartition(arr, low, high, counter);
}

// Mergesort
// (your comments here)
template <class T>
int Mergesort(T arr[], int n)
{
    int count = 0;
    int low = 0;
    int high = n-1;
    MergesortHelper(arr, low, high, n, count);
    return count;
}

template <class T>
void MergesortHelper(T arr[], int low, int high, int n, int& counter)
{
    
}

template <class T>
void Merge(T arr[], int low, int mid, int high, int n, int& counter)
{
    
}

// Shell Sort
// (your comments here)
template <class T>
int ShellSort(T arr[], int n)
{
    int count = 0;
    
    return count;
}

template <class T>
void Swap(T arr[], int i, int j)
{
    T temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
