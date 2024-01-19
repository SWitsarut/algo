package main

import "fmt"

func findU(arr []int) int {
	size := len(arr)
	if size != 1 {
		m := size / 2
		l := findU(arr[:m])
		r := findU(arr[m:])
		var max int
		if l > r {
			max = l
		} else {
			max = r
		}
		return max
	} else {
		return arr[0]
	}
}

func findL(arr []int) int {
	size := len(arr)
	if size != 1 {
		m := size / 2
		l := findL(arr[:m])
		r := findL(arr[m:])
		var min int
		if l < r {
			min = l
		} else {
			min = r
		}
		return min
	} else {
		return arr[0]
	}
}

func main() {
	var A = []int{16, 25, 2, 54, 36, 9, 12, 66}
	u := findU(A)
	l := findL(A)
	size := u - l + 1
	fmt.Println("l\t", l, "\nu\t", u)
	D := make([]int, size)
	fmt.Println("D size:\t", len(D))
	// fmt.Println(D)
	for i := 0; i < len(A); i++ {
		D[A[i]-l]++
	}
	fmt.Println(D)
	for i := 1; i < u-1; i++ {
		D[i] = D[i-1] + D[i]
	}
	fmt.Println(D)
	S := make([]int, len(A))
	for i := len(A) - 1; i >= 0; i-- {
		j := A[i] - l
		S[D[j]-1] = A[i]
		D[j]--
	}
		
	fmt.Println(S)
}
