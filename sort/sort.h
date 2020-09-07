#ifndef sort_h
#define sort_h

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
typedef int ElementType;
typedef void (*FunType)(ElementType*,int);
void SelectionSort(int *a,int size);
void SelectionSort2(int *a,int size);
void BubbleSort(int *a,int size);
void BubbleSortswap(int *a,int size);
void InsertionSort(int*a,int size);
void ShellSort(int *a,int size);
void ShellSort2(int *a,int size);
void QuickSort(int *arr,int low,int high);
void MergeAdd(int arr[], int left, int mid, int right, int *temp);
void MergeSort(int arr[],int left,int right,int *temp);
//extern int N;
int* CreateArray(int N);
void PrintArray(ElementType A[],int N);
void Swap(int *a,int *b);
void Clock(FunType fp,ElementType A[],int N);
double ClockForAverage(FunType fp,ElementType A[],int N);
void Average(double T[],int N);
ElementType* Duplication(ElementType A[],int N);
void Bubble_Sort(ElementType A[],int N);
void Insertion_Sort(ElementType A[],int N);
void Shell_Sort(ElementType A[],int N);
void Heap_Sort(ElementType A[],int N);
void Merge_Recursive_Sort(ElementType A[],int N);
void Merge_NonRecursive_Sort(ElementType A[],int N);
void Quick_Sort(ElementType A[],int N);
#endif /* sort_h */
