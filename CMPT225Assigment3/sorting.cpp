//
//  sorting.cpp
//  CMPT225Assigment3
//
//  Created by Kevin Zhang on 2016-02-16.
//  Copyright © 2016 Kevin Zhang. All rights reserved.
//

#include "sorting.hpp"
#include <iostream>
using namespace std;

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
            if (arr[i]>arr[j]) {
                Swap(arr, i, j);
            }
            count++;
        }
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
        QuicksortHelper(arr, pivotindex+1, high, counter);
    }
}

template <class T>
int QSPartition(T arr[], int low, int high, int& counter)
{
    int pivotindex = high;
    T temp;
    
    T pivot = arr[high];
    high--;
    
    
    while ( low <= high )
    {
        while( arr[low] <= pivot && low <= high )
        {
            low++;
            counter++;
        }
        while( arr[high] > pivot && low <= high )
        {
            high--;
            counter++;
        }
        if ( low < high )
        {
            //std::swap(arr[low], arr[high]);
            
            temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            
        }
    }
    //std::swap(arr[high + 1], arr[pivotindex]);
    //Swap pivot into place
    
    temp = arr[high + 1];
    arr[high + 1] = arr[pivotindex];
    arr[pivotindex] = temp;
    
    
    pivotindex = high + 1;
    return pivotindex;

//    int pivotindex = high;
//    while (true){
//        while (arr[low] < arr[pivotindex])
//        {
//            low++;
//            counter++;
//        }
//
//        while (arr[high] > arr[pivotindex])
//        {
//            high--;
//            counter++;
//
//        }
//        
//        if (low < high)
//        {
//            Swap(arr, high, low);
//            //counter++;
//        }
//        else
//        {
//            //counter++;
//            return high;
//            // Return pivot once high == low
//        }
//    }
//    T pivot = arr[high];
//    int pivotindex = low;
//    for (int j=pivotindex; j<=high-1; ++j) {
//        if (arr[j]<=pivot) {
//            Swap(arr, pivotindex, j);
//            pivotindex++;
//        }
//        counter++;
//    }
//    Swap(arr, pivotindex, high);
//    return pivotindex;
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
        RQuicksortHelper(arr, pivotindex+1, high, counter);
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
    if (low<high){
        int mid= low + (high-low)/2;
        MergesortHelper(arr, low, mid, n, counter);
        MergesortHelper(arr, mid+1, high, n, counter);
        Merge(arr, low, mid, high, n, counter);
    }
}

template <class T>
void Merge(T arr[], int low, int mid, int high, int n, int& counter)
{
    T* temp;
    temp = new T [n];
    for (int i=low; i<=high; ++i) {
        temp[i] = arr[i];
    }
    
    int i = low;
    int j = mid+1;
    int k = low;
    while (i<= mid && j<=high) {
        if (temp[i]<=temp[j]) {
            arr[k] =temp[i];
            ++i;
            counter++;
        }else{
            arr[k] =temp[j];
            ++j;
            counter++;
        }
        ++k;
    }
    while (i<=mid) {
        arr[k] = temp[i];
        ++k;
        ++i;
    }
    delete [] temp;
}

// Shell Sort
// (your comments here)
template <class T>
int ShellSort(T arr[], int n)
{
    int count = 0;
    
    for (int gap = n/2; gap>0; gap/=2) {
        for (int i=gap; i<n; ++i) {
            for (int j=i-gap; j>=0 && arr[j]>arr[j+gap]; j-=gap) {
                Swap(arr, j, j+gap);
                count++;
            }
        }
    }
    
    return count;
}

template <class T>
void Swap(T arr[], int i, int j)
{
    T temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
