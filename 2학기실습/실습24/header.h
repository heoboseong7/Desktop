#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// common functions
void gendata(int arr[], int n);
void printarr(int arr[], int n);
int gcd(int a, int b);
void swap(int arr[], int s, int t, int d);
void reverse(int arr[], int start, int end);
// left rotation functions d > 0
void ltrivial(int arr[], int d, int n);
void ljuggling(int arr[], int d, int n);
void lblock_swap(int arr[], int d, int n);
// right rotation functions d < 0
void rtrivial(int arr[], int d, int n);
void rjuggling(int arr[], int d, int n);
void rblock_swap(int arr[], int d, int n);