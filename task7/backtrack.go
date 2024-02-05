package main

import (
	"fmt"
	"sort"
)

var count int = 0

func maxtominbin(arr []int, k int) {
	if k == len(arr) {
		count++
		fmt.Println(arr)
	} else {
		arr[k] = 1
		maxtominbin(arr, k+1)
		arr[k] = 2
		maxtominbin(arr, k+1)
	}
}

func perm(arr []int, k int) {
	if k == len(arr)-1 {
		count++
		fmt.Println(arr)
	} else {
		for i := k; i < len(arr); i++ {
			arr[k], arr[i] = arr[i], arr[k]
			perm(arr, k+1)
			arr[k], arr[i] = arr[i], arr[k]
		}
	}
}

func main() {
	fmt.Println("Start")
	var size = 3
	element := make([]int, size)
	element[0] = 1
	element[1] = 2
	element[2] = 3

	// Sort the array for lexicographic order
	sort.Ints(element)

	perm(element, 0)
	fmt.Println("run", count, "times")
}
