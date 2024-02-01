package main

import "fmt"

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
	if k == len(arr) {
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
	var size = 5
	// fmt.Scan(&size)
	// bin := make([]int, size)
	kid := make([]int, size)
	kid[0] = 1
	kid[1] = 2
	kid[2] = 3
	perm(kid, 0)
	fmt.Println("run", count, "times")
}
